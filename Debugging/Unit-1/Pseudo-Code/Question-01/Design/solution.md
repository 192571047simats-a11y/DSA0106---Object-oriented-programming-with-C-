# WaterConsumer class and tiered invoice

## Design overview
- Keep readings and bill state private inside `WaterConsumer`.
- Reject negative readings and a current reading below the previous reading.
- Calculate consumption once, then apply the three progressive tariff bands.
- Apply the 10% environmental surcharge only when consumption exceeds 300 units.

## Structured pseudo-code
```text
CLASS WaterConsumer
PRIVATE:
    consumerID : STRING
    previousReading, currentReading : REAL
    unitsConsumed, totalBill : REAL
PUBLIC:
    METHOD Initialize(id, prev, curr)
        IF prev < 0 OR curr < prev THEN
            DISPLAY "Invalid meter readings"
            RETURN FALSE
        ENDIF
        consumerID <- id
        previousReading <- prev
        currentReading <- curr
        RETURN TRUE
    ENDMETHOD

    METHOD CalculateConsumption()
        unitsConsumed <- currentReading - previousReading
        RETURN unitsConsumed
    ENDMETHOD

    METHOD ComputeBill()
        remaining <- unitsConsumed
        totalBill <- 0
        firstBand <- MIN(remaining, 100)
        totalBill <- totalBill + firstBand * 1.50
        remaining <- remaining - firstBand
        secondBand <- MIN(remaining, 200)
        totalBill <- totalBill + secondBand * 2.50
        remaining <- remaining - secondBand
        IF remaining > 0 THEN
            totalBill <- totalBill + remaining * 4.00
            totalBill <- totalBill * 1.10
        ENDIF
        RETURN totalBill
    ENDMETHOD

    METHOD DisplayBill()
        DISPLAY consumerID, unitsConsumed, totalBill
    ENDMETHOD
ENDCLASS

BEGIN
    CREATE consumer AS WaterConsumer
    IF consumer.Initialize("WC101", 1450.0, 1820.0) THEN
        consumer.CalculateConsumption()
        consumer.ComputeBill()
        consumer.DisplayBill()
    ENDIF
END
```

## Dry-run trace
| Item | Calculation | Value |
|---|---:|---:|
| Units | 1820 - 1450 | 370 |
| First 100 | 100 × 1.50 | 150.00 |
| Next 200 | 200 × 2.50 | 500.00 |
| Remaining 70 | 70 × 4.00 | 280.00 |
| Subtotal | 150 + 500 + 280 | 930.00 |
| 10% surcharge | 930 × 0.10 | 93.00 |
| Final bill | 930 + 93 | **1023.00** |

Output: `WC101 | Units: 370 | Total: 1023.00`
