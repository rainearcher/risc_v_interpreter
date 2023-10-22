#include "instruction.h"

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