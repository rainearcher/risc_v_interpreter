#include "CPU.h"

Instruction::Instruction(bitset<32> fetch)
{
	//cout << fetch << endl;
	bits = fetch;
	//cout << bits << endl;
}

bitset<5> Instruction::read_reg_1()
{
	bitset<5> reg;
	for (size_t i = 0; i < 5; i++)
	{
		reg[i] = bits[i + 15];
	}
	return reg;
}

bitset<5> Instruction::read_reg_2()
{
	bitset<5> reg;
	for (size_t i = 0; i < 5; i++)
	{
		reg[i] = bits[i + 20];
	}
	return reg;
}

bitset<5> Instruction::write_reg()
{
	bitset<5> reg;
	for (size_t i = 0; i < 5; i++)
	{
		reg[i] = bits[i + 7];
	}
	return reg;
}

bitset<7> Instruction::opcode()
{
	bitset<7> code;
	for (size_t i = 0; i < 7; i++)
	{
		code[i] = bits[i];
	}
	return code;
}

bitset<12> Instruction::i_type_imm()
{
	bitset<12> imm;
	for (size_t i = 0; i < 12; i++)
	{
		imm[i] = bits[i + 25];
	}
	return imm;
}

bitset<12> Instruction::s_type_imm()
{
	bitset<12> imm;
	for (size_t i = 0; i < 5; i++)
	{
		imm[i] = bits[i + 7];
	}
	for (size_t i = 5; i < 12; i++)
	{
		imm[i] = bits[i + 20];
	}
	return imm;
}

bitset<13> Instruction::b_type_imm()
{
	bitset<13> imm;
	imm[11] = bits[7];
	imm[12] = bits[31];
	for (size_t i = 1; i <= 4; i++)
	{
		imm[i] = bits[i + 7];
	}
	for (size_t i = 5; i <= 10; i++)
	{
		imm[i] = bits[i + 20];
	}
	return imm;
}

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
	controller.set_opcode(curInstruction.opcode());
	regFile.set_read_register_1(curInstruction.read_reg_1());
	regFile.set_read_register_2(curInstruction.read_reg_2());
	regFile.set_write_register(curInstruction.write_reg());

	immGen.set_input(curInstruction.bits);

}

unsigned long CPU::readPC()
{
	return PC;
}

void Controller::set_opcode(bitset<7> code)
{
	opcode = code;
}

void RegisterFile::set_read_register_1(bitset<5> reg)
{
	read_reg_1 = reg.to_ulong();
}

void RegisterFile::set_read_register_2(bitset<5> reg)
{
	read_reg_2 = reg.to_ulong();
}

void RegisterFile::set_write_register(bitset<5> reg)
{
	write_reg = reg.to_ulong();
}

void ImmGen::set_input(bitset<32> inp)
{
	Instruction instruction(inp);
	if (instruction.opcode() == I_TYPE)
	{
		auto imm = instruction.i_type_imm();
		if (!imm[11]) 
			immediate = imm.to_ulong();
		else
		{
			imm.flip();
			immediate = -(imm.to_ulong() + 1);
		}
	}
	else if (instruction.opcode() == S_TYPE)
	{
		auto imm = instruction.s_type_imm();
		if (!imm[11])
			immediate = imm.to_ulong();
		else
		{
			imm.flip();
			immediate = -(imm.to_ulong() + 1);
		}
	}
	else if (instruction.opcode() == B_TYPE)
	{
		auto imm = instruction.b_type_imm();
		if (!imm[12])
			immediate = imm.to_ulong();
		else
		{
			imm.flip();
			immediate = -(imm.to_ulong() + 1);
		}
	}
}