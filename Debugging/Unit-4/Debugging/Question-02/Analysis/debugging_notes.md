# Missing Base Constructor in Derived Initializer List

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Before entering the derived constructor body, C++ constructs the base subobject. Without an explicit initializer, it attempts to call Device(), which does not exist. Delegate with `Sensor(...): Device(mac), ...`.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
