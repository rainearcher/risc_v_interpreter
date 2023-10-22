#include <bitset>
using namespace std;

class Instruction {
public:
	bitset<32> bits;//instruction
	Instruction(bitset<32> fetch); // constructor
};

class InstructionReader
{
public:
	static bitset<5> read_reg_1(const Instruction &instr);
	static bitset<5> read_reg_2(const Instruction &instr);
	static bitset<5> write_reg(const Instruction &instr);
	static bitset<7> opcode(const Instruction &instr);
	static bitset<32> i_type_imm(const Instruction &instr);
	static bitset<32> s_type_imm(const Instruction &instr);
	static bitset<32> b_type_imm(const Instruction &instr);
	static bitset<3> func3(const Instruction &instr);
};