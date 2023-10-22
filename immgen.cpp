#include "immgen.h"
#include "const.h"
#include "instruction.h"

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