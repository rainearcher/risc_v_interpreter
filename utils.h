#include <bitset>
using namespace std;

bitset<32> fetch_4_bytes(bitset<8> *mem, unsigned long address)
{
	return ((mem[address + 3].to_ulong() << 24) + 
			(mem[address + 2].to_ulong() << 16) + 
			(mem[address + 1].to_ulong() << 8) + 
			(mem[address + 0].to_ulong()));
}