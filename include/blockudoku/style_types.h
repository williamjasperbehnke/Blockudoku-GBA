#ifndef BLOCKUDOKU_STYLE_TYPES_H
#define BLOCKUDOKU_STYLE_TYPES_H

namespace blockudoku
{

enum class block_style
{
    classic = 0,
    brick = 1,
    flat = 2,
    minecraft = 3,
    face = 4,
    count = 5
};

enum class palette_style
{
    classic = 0,
    sunrise = 1,
    mint = 2,
    ocean = 3,
    forest = 4,
    colorblind = 5,
    grayscale = 6,
    gameboy = 7,
    count = 8
};

[[nodiscard]] constexpr int to_index(block_style style)
{
    return static_cast<int>(style);
}

[[nodiscard]] constexpr int to_index(palette_style style)
{
    return static_cast<int>(style);
}

}

#endif
