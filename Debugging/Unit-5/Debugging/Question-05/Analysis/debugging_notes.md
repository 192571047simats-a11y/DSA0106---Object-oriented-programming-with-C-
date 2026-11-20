# Pass-by-Value Object Slicing Suppressing Dynamic Binding

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Passing a polymorphic object by value copies only the base subobject into the parameter, causing slicing and losing dynamic dispatch. Accept `const Base&` or `Base*` instead.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
