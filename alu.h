#include <bitset>
using namespace std;

string ALU_ADD_STR = "0010";
string ALU_SUB_STR = "0110";
string ALU_AND_STR = "0000";
string ALU_XOR_STR = "1110";
string ALU_SRA_STR = "1000";

enum AluOperation
{
	AluAdd,
	AluSub,
	AluXor,
	AluAnd,
	AluSra
};

class ALU {
public:
	void set_input_1(bitset<32> inp);
	void set_input_2(bitset<32> inp);

	void set_operation(bitset<4> op);

	bitset<32> get_result();
	bool get_zero_flag();
private:
	int calculate_result();
private:
	int operand1;
	int operand2;
	AluOperation operation;
};


class ALUController {
public:
	void set_instruction_input(bitset<32> instr);
	void set_op(bitset<2> op);

	bitset<4> get_alu_control();

private:
	bitset<4> check_r_type();
	bitset<4> check_i_type();
private:
	bool instrBit30;
	bitset<3> func3;
	bitset<2> aluOp;
};