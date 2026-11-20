# University ERP virtual inheritance

## Design overview
Student and Faculty inherit Person virtually. TeachingAssistant is the most-derived class and initializes the single shared Person subobject directly.

## Structured pseudo-code
```text
CLASS Person
    personID : STRING; fullName : STRING; email : STRING
    CONSTRUCTOR(id,name,mail) assign fields END
ENDCLASS
CLASS Student EXTENDS VIRTUAL Person
    gpa : REAL; creditsEarned : INTEGER
    CONSTRUCTOR(id,name,mail,g,c) : Person(id,name,mail)
ENDCLASS
CLASS Faculty EXTENDS VIRTUAL Person
    academicDepartment : STRING; rankTitle : STRING
    CONSTRUCTOR(id,name,mail,dept,rank) : Person(id,name,mail)
ENDCLASS
CLASS TeachingAssistant EXTENDS Student, Faculty
    stipendAmount : REAL; assignedCourse : STRING
    CONSTRUCTOR(id,name,mail,g,c,dept,rank,stipend,course)
        : Person(id,name,mail),
          Student(id,name,mail,g,c),
          Faculty(id,name,mail,dept,rank)
        assign stipendAmount, assignedCourse
    END
    METHOD DisplayTARecord()
        DISPLAY personID, fullName, gpa, academicDepartment, stipendAmount
    END
ENDCLASS
BEGIN
    ta <- TeachingAssistant("TA17","Mira","mira@uni.edu",3.8,90,
                            "Computing","Assistant",18000,"C++")
    ta.DisplayTARecord()
END
```

## Trace
Construction initializes the virtual Person base once, then Student, Faculty, and TeachingAssistant. The record has one shared `personID` and no ambiguous duplicate Person fields.
