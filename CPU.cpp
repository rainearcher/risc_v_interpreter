#include "CPU.h"

Instruction::Instruction(bitset<32> fetch)
{
	//cout << fetch << endl;
	bits = fetch;
	//cout << bits << endl;
}

CPU::CPU(bitset<8> *instMem) :
	instructionMemory(instMem), 
	curInstruction(bitset<32>()), 
	PC(0)
{
	for (int i = 0; i < 4096; i++) //copy instrMEM
	{
		dataMemory[i] = (0);
	}
}

void CPU::fetch_current_instruction() 
{
	bitset<32> instBits = get_current_instruction_bits();  //get 32 bit instruction
	curInstruction.bits = instBits;
}

bitset<32> CPU::get_current_instruction_bits() 
{
	return ((instructionMemory[PC + 3].to_ulong() << 24) + 
			(instructionMemory[PC + 2].to_ulong() << 16) + 
			(instructionMemory[PC + 1].to_ulong() << 8) + 
			(instructionMemory[PC + 0].to_ulong()));
}

void CPU::Cycle()
{
	decode_current_instruction();
	PC += 4;
}

void CPU::decode_current_instruction()
{
	//cout<<curr->instr<<endl;
	fetch_current_instruction();
}

unsigned long CPU::readPC()
{
	return PC;
}

// Add other functions here ... 