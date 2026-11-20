# Polynomial dynamic array, subscript and addition

## Design overview
The polynomial stores coefficients from power zero upward in a dynamically allocated array. Index access checks bounds and returns a reference. Addition creates a result with the larger degree and treats missing coefficients as zero.

## Structured pseudo-code
```text
CLASS Polynomial
PRIVATE:
    degree : INTEGER
    coeffArray : POINTER TO REAL
PUBLIC:
    CONSTRUCTOR(deg)
        degree <- deg
        ALLOCATE coeffArray[degree + 1]
        FOR i <- 0 TO degree
            coeffArray[i] <- 0.0
        ENDFOR
    END
    COPY CONSTRUCTOR(REF other)
        degree <- other.degree
        ALLOCATE coeffArray[degree + 1]
        COPY every coefficient from other
    END
    DESTRUCTOR() DEALLOCATE coeffArray END
    OPERATOR [](index) RETURNS REF REAL
        IF index < 0 OR index > degree THEN
            THROW IndexOutOfRangeException
        ENDIF
        RETURN REF coeffArray[index]
    END
    OPERATOR +(REF rhs) RETURNS Polynomial
        resultDegree <- MAX(degree, rhs.degree)
        result <- Polynomial(resultDegree)
        FOR i <- 0 TO resultDegree
            leftValue <- 0; rightValue <- 0
            IF i <= degree THEN leftValue <- coeffArray[i] ENDIF
            IF i <= rhs.degree THEN rightValue <- rhs.coeffArray[i] ENDIF
            result[i] <- leftValue + rightValue
        ENDFOR
        RETURN result
    END
ENDCLASS
```

## Addition trace
Coefficients are stored low power first.
P1: [5, 2, 3, 0]; P2: [7, 0, 1, 4].
| Power | P1 | P2 | Sum |
|---:|---:|---:|---:|
| 0 | 5 | 7 | 12 |
| 1 | 2 | 0 | 2 |
| 2 | 3 | 1 | 4 |
| 3 | 0 | 4 | 4 |
Result: **4x³ + 4x² + 2x + 12**.
