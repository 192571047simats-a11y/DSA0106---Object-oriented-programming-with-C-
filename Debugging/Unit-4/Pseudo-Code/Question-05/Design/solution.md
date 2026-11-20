# Product pointer array and zero-copy bubble sort

## Design overview
Each Product is dynamically allocated once. Bubble sort compares the prices of pointed-to objects but swaps only pointer variables, so product objects are not copied or moved.

## Structured pseudo-code
```text
CLASS Product
    sku : STRING; price : REAL; stockCount : INTEGER
    CONSTRUCTOR(s,p,n) assign fields END
    METHOD PrintProduct() DISPLAY sku,price,stockCount END
    DESTRUCTOR()
ENDCLASS
BEGIN
    catalog[0] <- NEW Product("Laptop",1200,5)
    catalog[1] <- NEW Product("Mouse",25,40)
    catalog[2] <- NEW Product("Monitor",350,12)
    N <- 3
    FOR i <- 0 TO N-2
        FOR j <- 0 TO N-2-i
            IF catalog[j]->price > catalog[j+1]->price THEN
                tempPointer <- catalog[j]
                catalog[j] <- catalog[j+1]
                catalog[j+1] <- tempPointer
            ENDIF
        ENDFOR
    ENDFOR
    FOR EACH pointer IN catalog
        pointer->PrintProduct()
    ENDFOR
    FOR EACH pointer IN catalog
        DELETE pointer
    ENDFOR
END
```

## Pointer-swap trace
Let addresses be L, M and R for Laptop, Mouse and Monitor.
| Pass | Comparison | Swap | Pointer order |
|---|---|---|---|
| Start | – | – | L(1200), M(25), R(350) |
| 1, j=0 | 1200 > 25 | Yes | M, L, R |
| 1, j=1 | 1200 > 350 | Yes | M, R, L |
| 2, j=0 | 25 > 350 | No | M, R, L |
Final ascending order: Mouse ($25), Monitor ($350), Laptop ($1200). Only pointer values are swapped.
