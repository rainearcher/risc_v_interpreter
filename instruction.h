#include <bitset>
using namespace std;

class Instruction {
public:
	bitset<32> bits;//instruction
	Instruction(bitset<32> fetch); // constructor
	bitset<5> read_reg_1();
	bitset<5> read_reg_2();
	bitset<5> write_reg();
	bitset<7> opcode();
	bitset<12> i_type_imm();
	bitset<12> s_type_imm();
	bitset<13> b_type_imm();
};

