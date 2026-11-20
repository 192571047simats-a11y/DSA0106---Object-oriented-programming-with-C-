# GameObject lifecycle with virtual destructor

## Design overview
GameObject is abstract and has a virtual destructor. ParticleSystem owns a dynamic particle-coordinate array. Deleting each entity through a GameObject pointer invokes the derived destructor before the base destructor.

## Structured pseudo-code
```text
ABSTRACT CLASS GameObject
    ABSTRACT METHOD Update(deltaTime : REAL)
    ABSTRACT METHOD Render()
    VIRTUAL DESTRUCTOR()
ENDCLASS
CLASS ParticleSystem EXTENDS GameObject
PRIVATE:
    particleCoordinates : POINTER TO REAL
    particleCount : INTEGER
PUBLIC:
    CONSTRUCTOR(count)
        particleCount <- count
        ALLOCATE particleCoordinates[particleCount * 2]
    END
    OVERRIDE METHOD Update(deltaTime)
        UPDATE every particle using deltaTime
    END
    OVERRIDE METHOD Render() DISPLAY particleCount END
    DESTRUCTOR()
        DEALLOCATE particleCoordinates
        DISPLAY "ParticleSystem resources released"
    END
ENDCLASS
BEGIN
    sceneEntities[0] <- NEW ParticleSystem(100)
    FOR EACH entity IN sceneEntities
        entity->Update(0.016)
        entity->Render()
    ENDFOR
    FOR EACH entity IN sceneEntities
        DELETE entity
    ENDFOR
END
```

## Cleanup trace
For `DELETE GameObject*` referring to ParticleSystem:
1. `ParticleSystem` destructor runs and releases the particle array.
2. `GameObject` base destructor runs.
This order prevents the derived resource from being leaked.
