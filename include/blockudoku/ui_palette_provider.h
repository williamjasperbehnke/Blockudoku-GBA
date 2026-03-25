#ifndef BLOCKUDOKU_UI_PALETTE_PROVIDER_H
#define BLOCKUDOKU_UI_PALETTE_PROVIDER_H

#include "blockudoku/style_types.h"

namespace bn
{
    class bg_palette_item;
    class bg_palette_ptr;
    class sprite_palette_item;
}

namespace blockudoku::ui_palette_provider
{

[[nodiscard]] const bn::bg_palette_item& background_palette_item(palette_style style);
[[nodiscard]] bn::bg_palette_ptr create_background_palette(palette_style style);
[[nodiscard]] const bn::sprite_palette_item& text_palette_item(palette_style style);
[[nodiscard]] const bn::sprite_palette_item& accent_palette_item(palette_style style);

}

#endif
