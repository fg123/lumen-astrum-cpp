
#ifndef KEYMAPPING_H
#define KEYMAPPING_H

#include <SFML/Window/Keyboard.hpp>
#include <map>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
enum class KeyMapping {
    CAMERA_LEFT, CAMERA_RIGHT, CAMERA_UP, CAMERA_DOWN, CONSOLE_ACTIVATE
};

class UserPreferences {
    std::map<KeyMapping, sf::Keyboard::Key> map;
public:
    UserPreferences() {
        // Deserialize Here
        generateDefaultMapping();
    }

    sf::Keyboard::Key getKey(KeyMapping mapping) {
        return map[mapping];
    }

    void generateDefaultMapping() {
        map[KeyMapping::CAMERA_LEFT] = sf::Keyboard::Key::A;
        map[KeyMapping::CAMERA_RIGHT] = sf::Keyboard::Key::D;
        map[KeyMapping::CAMERA_UP] = sf::Keyboard::Key::W;
        map[KeyMapping::CAMERA_DOWN] = sf::Keyboard::Key::S;
        map[KeyMapping::CONSOLE_ACTIVATE] = sf::Keyboard::Key::F1;
    }
};

#endif
