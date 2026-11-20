# Non-Virtual Destructor Memory Leak in Polymorphic Deletion

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Deleting a derived object through a base pointer requires a virtual base destructor. Without it, behavior is undefined and the derived destructor may not run. A virtual destructor enables correct derived-to-base destruction.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
