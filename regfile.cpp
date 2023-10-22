#include "regfile.h"
RegisterFile::RegisterFile()
{
	for (int i = 0; i < 32; i++)
	{
		registers[i] = 0;
	}
}
void RegisterFile::set_read_register_1(bitset<5> reg)
{
	readReg1 = reg.to_ulong();
}

void RegisterFile::set_read_register_2(bitset<5> reg)
{
	readReg2 = reg.to_ulong();
}

void RegisterFile::set_write_register(bitset<5> reg)
{
	writeReg = reg.to_ulong();
}

void RegisterFile::set_reg_write_flag(bool write)
{
	shouldWrite = write;
}

void RegisterFile::write_data(bitset<32> data)
{
	if (!shouldWrite)
		return;
	registers[writeReg] = data;
}

bitset<32> RegisterFile::get_data_1()
{
	return registers[readReg1];
}

bitset<32> RegisterFile::get_data_2()
{
    return registers[readReg2];
}

int RegisterFile::read_a0()
{

    return registers[10].to_ulong();
}

int RegisterFile::read_a1()
{
    return registers[11].to_ulong();
}
