#include <bitset>
using namespace std;
class ALU {
public:
	void set_input_1(bitset<32> inp);
	void set_input_2(bitset<32> inp);

	void set_operation(bitset<4> op);

	bitset<32> get_result();
	bool get_zero_flag();
};


class ALUController {
public:
	void set_instruction_input(bitset<32> instr);
	void set_op(bitset<2> op);

	bitset<4> get_alu_control();
};