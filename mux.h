#ifndef MUX
#define MUX
#include <bitset>
using namespace std;
class Mux {
public:
	void set_input_0(bitset<32> inp);
	void set_input_1(bitset<32> inp);

	void set_input_choice(bool choice);
	bitset<32> get_output();
private:
	bitset<32> input[2];
	int index;
};
#endif