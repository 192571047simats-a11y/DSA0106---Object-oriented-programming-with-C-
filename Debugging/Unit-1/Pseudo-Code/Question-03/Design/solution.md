# CheckFlightReadiness(statusRegister)

## Design overview
Mandatory mask is `0x0F`; inhibitor mask is `0xB0` (bits 4, 5 and 7); radio bit `0x40` is non-blocking. Use bitwise operations directly and report each active fault.

## Structured pseudo-code
```text
CONSTANT REQUIRED_MASK <- 0x0F
CONSTANT LOW_BATTERY <- 0x10
CONSTANT OVER_TEMP <- 0x20
CONSTANT FATAL_ACTUATOR <- 0x80
CONSTANT INHIBITOR_MASK <- 0xB0

METHOD CheckFlightReadiness(statusRegister : BYTE)
    missing <- REQUIRED_MASK XOR (statusRegister AND REQUIRED_MASK)
    IF (statusRegister AND LOW_BATTERY) != 0 THEN DISPLAY "Low battery warning" ENDIF
    IF (statusRegister AND OVER_TEMP) != 0 THEN DISPLAY "Over-temperature warning" ENDIF
    IF (statusRegister AND FATAL_ACTUATOR) != 0 THEN DISPLAY "Fatal actuator failure" ENDIF
    IF missing != 0 THEN DISPLAY "Missing sensor mask: ", HEX(missing) ENDIF
    IF missing = 0 AND (statusRegister AND INHIBITOR_MASK) = 0 THEN
        DISPLAY "Flight Ready"
    ELSE
        DISPLAY "Flight NOT Ready"
    ENDIF
ENDMETHOD
BEGIN
    CheckFlightReadiness(0x4F)
    CheckFlightReadiness(0x3B)
END
```

## Trace table
| Register | Required bits present? | Inhibitors | Result |
|---|---|---|---|
| `0x4F` | `0x4F AND 0x0F = 0x0F` complete | `0x4F AND 0xB0 = 0x00` | Ready; radio bit is set but non-blocking |
| `0x3B` | `0x3B AND 0x0F = 0x0B`; missing `0x04` | `0x3B AND 0xB0 = 0x30` | Not ready; over-temperature and low required sensor bit 2 |

Note: `0x3B` has both low-battery (`0x10`) and over-temperature (`0x20`) inhibitor bits set; missing mandatory mask is `0x04`.
