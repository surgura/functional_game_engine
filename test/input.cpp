#include "input.hpp"
#include "types.hpp"
#include <conio.h>

#include <iostream>

void read_input(input_state& input)
{
    input.escape_pressed = false;
    input.up_pressed = false;
    input.right_pressed = false;
    input.down_pressed = false;
    input.left_pressed = false;
    input.action_pressed = false;
	while (_kbhit()) {
		uint16_t read_char;
		read_char = _getwch();
        if (read_char == 27) { // escape
            input.escape_pressed = true;
        } else if (read_char == 224) { // special key
            read_char = _getwch();
            switch (read_char)
            {
                case 72:
                    input.up_pressed = true;
                break;
                case 77:
                    input.right_pressed = true;
                break;
                case 80:
                    input.down_pressed = true;
                break;
                case 75:
                    input.left_pressed = true;
                break;
            }
        } else if (read_char == 113) {
            input.action_pressed = true;
        } else {
            std::cout << (std::uint32_t)read_char << std::endl;
        }
	}
}