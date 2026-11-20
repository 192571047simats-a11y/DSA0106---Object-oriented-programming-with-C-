# Autonomous fleet multilevel inheritance

## Design overview
Pass constructor arguments through each inheritance tier using initializer lists. The heap object is first viewed through a Vehicle pointer; a checked downcast provides access to drone-only telemetry.

## Structured pseudo-code
```text
CLASS Vehicle
    vehicleVIN : STRING; baseWeightKg : REAL
    CONSTRUCTOR(vin,weight) assign fields END
    METHOD DisplaySpecs() DISPLAY vehicleVIN,baseWeightKg END
    VIRTUAL DESTRUCTOR()
ENDCLASS
CLASS AutonomousVehicle EXTENDS Vehicle
    lidarSensorID, firmwareVersion : STRING
    CONSTRUCTOR(vin,w,lidar,firmware) : BASE(vin,w)
        assign lidarSensorID, firmwareVersion
    END
ENDCLASS
CLASS DeliveryDrone EXTENDS AutonomousVehicle
    payloadCapacityKg,batteryChargePercent : REAL
    CONSTRUCTOR(vin,w,lidar,firmware,payload,battery)
        : BASE(vin,w,lidar,firmware)
        assign payloadCapacityKg,batteryChargePercent
    END
    METHOD DisplayFlightStatus()
        DisplaySpecs()
        DISPLAY lidarSensorID,firmwareVersion,payloadCapacityKg,batteryChargePercent
    END
ENDCLASS
BEGIN
    vehiclePtr <- NEW DeliveryDrone("VIN-88",12.5,"LDR-4","2.1",4.0,86)
    vehiclePtr->DisplaySpecs()
    dronePtr <- DYNAMIC_CAST(vehiclePtr AS DeliveryDrone POINTER)
    IF dronePtr != NULL THEN dronePtr->DisplayFlightStatus() ENDIF
    DELETE vehiclePtr
END
```

## Constructor trace
1. Vehicle constructor
2. AutonomousVehicle constructor
3. DeliveryDrone constructor
4. Destruction occurs in reverse order when deleted through a virtual base destructor.
