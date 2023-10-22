#include "alu.h"
#include "instruction.h"

void ALU::set_input_1(bitset<32> inp)
{
    operand1 = static_cast<int>(inp.to_ulong());
}

void ALU::set_input_2(bitset<32> inp)
{
    operand2 = static_cast<int>(inp.to_ulong());
}

void ALU::set_operation(bitset<4> op)
{
    string opStr = op.to_string();
    if (opStr == ALU_ADD_STR)
        operation = AluAdd;
    else if (opStr == ALU_SUB_STR)
        operation = AluSub;
    else if (opStr == ALU_AND_STR)
        operation = AluAnd;
    else if (opStr == ALU_XOR_STR)
        operation = AluXor;
    else if (opStr == ALU_SRA_STR)
        operation = AluSra;
    else
        operation = AluAdd;
}

bitset<32> ALU::get_result()
{
    return bitset<32>(calculate_result());
}

bool ALU::get_zero_flag()
{
    return calculate_result() == 0;
}

int ALU::calculate_result()
{
    switch (operation)
    {
    case AluAdd:
        return operand1 + operand2;
    case AluSub:
        return operand1 - operand2;
    case AluXor:
        return operand1 ^ operand2;
    case AluAnd:
        return operand1 & operand2;
    case AluSra:
        return operand1 >> operand2;
    default:
        return operand1 + operand2;
    }
}

void ALUController::set_instruction_input(bitset<32> instr)
{
    instrBit30 = instr[30];
    func3 = InstructionReader::func3(instr);
}

void ALUController::set_op(bitset<2> op)
{
    aluOp = op;
}

bitset<4> ALUController::get_alu_control()
{
    if (aluOp.to_string() == "00")
        return bitset<4>(ALU_ADD_STR);
    else if (aluOp.to_string() == "01")
        return bitset<4>(ALU_SUB_STR);
    else if (aluOp.to_string() == "10")
        return check_r_type();
    else if (aluOp.to_string() == "11")
        return check_i_type();

    return bitset<4>();
}

bitset<4> ALUController::check_r_type()
{
    if (func3.to_string() == "000")
    {
        if (instrBit30 == 0)
            return bitset<4>(ALU_ADD_STR);
        else if (instrBit30 == 1)
            return bitset<4>(ALU_SUB_STR);
    }
    else if (func3.to_string() == "100")
        return bitset<4>(ALU_XOR_STR);
    else if (func3.to_string() == "101")
        return bitset<4>(ALU_SRA_STR);
    else if (func3.to_string() == "111")
        return bitset<4>(ALU_AND_STR);

    return bitset<4>();
}

bitset<4> ALUController::check_i_type()
{
    if (func3.to_string() == "000")
        return bitset<4>(ALU_ADD_STR);
    else if (func3.to_string() == "111")
        return bitset<4>(ALU_AND_STR);
    return bitset<4>();
}
