# Polymorphic employee payroll

## Design overview
Employee is abstract because `CalculatePay` is pure virtual. Store derived instances through Employee pointers and invoke the virtual method through the base interface. Delete through a virtual destructor.

## Structured pseudo-code
```text
ABSTRACT CLASS Employee
PROTECTED: employeeID, name : STRING
PUBLIC:
    CONSTRUCTOR(id,n) assign id,name END
    ABSTRACT METHOD CalculatePay() RETURNS REAL
    METHOD DisplayHeader() DISPLAY employeeID,name END
    VIRTUAL DESTRUCTOR()
ENDCLASS
CLASS SalariedEmployee EXTENDS Employee
    monthlySalary : REAL
    OVERRIDE METHOD CalculatePay() RETURN monthlySalary END
ENDCLASS
CLASS HourlyEmployee EXTENDS Employee
    hourlyWage,hoursWorked : REAL
    OVERRIDE METHOD CalculatePay()
        regular <- MIN(hoursWorked,40) * hourlyWage
        overtime <- MAX(0,hoursWorked-40) * hourlyWage * 1.5
        RETURN regular + overtime
    END
ENDCLASS
BEGIN
    employees : ARRAY[2] OF POINTER TO Employee
    employees[0] <- NEW SalariedEmployee("E01","Asha",8500)
    employees[1] <- NEW HourlyEmployee("E02","Bala",50,48)
    total <- 0
    FOR EACH employee IN employees
        employee->DisplayHeader()
        pay <- employee->CalculatePay()
        DISPLAY pay
        total <- total + pay
    ENDFOR
    DISPLAY total
    DELETE each employee
END
```

## Pay trace
| Employee | Calculation | Pay |
|---|---|---:|
| Salaried | Monthly salary | 8,500 |
| Hourly regular | 40 × 50 | 2,000 |
| Hourly overtime | 8 × 50 × 1.5 | 600 |
| Hourly total | 2,000 + 600 | 2,600 |
| Total disbursement | 8,500 + 2,600 | **11,100** |
