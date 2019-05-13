#pragma once

struct input_state
{
    bool up_pressed;
    bool down_pressed;
    bool left_pressed;
    bool right_pressed;
    bool escape_pressed;
};

void read_input(input_state& input);