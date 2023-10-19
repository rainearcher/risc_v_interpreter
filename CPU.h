#include <iostream>
#include <bitset>
#include <stdio.h>
#include<stdlib.h>
#include <string>
using namespace std;


class Instruction {
public:
	bitset<32> bits;//instruction
	Instruction(bitset<32> fetch); // constructor

};

class CPU {
public:
	CPU(bitset<8> *instMem);
	unsigned long readPC();
	void Cycle();

private:
	void decode_current_instruction();
	void fetch_current_instruction();
	bitset<32> get_current_instruction_bits();

private:
	Instruction curInstruction;
	bitset<8> *instructionMemory;
	int dataMemory[4096]; //data memory byte addressable in little endian fashion;
	unsigned long PC; //pc 
};

// add other functions and objects here
