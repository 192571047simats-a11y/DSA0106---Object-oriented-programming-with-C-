# Complex number constructors and operators

## Design overview
Store real and imaginary components separately. Provide three constructor forms and implement addition, multiplication and equality using their mathematical definitions.

## Structured pseudo-code
```text
CLASS Complex
PRIVATE:
    real, imag : REAL
PUBLIC:
    CONSTRUCTOR() real <- 0; imag <- 0 END
    CONSTRUCTOR(r : REAL) real <- r; imag <- 0 END
    CONSTRUCTOR(r : REAL, i : REAL) real <- r; imag <- i END
    OPERATOR +(REF other) RETURNS Complex
        RETURN Complex(real + other.real, imag + other.imag)
    END
    OPERATOR *(REF other) RETURNS Complex
        RETURN Complex(real*other.real - imag*other.imag,
                       real*other.imag + imag*other.real)
    END
    OPERATOR ==(REF other) RETURNS BOOLEAN
        RETURN real = other.real AND imag = other.imag
    END
    METHOD Display() DISPLAY real, " + ", imag, "i" END
ENDCLASS
BEGIN
    C1 <- Complex(3,2)
    C2 <- Complex(1,4)
    product <- C1 * C2
    product.Display()
END
```

## Dry-run trace
| Component | Calculation | Result |
|---|---|---:|
| Real | (3×1) − (2×4) | -5 |
| Imaginary | (3×4) + (2×1) | 14 |
| Product | | **-5 + 14i** |
