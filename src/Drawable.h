#ifndef BACKGROUND_DRAWABLE_H
#define BACKGROUND_DRAWABLE_H

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class Drawable : public Layer {
    sf::Texture texture;
    sf::Sprite sprite;
    sf::View &view;
public:
    Drawable(ResourceManager &manager, std::string resourceName, sf::View &view) : view(view) {
        manager.loadResourceIntoTexture(texture, resourceName);
        sprite.setTexture(texture);
    }

    void draw(sf::RenderWindow &window) override {
        window.setView(view);
        window.draw(sprite);
    }
};

#endif
