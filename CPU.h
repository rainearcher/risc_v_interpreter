#ifndef CPU_CLASS
#define CPU_CLASS

#include <iostream>
#include <bitset>
#include <stdio.h>
#include<stdlib.h>
#include <string>
#include "immgen.h"
#include "controller.h"
#include "regfile.h"
#include "instruction.h"
#include "mux.h"
#include "alu.h"
#include "datamem.h"

using namespace std;

class CPU {
public:
	CPU(bitset<8> *instMem);
	unsigned long readPC();
	void Cycle();
	int read_a0();
	int read_a1();

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

	ALUController aluController;
	ALU alu;

	Mux aluSrcMux;
	Mux pcJumpMux;
	Mux memOrAluMux;
	Mux dataOrPcToRegMux;
	Mux branchEqualOrLtMux;

	DataMemory dataMemory;
};


#endif