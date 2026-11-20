# TaxCalculationEngine

## Design overview
Cap deductions at their statutory limits, prevent taxable income from becoming negative, calculate tax progressively, add 4% cess, and round to the nearest whole rupee.

## Structured pseudo-code
```text
CLASS TaxCalculationEngine
PUBLIC:
    METHOD Calculate(gross, d80C, health) RETURNS INTEGER
        eligible80C <- MIN(d80C, 150000)
        eligibleHealth <- MIN(health, 25000)
        taxable <- MAX(0, gross - eligible80C - eligibleHealth)
        rawTax <- 0
        IF taxable > 1000000 THEN
            rawTax <- rawTax + (taxable - 1000000) * 0.30
            taxable <- 1000000
        ENDIF
        IF taxable > 500000 THEN
            rawTax <- rawTax + (taxable - 500000) * 0.20
            taxable <- 500000
        ENDIF
        IF taxable > 250000 THEN
            rawTax <- rawTax + (taxable - 250000) * 0.05
        ENDIF
        finalTax <- rawTax * 1.04
        RETURN INTEGER(finalTax + 0.5)
    ENDMETHOD
ENDCLASS
BEGIN
    CREATE engine AS TaxCalculationEngine
    tax <- engine.Calculate(1200000, 180000, 30000)
    DISPLAY tax
END
```

## Dry-run trace
| Step | Amount |
|---|---:|
| Gross salary | 1,200,000 |
| Eligible 80C | 150,000 |
| Eligible health | 25,000 |
| Taxable income | 1,025,000 |
| 0% band | 0 |
| 5% band: 250,000 × 5% | 12,500 |
| 20% band: 500,000 × 20% | 100,000 |
| 30% band: 25,000 × 30% | 7,500 |
| Raw tax | 120,000 |
| 4% cess | 4,800 |
| Final rounded tax | **124,800** |
