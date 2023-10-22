#include <iostream>
#include <bitset>
#include <stdio.h>
#include<stdlib.h>
#include <string>
using namespace std;


class Instruction {
public:
	bitset<32> bits;//instruction
	Instruction(bitset<32> fetch); // constructor

};

class CPU {
public:
	CPU(bitset<8> *instMem);
	unsigned long readPC();
	void Cycle();

private:
	void decode_current_instruction();
	void fetch_current_instruction();
	bitset<32> get_current_instruction_bits();

private:
	Instruction curInstruction;
	bitset<8> *instructionMemory;
	unsigned long PC; //pc 
};

class RegisterFile {
public:
	void set_read_register_1(bitset<5> reg);
	void set_read_register_2(bitset<5> reg);

	void set_write_register(bitset<5> reg);

	void set_reg_write_flag(bool write);

	void write_data(bitset<32> data);

	bitset<32> get_data_1();
	bitset<32> get_data_2();	
};

class ALU {
public:
	void set_input_1(bitset<32> inp);
	void set_input_2(bitset<32> inp);

	void set_operation(bitset<4> op);

	bitset<32> get_result();
	bool get_zero_flag();
};

class Mux {
public:
	void set_input_0(bitset<32> inp);
	void set_input_1(bitset<32> inp);

	void set_input_choice(bool choice);
	bitset<32> get_output();
};

class ImmGen {
public:
	void set_input(bitset<32> inp);
	bitset<32> get_immediate();
};

class DataMemory {
public:
	void set_address(bitset<32> address);
	void write_data(bitset<32> data);

	void set_mem_read(bool read);
	void set_mem_write(bool write);
	
	bitset<32> get_data();
private:
	int dataMemory[4096]; //data memory byte addressable in little endian fashion;
};

class Controller {
public:
	void set_opcode(bitset<6> opcode);

	bool get_branch_flag();
	bool get_mem_read_flag();
	bitset<2> get_alu_op();
	bool get_mem_write_flag();
	bool get_alu_src_flag();
	bool get_reg_write_flag();
};

class ALUController {
public:
	void set_instruction_input(bitset<32> instr);
	void set_op(bitset<2> op);

	bitset<4> get_alu_control();
};