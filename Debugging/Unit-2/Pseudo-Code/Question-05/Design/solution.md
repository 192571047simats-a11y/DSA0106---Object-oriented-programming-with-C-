# RegisterBank returning a reference

## Design overview
A valid index returns a reference to an element in the object's fixed array. An invalid index returns a reference to a persistent `errorSink`, so the caller never receives a dangling reference or an out-of-bounds array reference.

## Structured pseudo-code
```text
CLASS RegisterBank
PRIVATE:
    registers : ARRAY[8] OF INTEGER
    errorSink : INTEGER
PUBLIC:
    CONSTRUCTOR()
        FOR i <- 0 TO 7
            registers[i] <- 0
        ENDFOR
        errorSink <- -1
    END
    METHOD GetRegister(index : INTEGER) RETURNS REF INTEGER
        IF index >= 0 AND index < 8 THEN
            RETURN REF registers[index]
        ELSE
            DISPLAY "Register index out of range"
            RETURN REF errorSink
        ENDIF
    END
    METHOD DisplayState()
        FOR i <- 0 TO 7
            DISPLAY HEX(registers[i])
        ENDFOR
    END
ENDCLASS
BEGIN
    CREATE bank AS RegisterBank
    bank.GetRegister(0) <- 170
    bank.GetRegister(1) <- 255
    readVal <- bank.GetRegister(0)
    DISPLAY "Read value: ", HEX(readVal)
    bank.GetRegister(10) <- 999
    DISPLAY "Error sink: ", bank.GetRegister(10)
    bank.DisplayState()
END
```

## Trace table
| Operation | Result |
|---|---|
| Initialize | all registers = 0, errorSink = -1 |
| Set register 0 to 170 | register[0] = `0xAA` |
| Set register 1 to 255 | register[1] = `0xFF` |
| Read register 0 | `0xAA` |
| Write index 10 | alert; errorSink becomes 999 |
| Display | `AA FF 0 0 0 0 0 0` |

A function returning `T&` is an lvalue expression when it returns a valid persistent object. Assignment to the call result therefore assigns to that referenced object.
