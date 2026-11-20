# Static Data Member Linkage & Member Function Scoping

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
A static data member needs one definition unless it is an inline static member (C++17). A static member function has no `this` pointer and cannot access instance field `accHolder`; use a non-static member function for account details.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
