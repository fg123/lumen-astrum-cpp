//
// Created by Felix on 5/9/2018.
//

#ifndef UTIL_H
#define UTIL_H

#include "Game.h"

namespace Util {
    namespace Sprite {
        enum Align : unsigned int {
            LEFT = 0,
            TOP = 0,
            RIGHT = 1u << 0u,
            BOTTOM = 1u << 1u,
            CENTER_HORIZONTAL = 1u << 2u,
            CENTER_VERTICAL = 1u << 3u,
            CENTER = CENTER_HORIZONTAL | CENTER_VERTICAL
        };

        void alignSprite(Game &game, sf::Sprite &sprite, unsigned int alignment) {
            float desiredX = 0, desiredY = 0;
            if (alignment & RIGHT) {
                desiredX = game.getWindowSize().x - sprite.getTexture()->getSize().x;
            }
            if (alignment & BOTTOM) {
                desiredY = game.getWindowSize().y - sprite.getTexture()->getSize().y;
            }
            if (alignment & CENTER_HORIZONTAL) {
                desiredX = (game.getWindowSize().x  - sprite.getTexture()->getSize().x) / 2;
            }
            if (alignment & CENTER_VERTICAL) {
                desiredY = (game.getWindowSize().y  - sprite.getTexture()->getSize().y) / 2;
            }
            sprite.setPosition(desiredX, desiredY);
        }
    };
};

#endif
