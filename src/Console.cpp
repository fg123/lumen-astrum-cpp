//
// Created by Felix on 5/12/2018.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Layer.h"
#include "Console.h"

bool Console::onKeyDown(sf::Event::KeyEvent event) {
    if (event.code == userPreferences.getKey(KeyMapping::CONSOLE_ACTIVATE)) {
        activated = !activated;
        return true;
    }
    return false;
}

bool Console::onKeyUp(sf::Event::KeyEvent) {
    return false;
}

bool Console::onMouseWheeled(int value) {
    if (activated) {
        displayStartAt += value;
        displayStartAt = std::max(0, std::min(displayStartAt, (int) (entries.size() - MAX_CONSOLE_LINES)));
        return true;
    }
    return false;
}

void Console::draw(sf::RenderWindow &window) {
    if (activated) {
        window.setView(view);
        window.draw(backgroundShape);
        sf::Text text;
        text.setFont(consoleFont);
        text.setCharacterSize(CONSOLE_FONT_SIZE);
        text.setFillColor(sf::Color::White);
        for (int i = 0; i < MAX_CONSOLE_LINES; i++) {
            text.setPosition(0, CONSOLE_FONT_SIZE * i);
            text.setString(entries[displayStartAt + i].content);
            window.draw(text);
        }
    }
}
