#ifndef IMMGEN 
#define IMMGEN

#include <bitset>
using namespace std;

class ImmGen {
public:
	void set_input(bitset<32> inp);
	bitset<32> get_immediate();
	int get_immediate_int();
private:
	bitset<32> immediate;
	int immInt;
};

inline bitset<32> ImmGen::get_immediate()
{
	return immediate;
}

inline int ImmGen::get_immediate_int()
{
	return immInt;
}
#endif