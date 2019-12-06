#include "cpu6502.h";

cpu6502::cpu6502() {
    // Instruction table of 6502 CPU
    // Compiled by javidx9 and his wife
    using a = cpu6502;
    lookup = 
	{
		{ "BRK", &a::BRK, &a::IMM, 7 },{ "ORA", &a::ORA, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "ORA", &a::ORA, &a::ZP0, 3 },{ "ASL", &a::ASL, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PHP", &a::PHP, &a::IMP, 3 },{ "ORA", &a::ORA, &a::IMM, 2 },{ "ASL", &a::ASL, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ABS, 4 },{ "ASL", &a::ASL, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BPL", &a::BPL, &a::REL, 2 },{ "ORA", &a::ORA, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ZPX, 4 },{ "ASL", &a::ASL, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLC", &a::CLC, &a::IMP, 2 },{ "ORA", &a::ORA, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "ORA", &a::ORA, &a::ABX, 4 },{ "ASL", &a::ASL, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "JSR", &a::JSR, &a::ABS, 6 },{ "AND", &a::AND, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "BIT", &a::BIT, &a::ZP0, 3 },{ "AND", &a::AND, &a::ZP0, 3 },{ "ROL", &a::ROL, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PLP", &a::PLP, &a::IMP, 4 },{ "AND", &a::AND, &a::IMM, 2 },{ "ROL", &a::ROL, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "BIT", &a::BIT, &a::ABS, 4 },{ "AND", &a::AND, &a::ABS, 4 },{ "ROL", &a::ROL, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BMI", &a::BMI, &a::REL, 2 },{ "AND", &a::AND, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "AND", &a::AND, &a::ZPX, 4 },{ "ROL", &a::ROL, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SEC", &a::SEC, &a::IMP, 2 },{ "AND", &a::AND, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "AND", &a::AND, &a::ABX, 4 },{ "ROL", &a::ROL, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "RTI", &a::RTI, &a::IMP, 6 },{ "EOR", &a::EOR, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "EOR", &a::EOR, &a::ZP0, 3 },{ "LSR", &a::LSR, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PHA", &a::PHA, &a::IMP, 3 },{ "EOR", &a::EOR, &a::IMM, 2 },{ "LSR", &a::LSR, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "JMP", &a::JMP, &a::ABS, 3 },{ "EOR", &a::EOR, &a::ABS, 4 },{ "LSR", &a::LSR, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BVC", &a::BVC, &a::REL, 2 },{ "EOR", &a::EOR, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "EOR", &a::EOR, &a::ZPX, 4 },{ "LSR", &a::LSR, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLI", &a::CLI, &a::IMP, 2 },{ "EOR", &a::EOR, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "EOR", &a::EOR, &a::ABX, 4 },{ "LSR", &a::LSR, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "RTS", &a::RTS, &a::IMP, 6 },{ "ADC", &a::ADC, &a::IZX, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 3 },{ "ADC", &a::ADC, &a::ZP0, 3 },{ "ROR", &a::ROR, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "PLA", &a::PLA, &a::IMP, 4 },{ "ADC", &a::ADC, &a::IMM, 2 },{ "ROR", &a::ROR, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "JMP", &a::JMP, &a::IND, 5 },{ "ADC", &a::ADC, &a::ABS, 4 },{ "ROR", &a::ROR, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BVS", &a::BVS, &a::REL, 2 },{ "ADC", &a::ADC, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "ADC", &a::ADC, &a::ZPX, 4 },{ "ROR", &a::ROR, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SEI", &a::SEI, &a::IMP, 2 },{ "ADC", &a::ADC, &a::ABY, 4 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "ADC", &a::ADC, &a::ABX, 4 },{ "ROR", &a::ROR, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "???", &a::NOP, &a::IMP, 2 },{ "STA", &a::STA, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "STY", &a::STY, &a::ZP0, 3 },{ "STA", &a::STA, &a::ZP0, 3 },{ "STX", &a::STX, &a::ZP0, 3 },{ "???", &a::XXX, &a::IMP, 3 },{ "DEY", &a::DEY, &a::IMP, 2 },{ "???", &a::NOP, &a::IMP, 2 },{ "TXA", &a::TXA, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "STY", &a::STY, &a::ABS, 4 },{ "STA", &a::STA, &a::ABS, 4 },{ "STX", &a::STX, &a::ABS, 4 },{ "???", &a::XXX, &a::IMP, 4 },
		{ "BCC", &a::BCC, &a::REL, 2 },{ "STA", &a::STA, &a::IZY, 6 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "STY", &a::STY, &a::ZPX, 4 },{ "STA", &a::STA, &a::ZPX, 4 },{ "STX", &a::STX, &a::ZPY, 4 },{ "???", &a::XXX, &a::IMP, 4 },{ "TYA", &a::TYA, &a::IMP, 2 },{ "STA", &a::STA, &a::ABY, 5 },{ "TXS", &a::TXS, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 5 },{ "???", &a::NOP, &a::IMP, 5 },{ "STA", &a::STA, &a::ABX, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "???", &a::XXX, &a::IMP, 5 },
		{ "LDY", &a::LDY, &a::IMM, 2 },{ "LDA", &a::LDA, &a::IZX, 6 },{ "LDX", &a::LDX, &a::IMM, 2 },{ "???", &a::XXX, &a::IMP, 6 },{ "LDY", &a::LDY, &a::ZP0, 3 },{ "LDA", &a::LDA, &a::ZP0, 3 },{ "LDX", &a::LDX, &a::ZP0, 3 },{ "???", &a::XXX, &a::IMP, 3 },{ "TAY", &a::TAY, &a::IMP, 2 },{ "LDA", &a::LDA, &a::IMM, 2 },{ "TAX", &a::TAX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "LDY", &a::LDY, &a::ABS, 4 },{ "LDA", &a::LDA, &a::ABS, 4 },{ "LDX", &a::LDX, &a::ABS, 4 },{ "???", &a::XXX, &a::IMP, 4 },
		{ "BCS", &a::BCS, &a::REL, 2 },{ "LDA", &a::LDA, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 5 },{ "LDY", &a::LDY, &a::ZPX, 4 },{ "LDA", &a::LDA, &a::ZPX, 4 },{ "LDX", &a::LDX, &a::ZPY, 4 },{ "???", &a::XXX, &a::IMP, 4 },{ "CLV", &a::CLV, &a::IMP, 2 },{ "LDA", &a::LDA, &a::ABY, 4 },{ "TSX", &a::TSX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 4 },{ "LDY", &a::LDY, &a::ABX, 4 },{ "LDA", &a::LDA, &a::ABX, 4 },{ "LDX", &a::LDX, &a::ABY, 4 },{ "???", &a::XXX, &a::IMP, 4 },
		{ "CPY", &a::CPY, &a::IMM, 2 },{ "CMP", &a::CMP, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "CPY", &a::CPY, &a::ZP0, 3 },{ "CMP", &a::CMP, &a::ZP0, 3 },{ "DEC", &a::DEC, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "INY", &a::INY, &a::IMP, 2 },{ "CMP", &a::CMP, &a::IMM, 2 },{ "DEX", &a::DEX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 2 },{ "CPY", &a::CPY, &a::ABS, 4 },{ "CMP", &a::CMP, &a::ABS, 4 },{ "DEC", &a::DEC, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BNE", &a::BNE, &a::REL, 2 },{ "CMP", &a::CMP, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "CMP", &a::CMP, &a::ZPX, 4 },{ "DEC", &a::DEC, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "CLD", &a::CLD, &a::IMP, 2 },{ "CMP", &a::CMP, &a::ABY, 4 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "CMP", &a::CMP, &a::ABX, 4 },{ "DEC", &a::DEC, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
		{ "CPX", &a::CPX, &a::IMM, 2 },{ "SBC", &a::SBC, &a::IZX, 6 },{ "???", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "CPX", &a::CPX, &a::ZP0, 3 },{ "SBC", &a::SBC, &a::ZP0, 3 },{ "INC", &a::INC, &a::ZP0, 5 },{ "???", &a::XXX, &a::IMP, 5 },{ "INX", &a::INX, &a::IMP, 2 },{ "SBC", &a::SBC, &a::IMM, 2 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::SBC, &a::IMP, 2 },{ "CPX", &a::CPX, &a::ABS, 4 },{ "SBC", &a::SBC, &a::ABS, 4 },{ "INC", &a::INC, &a::ABS, 6 },{ "???", &a::XXX, &a::IMP, 6 },
		{ "BEQ", &a::BEQ, &a::REL, 2 },{ "SBC", &a::SBC, &a::IZY, 5 },{ "???", &a::XXX, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 8 },{ "???", &a::NOP, &a::IMP, 4 },{ "SBC", &a::SBC, &a::ZPX, 4 },{ "INC", &a::INC, &a::ZPX, 6 },{ "???", &a::XXX, &a::IMP, 6 },{ "SED", &a::SED, &a::IMP, 2 },{ "SBC", &a::SBC, &a::ABY, 4 },{ "NOP", &a::NOP, &a::IMP, 2 },{ "???", &a::XXX, &a::IMP, 7 },{ "???", &a::NOP, &a::IMP, 4 },{ "SBC", &a::SBC, &a::ABX, 4 },{ "INC", &a::INC, &a::ABX, 7 },{ "???", &a::XXX, &a::IMP, 7 },
	};
}

cpu6502::~cpu6502() {

}

uint8_t cpu6502::read(uint16_t addr) {
    return bus->read(addr, false);
}

void cpu6502::write(uint16_t addr, uint8_t data) {
    bus->write(addr, data);
}


// Inaccurate clock cycle implementation
void cpu6502::clock() {
    if(cycles == 0) {
        // Cycle begin
		// Read the code from the current PC location and increment it
		opcode = read(pc);
		pc++;

		// Read the cycles for the instruction
		cycles = lookup[opcode].cycles;

		// Call the methods associated with that instruction
		uint8_t additional_cycles1 = (this->*lookup[opcode].addrmode)();
		uint8_t additional_cycles2 = (this->*lookup[opcode].operate)();
		
		cycles += (additional_cycles1 & additional_cycles2);
    }

	cycles--;
}

void cpu6502::reset() {
	a = 0;
	x  = 0;
	y = 0;
	stack_ptr = 0xFD;
	status = 0x00 | U;

	addr_abs = 0xFFFC;								// Default 
	uint16_t low = read(addr_abs + 0);
	uint16_t high = read(addr_abs + 1);

	pc = (high << 8) | low;

	addr_rel = 0x0000;
	addr_abs = 0x0000;
	fetched = 0x00;

	cycles = 8;
}

// Maskable Interrupt
void cpu6502::irq() {
	if(getFlag(I) == 0) {
		// Interrupt occured
		// Write to stack current program counter
		write(0x0100 + stack_ptr, (pc >> 8) & 0x00FF);
		stack_ptr--;
		write(0x0100 + stack_ptr, pc & 0x00FF);
		stack_ptr--;

		setFlag(B, 0);
		setFlag(U, 1);
		setFlag(I, 1);
		write(0x0100 + stack_ptr, status);
		stack_ptr--;

		addr_abs = 0xFFFE;
		uint16_t low = read(addr_abs + 0);
		uint16_t high = read(addr_abs + 1);
		pc = (high << 8) | low;

		cycles = 7;
		
	}
}

// Non Maskable Interrupt
void cpu6502::nmi() {
	write(0x0100 + stack_ptr, (pc >> 8) & 0x00FF);
	stack_ptr--;
	write(0x0100 + stack_ptr, pc & 0x00FF);
	stack_ptr--;

	setFlag(B, 0);
	setFlag(U, 1);
	setFlag(I, 1);
	write(0x0100 + stack_ptr, status);
	stack_ptr--;

	addr_abs = 0xFFFA;
	uint16_t low = read(addr_abs + 0);
	uint16_t high = read(addr_abs + 1);
	pc = (high << 8) | low;

	cycles = 8;
}

void cpu6502::getFlag(FLAGS f) {
	return ((status & f) > 0) ? 1 : 0;
}

void cpu6502::setFlag(FLAGS f, bool val) {
	if(val)
		status |= f;
	else
		status &= ~f;
}

// Operations 

// Addressing Modes
// Used to refer to the address spaces that exist on our device (in this case RAM)
// Can be addressed in absolute or relative manners

uint8_t cpu6502::IMP() {								// Implied Return with fetching from A-reg
	fetched = a;
	return 0;
}

uint8_t cpu6502::IMM() {								// Immediate Return with PC increment
	addr_abs = pc++;
	return 0;
}

uint8_t cpu6502::ZP0() {								// Zero Page Addressing
	addr_abs = read(pc);
	pc++;
	addr_abs &= 0x00FF;
	return 0;
}

uint8_t cpu6502::ZPX() {								// Zero Page Addressing with X-reg offset
	addr_abs = (read(pc) + x);
	pc++;
	addr_abs &= 0x00FF;
	return 0;
}

uint8_t cpu6502::ZPY() {								// Zero Page Addressing with Y-reg offset
	addr_abs = (read(pc) + y);
	pc++;
	addr_abs &= 0x00FF;
	return 0;
}

uint8_t cpu6502::ABS() {								// Absolute Addressing
	uint16_t low = read(pc);
	pc++;
	uint16_t high = read(pc);
	pc++;

	addr_abs = (high << 8) | low;

	return 0;
}

uint8_t cpu6502::ABX() {								// Absolute Addressing X-reg offset
	uint16_t low = read(pc);
	pc++;
	uint16_t high = read(pc);
	pc++;

	addr_abs = (high << 8) | low;
	addr_abs += x;

	// Do we need an extra cpu cycle
	if((addr_abs & 0xFF00) != (high << 8))
		return 1;
	else 
		return 0;

}

uint8_t cpu6502::ABY() {								// Absolute Addressing Y-reg offset
	uint16_t low = read(pc);
	pc++;
	uint16_t high = read(pc);
	pc++;

	addr_abs = (high << 8) | low;
	addr_abs += y;

	// Do we need an extra cpu cycle
	if((addr_abs & 0xFF00) != (high << 8))
		return 1;
	else 
		return 0;

}

uint8_t cpu6502::IND() {								// Indirect Addressing
	uint16_t ptr_low = read(pc);
	pc++;
	uint16_t ptr_high = read(pc);
	pc++;

	uint16_t ptr = (ptr_high << 8) | ptr_low;

	// 6502 Bug xxFF-Page Increase
	if(ptr_low == 0x00FF) {
		addr_abs = (read(ptr & 0xFF00) << 8) | read(ptr + 0);
	}else {
		addr_abs = (read(ptr + 1 ) << 8) | read(ptr + 0);
	}
}

uint8_t cpu6502::IZX()
{
	uint16_t t = read(pc);
	pc++;

	uint16_t low = read((uint16_t)(t + (uint16_t)x) & 0x00FF);
	uint16_t high = read((uint16_t)(t + (uint16_t)x + 1) & 0x00FF);

	addr_abs = (high << 8) | low;
	
	return 0;
}

uint8_t cpu6502::IZY()
{
	uint16_t t = read(pc);
	pc++;

	uint16_t low = read(t & 0x00FF);
	uint16_t high = read((t + 1) & 0x00FF);

	addr_abs = (high << 8) | low;
	addr_abs += y;
	
	if ((addr_abs & 0xFF00) != (high << 8))
		return 1;
	else
		return 0;
}

uint8_t cpu6502::REL() {								// Relative Addressing mode
	addr_rel = read(pc);
	pc++;
	if (addr_rel & 0x80)
		addr_rel |= 0xFF00;
	return 0;
}

// Instructions

// We have the address now we need to fetch
uint8_t cpu6502::fetch() {
	if(!(lookup[opcode].addrmode == &cpu6502::IMP))
		fetched = read(addr_abs);
	return fetched;
}

// Bitwise AND
uint8_t cpu6502::AND() {
	fetch();
	a = a & fetched;
	setFlag(Z, a == 0x00);
	setFlag(N, a & 0x80);
	return 1;
}

// Branch
uint8_t cpu6502::BCS() {
	if(getFlag(C) == 1) {
		cycles++;
		addr_abs = pc + addr_rel;

		if((addr_abs & 0xFF00) != (pc & 0xFF00))
			cycles++;
		
		pc = addr_abs;
	}

	return 0;
}

// Clear Flags
uint8_t cpu6502::CLC() {
	setFlag(C, false);
	return 0;
}

uint8_t cpu6502::CLD() {
	setFlag(D, false);
	return 0;
}

uint8_t cpu6502::CLI()
{
	SetFlag(I, false);
	return 0;
}

uint8_t cpu6502::CLV()
{
	SetFlag(V, false);
	return 0;
}

// Addition (accounting for overflow)
uint8_t cpu6502::ADC() {
	fetch();
	uint16_t temp = (uint16_t)a + (uint16_t)fetched + (uint16_t)getFlag(C);
	setFlag(C, temp > 255);
	setFlag(Z, (temp & 0x00FF) == 0);
	setFlag(N, temp & 0x80);
	
	// Overflow calculation
	uint16_t a_xor_f = (uint16_t)a ^ (uint16_t)f;
	uint16_t a_xor_temp = (uint16_t)a ^ (uint16_t)temp;
	setFlag(V, ((~(a_xor_f) & a_xor_temp)) & 0x0000);

	a = temp & 0x00FF;
	return 1;
}

// Subtraction 
uint8_t cpu6502::SBC() {
	fetched();

	uint8_t value = ((uint8_t)fetched) ^ 0x00FF;
	uint16_t temp = (uint16_t)a + (uint16_t)value + (uint16_t)getFlag(C);
	setFlag(C, temp > 255);
	setFlag(Z, (temp & 0x00FF) == 0);
	setFlag(N, temp & 0x80);
	
	// Overflow calculation
	uint16_t a_xor_f = (uint16_t)a ^ (uint16_t)f;
	uint16_t a_xor_temp = (uint16_t)a ^ (uint16_t)temp;
	setFlag(V, ((~(a_xor_f) & a_xor_temp)) & 0x0000);

	a = temp & 0x00FF;
	return 1;
}


// Push A-reg to STACK
uint8_t cpu6502::PHA() {
	// 6502 stack pointer = 0x0100
	write(0x0100 + stack_ptr, a);
	stack_ptr--;
	return 0;
}

uint8_t cpu6502::PLA() {
	stack_ptr++;
	a = read(0x0100 + stack_ptr);
	setFlag(Z, a == 0x00);
	setFlag(N, a & 0x80);
	
	return 0;
}

uint8_t cpu6502::RTI()
{
	stkp++;
	status = read(0x0100 + stkp);
	status &= ~B;
	status &= ~U;

	stkp++;
	pc = (uint16_t)read(0x0100 + stkp);
	stkp++;
	pc |= (uint16_t)read(0x0100 + stkp) << 8;
	return 0;
}