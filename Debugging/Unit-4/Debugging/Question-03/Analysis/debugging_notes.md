# Base Class Pointer Member Access & Object Slicing

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Member access through `Vehicle*` is checked against the static type Vehicle, so derived-only methods are unavailable. Use a checked `dynamic_cast` for downcasting. A base object copied by value would slice derived fields.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
