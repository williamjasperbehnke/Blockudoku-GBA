#include "blockudoku/dpad_repeater.h"

#include "bn_keypad.h"

namespace blockudoku
{
    void dpad_repeater::reset()
    {
        _left_frames = 0;
        _right_frames = 0;
        _up_frames = 0;
        _down_frames = 0;
    }

    bool dpad_repeater::left()
    {
        return pressed_or_repeated(bn::keypad::left_held(), bn::keypad::left_pressed(), _left_frames);
    }

    bool dpad_repeater::right()
    {
        return pressed_or_repeated(bn::keypad::right_held(), bn::keypad::right_pressed(), _right_frames);
    }

    bool dpad_repeater::up()
    {
        return pressed_or_repeated(bn::keypad::up_held(), bn::keypad::up_pressed(), _up_frames);
    }

    bool dpad_repeater::down()
    {
        return pressed_or_repeated(bn::keypad::down_held(), bn::keypad::down_pressed(), _down_frames);
    }

    bool dpad_repeater::pressed_or_repeated(bool held, bool pressed, int& held_frames)
    {
        if(pressed)
        {
            held_frames = 1;
            return true;
        }

        if(! held)
        {
            held_frames = 0;
            return false;
        }

        ++held_frames;
        if(held_frames <= initial_delay_frames)
        {
            return false;
        }

        return (held_frames - initial_delay_frames) % repeat_interval_frames == 0;
    }
}
