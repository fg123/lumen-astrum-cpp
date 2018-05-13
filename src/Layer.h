//
// Created by Felix on 5/12/2018.
//

#ifndef LAYER_H
#define LAYER_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

class LayerEvents {
    virtual bool onClickEvent(sf::Mouse::Button) = 0;

    virtual bool onKeyDown(sf::Event::KeyEvent) = 0;

    virtual bool onKeyUp(sf::Event::KeyEvent) = 0;

    virtual bool onTextEntered(sf::Event::TextEvent) = 0;

    virtual bool onMouseWheeled(int value) = 0;

    virtual void draw(sf::RenderWindow &) = 0;
};

class Layer : LayerEvents {
public:
    bool onClickEvent(sf::Mouse::Button) override { return false; }

    bool onKeyDown(sf::Event::KeyEvent) override { return false; }

    bool onKeyUp(sf::Event::KeyEvent) override { return false; }

    bool onMouseWheeled(int value) override { return false; }

    void draw(sf::RenderWindow &) override {}

    bool onTextEntered(sf::Event::TextEvent) override { return false; };
};

#endif
