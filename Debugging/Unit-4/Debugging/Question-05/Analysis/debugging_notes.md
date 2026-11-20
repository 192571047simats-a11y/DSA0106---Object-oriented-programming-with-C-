# Private Inheritance Access Violations & Inaccessible Base Cast

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Private inheritance makes the public base interface private in the derived class and prevents public upcasting outside the class. Use public inheritance for an IS-A relationship.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
