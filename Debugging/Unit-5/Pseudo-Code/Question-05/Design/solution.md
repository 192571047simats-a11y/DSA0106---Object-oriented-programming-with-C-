# Telemetry calibration and noexcept contract

## Design overview
Calibration is allowed to throw when the computed temperature is outside the physical range. CommitTelemetry is declared noexcept and catches all internal failures so no exception escapes it. The caller catches calibration errors.

## Structured pseudo-code
```text
CLASS OutOfBoundsException
    measuredTemperature : REAL
ENDCLASS

FUNCTION CalibrateThermalSensors(rawVoltage : REAL) RETURNS REAL NOEXCEPT(FALSE)
    temperature <- CONVERT_VOLTAGE_TO_TEMPERATURE(rawVoltage)
    IF temperature < -273.15 OR temperature > 1500.0 THEN
        THROW OutOfBoundsException(temperature)
    ENDIF
    RETURN temperature
END

FUNCTION CommitTelemetry(finalTemp : REAL) NOEXCEPT
    TRY
        WRITE_TO_AVIONICS_BUS(finalTemp)
        DISPLAY "Telemetry committed"
    CATCH (...)
        RECORD_INTERNAL_COMMIT_FAILURE()
        DISPLAY "Commit failure contained"
    ENDTRY
END

BEGIN
    TRY
        calibrated <- CalibrateThermalSensors(VOLTAGE_FOR_MINUS_300_C)
        CommitTelemetry(calibrated)
    CATCH (e AS OutOfBoundsException)
        DISPLAY "Calibration rejected: ", e.measuredTemperature
    CATCH (...)
        DISPLAY "Unexpected calibration failure"
    ENDTRY
END
```

## Trace
| Step | Event |
|---:|---|
| 1 | Calibration receives voltage corresponding to -300.0°C |
| 2 | -300.0 is below the lower bound -273.15°C |
| 3 | OutOfBoundsException is thrown |
| 4 | Control transfers to Main's OutOfBoundsException handler |
| 5 | CommitTelemetry is not called for the invalid reading |
Output: `Calibration rejected: -300.0°C`.
