# DivisorAndPrimeEngine

## Design overview
Validate positive input, handle `N = 1`, initialize the proper-divisor sum with 1 for `N > 1`, and test candidate factors only through the square root. Add paired divisors once.

## Structured pseudo-code
```text
METHOD DivisorAndPrimeEngine()
    REPEAT
        INPUT N
        IF N <= 0 THEN DISPLAY "Enter a positive integer" ENDIF
    UNTIL N > 0
    IF N = 1 THEN
        DISPLAY "Deficient"
        RETURN
    ENDIF
    sumOfDivisors <- 1
    d <- 2
    WHILE d * d <= N DO
        IF N MOD d != 0 THEN
            d <- d + 1
            CONTINUE
        ENDIF
        sumOfDivisors <- sumOfDivisors + d
        paired <- N / d
        IF paired != d THEN sumOfDivisors <- sumOfDivisors + paired ENDIF
        d <- d + 1
    ENDWHILE
    IF sumOfDivisors = N THEN DISPLAY "Perfect"
    ELSE IF sumOfDivisors > N THEN DISPLAY "Abundant"
    ELSE DISPLAY "Deficient"
    ENDIF
ENDMETHOD
```

## Trace tables
For `N = 28`:
| d | 28 MOD d | Paired divisor | Sum |
|---:|---:|---:|---:|
| Start | – | 1 | 1 |
| 2 | 0 | 14 | 17 |
| 3 | 1 | – | 17 |
| 4 | 0 | 7 | 28 |
Stop when `5 × 5 > 28`. Sum = 28, therefore **Perfect**.

For `N = 12`:
| d | 12 MOD d | Paired divisor | Sum |
|---:|---:|---:|---:|
| Start | – | 1 | 1 |
| 2 | 0 | 6 | 9 |
| 3 | 0 | 4 | 16 |
Stop when `4 × 4 > 12`. Sum = 16, therefore **Abundant**.
