#ifndef BLOCKUDOKU_DPAD_REPEATER_H
#define BLOCKUDOKU_DPAD_REPEATER_H

namespace blockudoku
{

class dpad_repeater
{
public:
    void reset();

    [[nodiscard]] bool left();
    [[nodiscard]] bool right();
    [[nodiscard]] bool up();
    [[nodiscard]] bool down();

private:
    static constexpr int initial_delay_frames = 6;
    static constexpr int repeat_interval_frames = 4;

    int _left_frames = 0;
    int _right_frames = 0;
    int _up_frames = 0;
    int _down_frames = 0;

    [[nodiscard]] static bool pressed_or_repeated(bool held, bool pressed, int& held_frames);
};

}

#endif
