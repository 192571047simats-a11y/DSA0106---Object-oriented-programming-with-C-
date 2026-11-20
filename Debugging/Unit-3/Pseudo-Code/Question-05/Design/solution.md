# Vector2D prefix postfix and compound assignment

## Design overview
Prefix increment changes the current object and returns a reference to it. Postfix increment saves the old state, changes the object, and returns the saved copy. Compound addition updates both coordinates and returns the current object by reference.

## Structured pseudo-code
```text
CLASS Vector2D
PRIVATE:
    x, y : REAL
PUBLIC:
    CONSTRUCTOR(a=0.0,b=0.0) x<-a; y<-b END
    PREFIX OPERATOR ++() RETURNS REF Vector2D
        x <- x + 1; y <- y + 1
        RETURN REF THIS
    END
    POSTFIX OPERATOR ++(dummy INTEGER) RETURNS Vector2D
        old <- COPY(THIS)
        x <- x + 1; y <- y + 1
        RETURN old
    END
    OPERATOR +=(REF rhs) RETURNS REF Vector2D
        x <- x + rhs.x; y <- y + rhs.y
        RETURN REF THIS
    END
    METHOD Display() DISPLAY x,y END
ENDCLASS
BEGIN
    v1 <- Vector2D(5,8)
    v2 <- ++v1
    v3 <- v1++
    DISPLAY v1,v2,v3
END
```

## Trace table
| Statement | v1 | v2 | v3 |
|---|---|---|---|
| Initial | (5,8) | – | – |
| `v2 <- ++v1` | (6,9) | (6,9) | – |
| `v3 <- v1++` | (7,10) | (6,9) | (6,9) |
Postfix returns the snapshot from immediately before the second increment.
