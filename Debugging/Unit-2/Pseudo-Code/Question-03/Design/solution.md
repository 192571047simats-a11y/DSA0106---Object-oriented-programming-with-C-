# StudentRecord array and descending rank sort

## Design overview
Each object owns roll number, name, three marks, percentage and grade. Use a default constructor so the array can be created. Bubble sort swaps whole StudentRecord objects by percentage.

## Structured pseudo-code
```text
CLASS StudentRecord
PRIVATE:
    rollNo : INTEGER
    studentName : STRING
    marks : ARRAY[3] OF REAL
    percentage : REAL
    grade : CHARACTER
    METHOD CalculateResult()
        percentage <- (marks[0] + marks[1] + marks[2]) / 3
        IF percentage >= 85 THEN grade <- 'A'
        ELSE IF percentage >= 70 THEN grade <- 'B'
        ELSE IF percentage >= 50 THEN grade <- 'C'
        ELSE grade <- 'F'
        ENDIF
    END
PUBLIC:
    CONSTRUCTOR()
        rollNo <- 0; studentName <- ""; marks <- [0,0,0]
        percentage <- 0; grade <- 'F'
    END
    METHOD ReadData(r,n,a,b,c)
        rollNo <- r; studentName <- n; marks <- [a,b,c]
        CalculateResult()
    END
    METHOD GetPercentage() RETURNS REAL
        RETURN percentage
    END
    METHOD Display() ... END
ENDCLASS
BEGIN
    students <- ARRAY OF 3 StudentRecord
    students[0].ReadData(1,"Asha",90,80,85)   // 85
    students[1].ReadData(2,"Bala",70,75,80)   // 75
    students[2].ReadData(3,"Charu",60,65,70)  // 65
    FOR i <- 0 TO 1
        FOR j <- 0 TO 1-i
            IF students[j].GetPercentage() < students[j+1].GetPercentage() THEN
                SWAP students[j], students[j+1]
            ENDIF
        ENDFOR
    ENDFOR
    DISPLAY students
END
```

## Dry-run trace
| Pass | Comparison | Swap? | Order after comparison |
|---|---|---|---|
| 1 | 85 vs 75 | No | Asha, Bala, Charu |
| 1 | 75 vs 65 | No | Asha, Bala, Charu |
| 2 | 85 vs 75 | No | Asha, Bala, Charu |
Final rank: Asha 85% (A), Bala 75% (B), Charu 65% (C).
