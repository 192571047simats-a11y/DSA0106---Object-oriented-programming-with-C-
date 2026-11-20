# Switch-Case Variable Initialization & Illegal Case Types

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
A case label cannot jump into the scope of a variable whose initialization is bypassed. Braces create a separate scope for each case. A switch condition must be integral or enumeration type; `case 4.5` is invalid. Add `break` to prevent unintended fall-through.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
