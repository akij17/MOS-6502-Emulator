#pragma once

class Bus;

class olc6502 {
    private:

    Bus *bus = nullptr;
    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t data);


    public:

    olc6502();
    ~olc6502();

    enum FLAGS {
        C = (1 << 0),
        Z = (1 << 1),
        I = (1 << 2),
        D = (1 << 3),
        B = (1 << 4),
        U = (1 << 5),
        V = (1 << 6),
        N = (1 << 7)
    };

    uint8_t a = 0x00;                           //Accumulator Register
    uint8_t x = 0x00;                           // X Register
    uint8_t y = 0x00;                           // Y Register
    uint8_t stack_pointer = 0x00;               // Stack Pointer
    uint8_t pc = 0x00                           // Program counter
    uint8_t status = 0x00;                      // Status Register

    void connectBus(Bus *n) {
        bus = n;
    }
};