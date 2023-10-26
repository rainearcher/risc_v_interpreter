#include "CPU.h"
#include "utils.h"

CPU::CPU(bitset<8> *instMem) :
	instructionMemory(instMem), 
	curInstruction(bitset<32>()), 
	PC(0)
{
}


void CPU::fetch_current_instruction() 
{
	bitset<32> instBits = get_current_instruction_bits();  //get 32 bit instruction
	curInstruction.bits = instBits;
	curInstruction.bitString = instBits.to_string();
}

bitset<32> CPU::get_current_instruction_bits() 
{
	return fetch_4_bytes(instructionMemory, PC);
}

void CPU::Cycle()
{
	decode_current_instruction();
}

int CPU::read_a0()
{
    return regFile.read_a0();
}

int CPU::read_a1()
{
    return regFile.read_a1();
}

void CPU::decode_current_instruction()
{
	//cout<<curr->instr<<endl;
	fetch_current_instruction();

	controller.set_opcode(reader.opcode(curInstruction));
	regFile.set_read_register_1(reader.read_reg_1(curInstruction));
	regFile.set_read_register_2(reader.read_reg_2(curInstruction));
	regFile.set_write_register(reader.write_reg(curInstruction));
	regFile.set_reg_write_flag(controller.get_reg_write_flag());
	immGen.set_input(curInstruction.bits);

	aluSrcMux.set_input_0(regFile.get_data_2());
	aluSrcMux.set_input_1(immGen.get_immediate());
	aluSrcMux.set_input_choice(controller.get_alu_src_flag());
	aluController.set_instruction_input(curInstruction.bits);
	aluController.set_op(controller.get_alu_op());
	alu.set_input_1(regFile.get_data_1());
	alu.set_input_2(aluSrcMux.get_output());
	alu.set_operation(aluController.get_alu_control());

	branchEqualOrLtMux.set_input_choice(curInstruction.bits[14]);
	branchEqualOrLtMux.set_input_0(alu.get_zero_flag());
	branchEqualOrLtMux.set_input_1(!alu.get_zero_flag() & alu.get_result()[31]);
	pcBranchMux.set_input_choice(controller.get_branch_flag() & (branchEqualOrLtMux.get_output().to_ulong()));
	pcBranchMux.set_input_0(PC + 4);
	pcBranchMux.set_input_1(PC + immGen.get_immediate_int());
	pcBranchOrJumpMux.set_input_choice(controller.get_jump_flag());
	pcBranchOrJumpMux.set_input_0(pcBranchMux.get_output());
	pcBranchOrJumpMux.set_input_1(alu.get_result());


	dataMemory.set_mem_read(controller.get_mem_read_flag());
	dataMemory.set_mem_write(controller.get_mem_write_flag());
	dataMemory.set_address(alu.get_result());
	dataMemory.write_data(regFile.get_data_2());
	memOrAluMux.set_input_1(dataMemory.get_data());
	memOrAluMux.set_input_0(alu.get_result());
	memOrAluMux.set_input_choice(controller.get_mem_to_reg_flag());

	dataOrPcToRegMux.set_input_choice(controller.get_branch_flag());
	dataOrPcToRegMux.set_input_0(memOrAluMux.get_output());
	dataOrPcToRegMux.set_input_1(PC + 4);
	regFile.write_data(dataOrPcToRegMux.get_output());
	PC = pcBranchOrJumpMux.get_output().to_ulong();

	int reg1 = reader.read_reg_1(curInstruction).to_ulong();
	int reg2 = reader.read_reg_2(curInstruction).to_ulong();
	int writeReg = reader.write_reg(curInstruction).to_ulong();	
}

unsigned long CPU::readPC()
{
	return PC;
}

