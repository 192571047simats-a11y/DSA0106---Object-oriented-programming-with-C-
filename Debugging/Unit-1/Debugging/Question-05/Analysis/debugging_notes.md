# Dynamic Array Allocation & Stray Loop Semicolon

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
The semicolon after the for header makes the loop body empty. The following block executes once with `i` out of scope. Remove the semicolon, use the loop body, and pair `new[]` with `delete[]`.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
