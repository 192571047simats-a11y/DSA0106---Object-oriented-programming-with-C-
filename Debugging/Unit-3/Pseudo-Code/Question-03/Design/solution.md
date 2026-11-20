# Currency normalization, stream I/O and unary minus

## Design overview
Convert the dollar/cents pair into a single signed integer number of cents for normalization. Split it back into dollars and a non-negative cents remainder. Unary negation changes the sign of the total amount.

## Structured pseudo-code
```text
CLASS Currency
PRIVATE:
    totalCents : INTEGER
PUBLIC:
    CONSTRUCTOR(d : INTEGER = 0, c : INTEGER = 0)
        totalCents <- d * 100 + c
    END
    METHOD GetDollars() RETURNS INTEGER
        RETURN TRUNCATE(totalCents / 100)
    END
    METHOD GetCents() RETURNS INTEGER
        RETURN ABS(totalCents MOD 100)
    END
    OPERATOR -() RETURNS Currency
        RETURN CurrencyFromTotal(-totalCents)
    END
    FRIEND OPERATOR <<(outStream, cur)
        PRINT "$", cur.GetDollars(), ".", TWO_DIGIT(cur.GetCents())
    END
    FRIEND OPERATOR >>(inStream, REF cur)
        READ d, c
        cur <- Currency(d,c)
    END
ENDCLASS
BEGIN
    cur <- Currency(5,275)
    DISPLAY cur
    debt <- -cur
    DISPLAY debt
END
```

## Dry-run trace
Input: dollars = 5, cents = 275.
Total cents = 5×100 + 275 = 775.
Normalized amount = **$7.75**.
Unary negation = **-$7.75** (represented internally as -775 cents).

