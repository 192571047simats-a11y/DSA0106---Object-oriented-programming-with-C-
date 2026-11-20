# BranchOffice static reserve manager

## Design overview
Each branch stores its own balance. Static fields hold the enterprise-wide reserve and active branch count. Successful deposits and withdrawals update both values.

## Structured pseudo-code
```text
CLASS BranchOffice
PRIVATE:
    branchID, branchName : STRING
    currentBalance : REAL
    STATIC totalVaultReserves : REAL <- 0
    STATIC totalBranchesActive : INTEGER <- 0
PUBLIC:
    CONSTRUCTOR(id, name, openingDeposit)
        branchID <- id; branchName <- name
        currentBalance <- openingDeposit
        totalVaultReserves <- totalVaultReserves + openingDeposit
        totalBranchesActive <- totalBranchesActive + 1
    END
    METHOD Deposit(amount)
        IF amount > 0 THEN
            currentBalance <- currentBalance + amount
            totalVaultReserves <- totalVaultReserves + amount
        ENDIF
    END
    METHOD Withdraw(amount) RETURNS BOOLEAN
        IF amount > 0 AND amount <= currentBalance THEN
            currentBalance <- currentBalance - amount
            totalVaultReserves <- totalVaultReserves - amount
            RETURN TRUE
        ENDIF
        RETURN FALSE
    END
    STATIC METHOD GetVaultSummary()
        DISPLAY totalBranchesActive, totalVaultReserves
    END
    STATIC METHOD GetGlobalLiquidityRatio(targetReserve) RETURNS REAL
        IF targetReserve <= 0 THEN RETURN 0 ENDIF
        RETURN totalVaultReserves / targetReserve
    END
ENDCLASS
BEGIN
    b1 <- BranchOffice("B01","North",200000)
    b2 <- BranchOffice("B02","South",150000)
    b1.Deposit(150000)
    b2.Withdraw(50000)
    BranchOffice.GetVaultSummary()
END
```

## Trace table
| Event | Branch 1 | Branch 2 | Total reserves |
|---|---:|---:|---:|
| Opening | 200,000 | 150,000 | 350,000 |
| Branch 1 deposit | 350,000 | 150,000 | 500,000 |
| Branch 2 withdrawal | 350,000 | 100,000 | **450,000** |
Active branches = 2.
