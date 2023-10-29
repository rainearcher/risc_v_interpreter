# RISC V Interpreter
This is Project 1 for UCLA ECE M116C/CS M151B F23 quarter. The code implements the following RISC-V instructions:

ADD, SUB, ADDI, XOR, AND, SRA, LW, SW, BLT, JALR

## Compiling
```
g++ *cpp -o cpusim
```

## Running the program
```
./cpusim tests/<instruction-memory-file>
```
instruction-memory-file is a .txt file where each line is a single byte stored in little-endian format, represented as an unsigned decimal.

The program should output 
```
(a0,a1)
```
where a0,a1 are the standard return value registers.

## Included files
See tests/ directory for example input files.
See assembly/ directory for assembly representation of the input files.
See txt/ directory for annotated representations of the input files.

## Testing
```
python -m unittest
```
This will create a cpusim executable and test against the files in the tests/ directory.
