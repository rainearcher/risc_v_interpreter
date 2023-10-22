#include "CPU.h"
#include "utils.h"

CPU::CPU(bitset<8> *instMem) :
	instructionMemory(instMem), 
	curInstruction(bitset<32>()), 
	PC(0)
{
}

void CPU::fetch_current_instruction() 
{
	bitset<32> instBits = get_current_instruction_bits();  //get 32 bit instruction
	curInstruction.bits = instBits;
}

bitset<32> CPU::get_current_instruction_bits() 
{
	return fetch_4_bytes(instructionMemory, PC);
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
	controller.set_opcode(reader.opcode(curInstruction));
	regFile.set_read_register_1(reader.read_reg_1(curInstruction));
	regFile.set_read_register_2(reader.read_reg_2(curInstruction));
	regFile.set_write_register(reader.write_reg(curInstruction));

	immGen.set_input(curInstruction.bits);

}

unsigned long CPU::readPC()
{
	return PC;
}

