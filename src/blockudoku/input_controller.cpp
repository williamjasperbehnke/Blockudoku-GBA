#include "blockudoku/input_controller.h"

#include "bn_keypad.h"

#include "blockudoku/game_state.h"

namespace blockudoku
{
    game_event input_controller::update(game_state& state)
    {
        if(bn::keypad::select_pressed())
        {
            return { game_event_type::reset, 0 };
        }

        if(state.game_over())
        {
            if(bn::keypad::start_pressed())
            {
                return { game_event_type::reset, 0 };
            }

            return { game_event_type::none, 0 };
        }

        if(bn::keypad::start_pressed())
        {
            return { game_event_type::hint_requested, 0 };
        }

        if(bn::keypad::b_pressed() && state.cycle_hint_move())
        {
            return { game_event_type::hint_cycled, 0 };
        }

        if(_dpad.left() && state.move_cursor(-1, 0))
        {
            return { game_event_type::cursor_moved, 0 };
        }

        if(_dpad.right() && state.move_cursor(1, 0))
        {
            return { game_event_type::cursor_moved, 0 };
        }

        if(bn::keypad::l_pressed() && state.cycle_slot(-1))
        {
            return { game_event_type::slot_changed, 0 };
        }

        if(bn::keypad::r_pressed() && state.cycle_slot(1))
        {
            return { game_event_type::slot_changed, 0 };
        }

        if(_dpad.up() && state.move_cursor(0, -1))
        {
            return { game_event_type::cursor_moved, 0 };
        }

        if(_dpad.down() && state.move_cursor(0, 1))
        {
            return { game_event_type::cursor_moved, 0 };
        }

        if(bn::keypad::a_pressed())
        {
            return state.try_place_selected();
        }

        return { game_event_type::none, 0 };
    }
}
