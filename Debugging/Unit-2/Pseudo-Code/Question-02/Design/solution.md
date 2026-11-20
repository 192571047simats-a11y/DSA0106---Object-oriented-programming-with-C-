# Matrix2D and friend diagonal dot product

## Design overview
Keep the 3×3 array private. Declare all member methods in the class and define them outside with `Matrix2D::`. The friend function is not a member and directly reads private diagonal entries.

## Structured pseudo-code
```text
CLASS Matrix2D
PRIVATE:
    grid : ARRAY[3][3] OF REAL
PUBLIC:
    METHOD Initialize()
        FOR r <- 0 TO 2
            FOR c <- 0 TO 2
                grid[r][c] <- 0
            ENDFOR
        ENDFOR
    END
    METHOD SetElement(row, col, value)
        IF row < 0 OR row >= 3 OR col < 0 OR col >= 3 THEN
            DISPLAY "Index out of range"; RETURN
        ENDIF
        grid[row][col] <- value
    END
    METHOD GetElement(row, col) RETURNS REAL
        IF indices invalid THEN DISPLAY "Index out of range"; RETURN 0 ENDIF
        RETURN grid[row][col]
    END
    METHOD Display()
        DISPLAY grid
    END
    FRIEND FUNCTION ComputeCrossTrace(A, B) RETURNS REAL
        sum <- 0
        FOR i <- 0 TO 2
            sum <- sum + A.grid[i][i] * B.grid[i][i]
        ENDFOR
        RETURN sum
    END
ENDCLASS

METHOD Matrix2D::Initialize() ... END
METHOD Matrix2D::SetElement(...) ... END
METHOD Matrix2D::GetElement(...) ... END
METHOD Matrix2D::Display() ... END
BEGIN
    CREATE A, B AS Matrix2D
    A.Initialize(); B.Initialize()
    SET A diagonal TO [2,4,6]
    SET B diagonal TO [1,3,5]
    DISPLAY ComputeCrossTrace(A,B)
END
```

## Trace table
| i | A[i][i] | B[i][i] | Product | Running sum |
|---:|---:|---:|---:|---:|
| 0 | 2 | 1 | 2 | 2 |
| 1 | 4 | 3 | 12 | 14 |
| 2 | 6 | 5 | 30 | **44** |
