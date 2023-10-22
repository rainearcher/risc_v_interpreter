#include "instruction.h"

Instruction::Instruction(bitset<32> fetch)
{
	//cout << fetch << endl;
	bits = fetch;
	//cout << bits << endl;
}

bitset<5> InstructionReader::read_reg_1(const Instruction &instr)
{
	bitset<5> reg;
	for (size_t i = 0; i < 5; i++)
	{
		reg[i] = instr.bits[i + 15];
	}
	return reg;
}

bitset<5> InstructionReader::read_reg_2(const Instruction &instr)
{
	bitset<5> reg;
	for (size_t i = 0; i < 5; i++)
	{
		reg[i] = instr.bits[i + 20];
	}
	return reg;
}

bitset<5> InstructionReader::write_reg(const Instruction &instr)
{
	bitset<5> reg;
	for (size_t i = 0; i < 5; i++)
	{
		reg[i] = instr.bits[i + 7];
	}
	return reg;
}

bitset<7> InstructionReader::opcode(const Instruction &instr)
{
	bitset<7> code;
	for (size_t i = 0; i < 7; i++)
	{
		code[i] = instr.bits[i];
	}
	return code;
}

bitset<32> InstructionReader::i_type_imm(const Instruction &instr)
{
	bitset<32> imm;
	for (size_t i = 0; i < 12; i++)
	{
		imm[i] = instr.bits[i + 25];
	}

	bool sign = imm[11];
	for (size_t i = 12; i < 32; i++)
	{
		imm[i] = sign;
	}

	return imm;
}

bitset<32> InstructionReader::s_type_imm(const Instruction &instr)
{
	bitset<32> imm;
	for (size_t i = 0; i < 5; i++)
	{
		imm[i] = instr.bits[i + 7];
	}
	for (size_t i = 5; i < 12; i++)
	{
		imm[i] = instr.bits[i + 20];
	}
	bool sign = imm[11];
	for (size_t i = 12; i < 32; i++)
	{
		imm[i] = sign;
	}

	return imm;
}

bitset<32> InstructionReader::b_type_imm(const Instruction &instr)
{
	bitset<32> imm;
	for (size_t i = 1; i <= 4; i++)
	{
		imm[i] = instr.bits[i + 7];
	}
	for (size_t i = 5; i <= 10; i++)
	{
		imm[i] = instr.bits[i + 20];
	}
	
	imm[11] = instr.bits[7];
	bool sign = imm[12] = instr.bits[31];
	
	for (size_t i = 13; i < 32; i++)
	{
		imm[i] = sign;
	}

	return imm;
}

bitset<3> InstructionReader::func3(const Instruction &instr)
{
	bitset<3> func;
	for (size_t i = 0; i < 3; i++)
	{
		func[i] = instr.bits[i + 12];
	}
	return func;
}
