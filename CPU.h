#include <iostream>
#include <bitset>
#include <stdio.h>
#include<stdlib.h>
#include <string>
#include "immgen.h"
#include "controller.h"
#include "regfile.h"
#include "instruction.h"
using namespace std;

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
	InstructionReader reader;
	bitset<8> *instructionMemory;
	unsigned long PC; //pc 
	RegisterFile regFile;
	Controller controller;
	ImmGen immGen;

};


