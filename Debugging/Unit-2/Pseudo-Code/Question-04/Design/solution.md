# Flexible logger with overloads and inline helper

## Design overview
Use an inline helper to format tags. Keep the overload signatures distinct so a one-argument string call selects the general logger and the two-argument integer/string call selects hardware diagnostics. Avoid overlapping default-argument overloads.

## Structured pseudo-code
```text
INLINE FUNCTION FormatPrefix(prefixTag : STRING) RETURNS STRING
    RETURN "[" + prefixTag + "] "
END

FUNCTION LogEvent(message : STRING)
    DISPLAY FormatPrefix("INFO") + message
END

FUNCTION LogEvent(message : STRING, severityLevel : INTEGER, timestamp : STRING)
    IF severityLevel = 1 THEN severity <- "LOW"
    ELSE IF severityLevel = 2 THEN severity <- "MEDIUM"
    ELSE IF severityLevel = 3 THEN severity <- "CRITICAL"
    ELSE severity <- "UNKNOWN"
    ENDIF
    DISPLAY "[" + severity + "] @ " + timestamp + " : " + message
END

FUNCTION LogEvent(errorCode : INTEGER, systemModule : STRING)
    DISPLAY "[HARDWARE_FAULT] Module: " + systemModule +
            " -> Error Code: 0x" + HEX(errorCode)
END

BEGIN
    LogEvent("System started")
    LogEvent("Temperature high", 2, "10:30:00")
    LogEvent(26, "SENSOR")
END
```

## Call-resolution trace
| Call | Selected overload | Output |
|---|---|---|
| `LogEvent("System started")` | One string parameter | `[INFO] System started` |
| `LogEvent("Temperature high",2,"10:30:00")` | Message, severity, timestamp | `[MEDIUM] @ 10:30:00 : Temperature high` |
| `LogEvent(26,"SENSOR")` | Integer, string | `[HARDWARE_FAULT] Module: SENSOR -> Error Code: 0x1A` |

The question's stated default arguments can be supported by a separate named wrapper or overload with non-conflicting signatures; do not give both the one-string overload and a three-parameter overload a default signature that makes the one-string call ambiguous.
