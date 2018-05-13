//
// Created by Felix on 5/12/2018.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include <sstream>
#include "Layer.h"
#include "Console.h"
#include "StateChange.h"

void Console::scrollToBottom() {
    displayStartAt = std::max(0, (int) (entries.size() - MAX_CONSOLE_LINES));
}

bool Console::onKeyDown(sf::Event::KeyEvent event) {
    if (event.code == userPreferences.getKey(KeyMapping::CONSOLE_ACTIVATE)) {
        activated = !activated;
        return true;
    }
    if (activated) {
        if (event.code == sf::Keyboard::Key::BackSpace && !inputBuffer.empty()) {
            inputBuffer.pop_back();
        } else if (event.code == sf::Keyboard::Key::Return && !inputBuffer.empty()) {
            debug(inputBuffer);
            runCommand(inputBuffer);
            scrollToBottom();
            inputBuffer.clear();
        }
        return true;
    }
    return false;
}

bool Console::onTextEntered(sf::Event::TextEvent event) {
    if (activated && std::isprint(event.unicode)) {
        inputBuffer += (char) event.unicode;
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
        window.draw(textboxShape);
        sf::Text text;
        text.setFont(consoleFont);
        text.setCharacterSize(CONSOLE_FONT_SIZE);
        text.setFillColor(sf::Color::White);
        for (int i = 0; i < MAX_CONSOLE_LINES && displayStartAt + i < entries.size(); i++) {
            text.setPosition(0, CONSOLE_FONT_SIZE * i);
            text.setString(entries[displayStartAt + i].content);
            window.draw(text);
        }
        text.setPosition(0, CONSOLE_HEIGHT);
        text.setString(inputBuffer);
        window.draw(text);
    }
}

void Console::runCommand(std::string input) {
    if (input.empty()) return;
    using namespace std;
    istringstream iss(input);
    vector<string> words;
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(words));
    if (words.empty()) return;
    if (words[0] == "chat") {
        if (words.size() == 1) {
            for (auto chatEntry: game.getState().chat) {
                debug(game.getPlayer(chatEntry.from).username + ": " + chatEntry.message);
            }
        } else {
            game.applyStateChange(std::unique_ptr<StateChange>(
                    new StateChanges::Chat(game, input.substr(input.find_first_of(" \t") + 1))
            ));
        }
    }
}
