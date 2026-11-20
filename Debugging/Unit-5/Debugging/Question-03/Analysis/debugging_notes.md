# Exception Rethrowing Slicing Bug (throw e vs throw)

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
`throw e;` creates a new exception object based on the static type of the caught expression and can slice derived information. Bare `throw;` rethrows the currently handled exception unchanged.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
