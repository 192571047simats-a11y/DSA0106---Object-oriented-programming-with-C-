# File ingestion RAII and stack unwinding

## Design overview
ResourceGuard acquires a handle in its constructor and releases it in its destructor. A CRC mismatch throws a typed exception. Stack unwinding destroys local automatic objects before control reaches the catch handler.

## Structured pseudo-code
```text
CLASS CRCValidationException
    expected, calculated : INTEGER
    CONSTRUCTOR(e,c) assign fields END
ENDCLASS
CLASS ResourceGuard
    handle : INTEGER
    CONSTRUCTOR(fileName)
        handle <- OPEN(fileName)
        IF handle invalid THEN THROW FileOpenException ENDIF
        DISPLAY "Resource acquired"
    END
    DESTRUCTOR()
        CLOSE(handle)
        DISPLAY "Resource released"
    END
ENDCLASS
FUNCTION IngestDataStream(fileName)
    guard <- ResourceGuard(fileName)
    expectedCRC <- READ_EXPECTED_CRC(guard)
    calculatedCRC <- CALCULATE_CRC(guard)
    IF expectedCRC != calculatedCRC THEN
        THROW CRCValidationException(expectedCRC,calculatedCRC)
    ENDIF
    DISPLAY "CRC valid"
END
BEGIN
    TRY
        IngestDataStream("telemetry.bin")
    CATCH (e AS CRCValidationException)
        DISPLAY "CRC mismatch", e.expected, e.calculated
    CATCH (...)
        DISPLAY "Unexpected ingestion failure"
    ENDTRY
END
```

## Event trace
| Order | Event |
|---:|---|
| 1 | ResourceGuard constructor opens file |
| 2 | Data is read and CRC calculated |
| 3 | CRC mismatch throws exception |
| 4 | Stack unwinding invokes ResourceGuard destructor |
| 5 | File handle is closed |
| 6 | CRCValidationException handler executes |
The resource release occurs before the catch body.
