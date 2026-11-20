# Composite canvas and fluent Circle API

## Design overview
Circle contains a Point2D object, representing a HAS-A relationship. Setters return a reference to the same Circle so calls can be chained using dot notation.

## Structured pseudo-code
```text
CLASS Point2D
PRIVATE: x,y : REAL
PUBLIC:
    CONSTRUCTOR(a=0.0,b=0.0) x<-a; y<-b END
    METHOD Set(a,b) x<-a; y<-b END
    METHOD Display() DISPLAY x,y END
ENDCLASS
CLASS Circle
PRIVATE:
    centerPoint : Point2D
    radius : REAL
PUBLIC:
    CONSTRUCTOR() centerPoint<-Point2D(0,0); radius<-1.0 END
    METHOD SetCenter(newX,newY) RETURNS REF Circle
        centerPoint.Set(newX,newY)
        RETURN REF THIS
    END
    METHOD SetRadius(r) RETURNS REF Circle
        IF r <= 0 THEN DISPLAY "Radius must be positive"
        ELSE radius <- r
        ENDIF
        RETURN REF THIS
    END
    METHOD Draw()
        DISPLAY "Center:", centerPoint, " Radius:", radius
    END
ENDCLASS
BEGIN
    myCircle.SetCenter(12.5,30.0).SetRadius(7.5).Draw()
END
```

## Trace
| Call | Center | Radius |
|---|---|---:|
| Constructor | (0,0) | 1.0 |
| SetCenter(12.5,30.0) | (12.5,30.0) | 1.0 |
| SetRadius(7.5) | (12.5,30.0) | 7.5 |
| Draw | prints final state | 7.5 |
