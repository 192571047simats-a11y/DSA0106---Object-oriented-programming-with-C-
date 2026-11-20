# ATM_SessionController

## Design overview
Authenticate with a maximum of three attempts. Only after successful authentication, enter a sentinel-controlled menu loop. Validate positive deposits, withdrawals, available balance and denomination multiples.

## Structured pseudo-code
```text
CONSTANT CORRECT_PIN <- 4821
balance <- 1000.00  // Sample opening balance; the question does not specify one
attempts <- 0
authenticated <- FALSE
WHILE attempts < 3 AND authenticated = FALSE DO
    INPUT enteredPIN
    attempts <- attempts + 1
    IF enteredPIN = CORRECT_PIN THEN authenticated <- TRUE
    ELSE DISPLAY "Incorrect PIN" ENDIF
ENDWHILE
IF authenticated = FALSE THEN
    DISPLAY "Card locked"
    STOP
ENDIF
choice <- 0
WHILE choice != 4 DO
    DISPLAY "1 Balance 2 Deposit 3 Withdraw 4 Exit"
    INPUT choice
    SWITCH choice
        CASE 1: DISPLAY balance; BREAK
        CASE 2:
            INPUT amount
            IF amount > 0 THEN balance <- balance + amount
            ELSE DISPLAY "Invalid deposit" ENDIF
            BREAK
        CASE 3:
            INPUT amount
            IF amount <= 0 OR amount > balance THEN DISPLAY "Invalid amount or insufficient funds"
            ELSE IF amount MOD 100 != 0 THEN DISPLAY "Amount must be a multiple of 100"
            ELSE balance <- balance - amount; DISPLAY "Withdrawal successful"
            ENDIF
            BREAK
        CASE 4: DISPLAY "Session ended"; BREAK
        DEFAULT: DISPLAY "Invalid menu option"
    ENDSWITCH
ENDWHILE
```

## Dry-run trace
| Event | Input | Result | Balance |
|---|---:|---|---:|
| PIN attempt 1 | 1111 | Incorrect PIN | 1000 |
| PIN attempt 2 | 4821 | Authenticated | 1000 |
| Withdrawal | 250 | Declined: not a multiple of 100 | 1000 |
| Withdrawal | 300 | Successful | 700 |
| Exit | 4 | Session ended | 700 |
