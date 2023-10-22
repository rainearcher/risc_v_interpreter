#ifndef CONTROLLER
#define CONTROLLER
#include <bitset>
using namespace std;

class Controller {
public:
	Controller();
	void set_opcode(bitset<7> opcode);

	bool get_branch_flag();
	bool get_mem_read_flag();
	bool get_mem_to_reg_flag();
	bitset<2> get_alu_op();
	bool get_mem_write_flag();
	bool get_alu_src_flag();
	bool get_reg_write_flag();
private:
	void reset_flags();
private:
	bitset<7> opcode;
	bool branch;
	bool memToReg;
	bool memRead;
	bool memWrite;
	bool regWrite;
	bool aluSrc;
	bitset<2> aluOp;
};

inline bool Controller::get_branch_flag()
{
    return branch;
}

inline bool Controller::get_mem_to_reg_flag()
{
	return memToReg;
}

inline bool Controller::get_mem_read_flag()
{
    return memRead;
}

inline bitset<2> Controller::get_alu_op()
{
    return aluOp;
}

inline bool Controller::get_mem_write_flag()
{
    return memWrite;
}

inline bool Controller::get_alu_src_flag()
{
    return aluSrc;
}

inline bool Controller::get_reg_write_flag()
{
    return regWrite;
}
#endif