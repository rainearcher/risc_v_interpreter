#include "immgen.h"
#include "const.h"
#include "instruction.h"

void ImmGen::set_input(bitset<32> inp)
{
	Instruction instr(inp);
	InstructionReader reader;
	if (reader.opcode(instr) == I_TYPE || reader.opcode(instr) == LOAD_TYPE || reader.opcode(instr) == JALR_TYPE)
	{
		immediate = reader.i_type_imm(instr);
		immInt = static_cast<int>(immediate.to_ulong());
	}
	else if (reader.opcode(instr) == S_TYPE)
	{
		immediate = reader.s_type_imm(instr);
		immInt = static_cast<int>(immediate.to_ulong());
	}
	else if (reader.opcode(instr) == B_TYPE)
	{
		immediate = reader.b_type_imm(instr);
		immInt = static_cast<int>(immediate.to_ulong());
	}
}