# Resilient banking nested exception engine

## Design overview
Use a base TransactionException with specialized derived exceptions. DebitLedger throws the appropriate type. The audit wrapper catches the base type only to log and immediately rethrows the same exception. Main catches specific types before the base type.

## Structured pseudo-code
```text
CLASS TransactionException
    reason : STRING
    CONSTRUCTOR(message) reason<-message END
ENDCLASS
CLASS AccountFrozenException EXTENDS TransactionException ENDCLASS
CLASS DailyLimitExceededException EXTENDS TransactionException
    excessAmount : REAL
ENDCLASS

FUNCTION DebitLedger(amount, frozen, dailyTotal)
    IF frozen THEN THROW AccountFrozenException("Account is frozen") ENDIF
    IF dailyTotal + amount > 50000 THEN
        THROW DailyLimitExceededException("Daily limit exceeded", dailyTotal+amount-50000)
    ENDIF
    DISPLAY "Debit completed"
END

FUNCTION AuditTransactionWrapper(amount,frozen,dailyTotal)
    TRY
        DebitLedger(amount,frozen,dailyTotal)
    CATCH (e AS TransactionException)
        DISPLAY "SECURITY AUDIT: ", e.reason
        RETHROW
    ENDTRY
END

BEGIN
    TRY
        AuditTransactionWrapper(1000, TRUE, 0)
    CATCH (e AS AccountFrozenException)
        DISPLAY "Transaction declined: frozen account"
    CATCH (e AS DailyLimitExceededException)
        DISPLAY "Transaction declined: daily limit"
    CATCH (e AS TransactionException)
        DISPLAY "Transaction failed: ", e.reason
    ENDTRY
END
```

## Dry-run trace
| Sequence | Control event |
|---:|---|
| 1 | Main calls AuditTransactionWrapper |
| 2 | Wrapper calls DebitLedger |
| 3 | DebitLedger sees frozen = TRUE and throws AccountFrozenException |
| 4 | Wrapper catches TransactionException base reference |
| 5 | Audit entry is written |
| 6 | Bare rethrow propagates the original derived exception |
| 7 | Main's AccountFrozenException handler executes |
Output notice: `Transaction declined: frozen account`.
