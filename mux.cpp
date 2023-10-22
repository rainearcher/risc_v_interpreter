#include "mux.h"

void Mux::set_input_0(bitset<32> inp)
{
    input[0] = inp;
}

void Mux::set_input_1(bitset<32> inp)
{
    input[1] = inp;
}

void Mux::set_input_choice(bool choice)
{
    index = choice;
}

bitset<32> Mux::get_output()
{
    return input[index];
}
