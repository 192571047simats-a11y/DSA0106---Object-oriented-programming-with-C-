# DynStr dynamic string with deep copy and +

## Design overview
Allocate `length + 1` bytes for the terminating null character. Copy construction allocates an independent buffer. Concatenation creates a new string and does not share either operand's storage.

## Structured pseudo-code
```text
CLASS DynStr
PRIVATE:
    dataPtr : POINTER TO CHARACTER
    charCount : INTEGER
PUBLIC:
    CONSTRUCTOR(sourceString)
        charCount <- LENGTH(sourceString)
        ALLOCATE dataPtr[charCount + 1]
        COPY sourceString INTO dataPtr
        dataPtr[charCount] <- NULL
    END
    COPY CONSTRUCTOR(REF other)
        charCount <- other.charCount
        ALLOCATE dataPtr[charCount + 1]
        COPY other.dataPtr INTO dataPtr
    END
    DESTRUCTOR()
        DEALLOCATE dataPtr
        dataPtr <- NULL
    END
    OPERATOR +(REF rhs) RETURNS DynStr
        combined <- CONCAT(dataPtr, rhs.dataPtr)
        RETURN NEW DynStr(combined)
    END
    METHOD Display() DISPLAY dataPtr END
ENDCLASS
BEGIN
    strA <- DynStr("Hello ")
    strB <- DynStr("World!")
    strC <- strA + strB
    strC.Display()
END
```

## Heap trace
| Object | Text | Length | Allocated bytes |
|---|---|---:|---:|
| strA | `Hello ` | 6 | 7 |
| strB | `World!` | 6 | 7 |
| strC | `Hello World!` | 12 | 13 |
Total simultaneous character-buffer allocation = 27 bytes, excluding object metadata. Each object owns its own buffer and releases it once in its destructor.
