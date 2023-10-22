#include "datamem.h"
#include "utils.h"

void DataMemory::set_address(bitset<32> addr)
{
    address = addr.to_ulong();
}

void DataMemory::write_data(bitset<32> data)
{
    if (!shouldWrite)
        return;
    
    for (size_t i = 0; i < 8; i++)
    {
        dataMemory[address][i] = data[i];
        dataMemory[address + 1][i] = data[i + 8];
        dataMemory[address + 2][i] = data[i + 16];
        dataMemory[address + 3][i] = data[i + 24];
    }
}

void DataMemory::set_mem_read(bool read)
{
    shouldRead = read;
}

void DataMemory::set_mem_write(bool write)
{
    shouldWrite = write;
}

bitset<32> DataMemory::get_data()
{
    return fetch_4_bytes(dataMemory, address);
}
