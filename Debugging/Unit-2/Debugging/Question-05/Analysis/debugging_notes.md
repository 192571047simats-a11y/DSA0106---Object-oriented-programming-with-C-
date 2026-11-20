# Friend Function Declaration & Scope Resolution Flaws

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
A friend function is a non-member. Declare it inside the class with `friend`, define it at namespace scope, and call it as `showBox(object)`, not `object.showBox()`.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
