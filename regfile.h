#include <bitset>
using namespace std;

class RegisterFile {
public:
	void set_read_register_1(bitset<5> reg);
	void set_read_register_2(bitset<5> reg);

	void set_write_register(bitset<5> reg);

	void set_reg_write_flag(bool write);

	void write_data(bitset<32> data);

	bitset<32> get_data_1();
	bitset<32> get_data_2();	
private:
	bitset<32> registers[32];
	int read_reg_1;
	int read_reg_2;
	int write_reg;
};