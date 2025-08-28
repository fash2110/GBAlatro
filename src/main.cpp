#include "bn_core.h"
#include "bn_display.h"
#include "bn_sprite_text_generator.h"
#include "common_info.h"
#include "common_variable_8x8_sprite_font.h"

namespace{
    constexpr bn::fixed text_y_inc = 14;
    constexpr bn::fixed text_y_limit = (bn::display::height() / 2) - text_y_inc;

    void writeText(bn::sprite_text_generator& text_generator){

        static bn::vector<bn::sprite_ptr, 32> text_sprites;
        text_sprites.clear();
        text_generator.generate(0, -text_y_limit, "GBAlatro", text_sprites);
        text_generator.generate(0, -text_y_limit+20, "Que pija", text_sprites);
        bn::core::update();
    }
}
    int main()
    {   
        bn::core::init();
        bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
        text_generator.set_center_alignment();
        

        while(true)
        {
            writeText(text_generator);
            bn::core::update();
        }
    }