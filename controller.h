#include <bitset>
using namespace std;

class Controller {
public:
	void set_opcode(bitset<7> opcode);

	bool get_branch_flag();
	bool get_mem_read_flag();
	bitset<2> get_alu_op();
	bool get_mem_write_flag();
	bool get_alu_src_flag();
	bool get_reg_write_flag();
private:
	bitset<7> opcode;
};