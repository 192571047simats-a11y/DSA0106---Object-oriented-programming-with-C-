# Attempting to Instantiate an Incomplete Abstract Class

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
A class that has not implemented every inherited pure virtual function remains abstract. Implement all pure virtual methods in VideoPacket before creating an object.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
