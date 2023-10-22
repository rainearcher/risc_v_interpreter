#include "regfile.h"

void RegisterFile::set_read_register_1(bitset<5> reg)
{
	read_reg_1 = reg.to_ulong();
}

void RegisterFile::set_read_register_2(bitset<5> reg)
{
	read_reg_2 = reg.to_ulong();
}

void RegisterFile::set_write_register(bitset<5> reg)
{
	write_reg = reg.to_ulong();
}