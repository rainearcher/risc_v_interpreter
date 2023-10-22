#include <bitset>
using namespace std;

class DataMemory {
public:
	void set_address(bitset<32> address);
	void write_data(bitset<32> data);

	void set_mem_read(bool read);
	void set_mem_write(bool write);
	
	bitset<32> get_data();
private:
	bitset<8> dataMemory[4096]; //data memory byte addressable in little endian fashion;
	unsigned long address;
	bool shouldRead;
	bool shouldWrite;
};