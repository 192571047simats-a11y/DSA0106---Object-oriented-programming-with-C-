# Scope Resolution & Variable Shadowing Conflicts

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
A single colon is invalid in a global qualification. `::taxRate` names the global variable. The unary scope operator cannot access an enclosing automatic local variable; rename the inner local variable instead of trying to qualify it.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
