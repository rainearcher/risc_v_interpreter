#include "controller.h"
#include "const.h"

Controller::Controller()
{
	reset_flags();
}

void Controller::reset_flags()
{
	opcode = bitset<7>();
	branch = false;
	memRead = false;
	memWrite = false;
	regWrite = false;
	aluSrc = false;
	aluOp = bitset<2>();
}

void Controller::set_opcode(bitset<7> code)
{
	reset_flags();
	opcode = code;
	if (opcode == R_TYPE)
	{
		regWrite = true;
		aluOp = bitset<2>("10");
	}
	else if (opcode == I_TYPE)
	{
		regWrite = true;
		aluSrc = true;
		aluOp = bitset<2>("10");
	}
	else if (opcode == LOAD_TYPE)
	{
		regWrite = true;
		aluSrc = true;
		memRead = true;
		memToReg = true;
		aluOp = bitset<2>("00");
	}
	else if (opcode == STORE_TYPE)
	{
		aluSrc = true;
		memWrite = true;
		aluOp = bitset<2>("00");
	}
	else if (opcode == B_TYPE)
	{
		branch = true;
		aluOp = bitset<2>("01");
	}
}
