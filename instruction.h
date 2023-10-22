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
	bitset<5> read_reg_1(const Instruction &instr);
	bitset<5> read_reg_2(const Instruction &instr);
	bitset<5> write_reg(const Instruction &instr);
	bitset<7> opcode(const Instruction &instr);
	bitset<32> i_type_imm(const Instruction &instr);
	bitset<32> s_type_imm(const Instruction &instr);
	bitset<32> b_type_imm(const Instruction &instr);
};