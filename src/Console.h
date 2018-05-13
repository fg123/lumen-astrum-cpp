//
// Created by Felix on 5/12/2018.
//

#ifndef CONSOLE_H
#define CONSOLE_H

#include "Layer.h"
#include "UserPreferences.h"
#include "ResourceManager.h"
#include "Game.h"

#define CONSOLE_WIDTH (WIN_WIDTH / 2)
#define CONSOLE_FONT_SIZE 14
#define MAX_CONSOLE_LINES 20
#define CONSOLE_HEIGHT (CONSOLE_FONT_SIZE * MAX_CONSOLE_LINES)

class Console : public Layer {
    class Entry {
    public:
        enum class Level {
            DEBUG, INFO, WARN, ERROR
        };
        Level level;
        std::string content;

        Entry(Level level, std::string &content) : level(level), content(content) {}
    };

    UserPreferences &userPreferences;
    bool activated = false;
    sf::View &view;
    Game &game;
    sf::Font consoleFont{};
    sf::RectangleShape backgroundShape{};
    sf::RectangleShape textboxShape{};
    std::vector<Entry> entries;
    int displayStartAt = 0;
    std::string inputBuffer = "";

    void runCommand(std::string input);

public:
    Console(Game &game, UserPreferences &userPreferences, ResourceManager &resourceManager, sf::View &view) :
            game(game),
            userPreferences(userPreferences),
            view(view),
            backgroundShape(sf::Vector2f(CONSOLE_WIDTH, CONSOLE_HEIGHT)),
            textboxShape(sf::Vector2f(CONSOLE_WIDTH, CONSOLE_FONT_SIZE)) {
        consoleFont = resourceManager.getFontFromResourceName("firaMono.ttf");
        backgroundShape.setFillColor(sf::Color(0, 0, 0, 125));
        textboxShape.setFillColor(sf::Color(0, 0, 0, 125));
        textboxShape.setOutlineColor(sf::Color::White);
        textboxShape.setOutlineThickness(2);
        textboxShape.setPosition(0, CONSOLE_HEIGHT);
    }

    bool onKeyDown(sf::Event::KeyEvent) override;

    bool onKeyUp(sf::Event::KeyEvent) override;

    bool onMouseWheeled(int value) override;

    bool onTextEntered(sf::Event::TextEvent) override;

    void draw(sf::RenderWindow &) override;

    void log(Entry::Level level, std::string &message) { entries.emplace_back(Entry(level, message)); }

    void debug(std::string message) { log(Entry::Level::DEBUG, message); }

    void info(std::string message) { log(Entry::Level::INFO, message); }

    void warn(std::string message) { log(Entry::Level::WARN, message); }

    void error(std::string message) { log(Entry::Level::ERROR, message); }

    void scrollToBottom();
};


#endif
