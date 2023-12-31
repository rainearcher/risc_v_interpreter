#ifndef CONSTS
#define CONSTS
#include <bitset>
using namespace std;

const bitset<7> R_TYPE("0110011");
const bitset<7> I_TYPE("0010011");
const bitset<7> S_TYPE("0100011");
const bitset<7> B_TYPE("1100011");
const bitset<7> LOAD_TYPE("0000011");
const bitset<7> STORE_TYPE("0100011");
const bitset<7> JALR_TYPE("1100111");
#endif