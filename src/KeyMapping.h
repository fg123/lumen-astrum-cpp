
#ifndef KEYMAPPING_H
#define KEYMAPPING_H

#include <SFML/Window/Keyboard.hpp>
#include <map>

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
enum class KeyMapping {
    MAP_LEFT, MAP_RIGHT, MAP_UP, MAP_DOWN
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
        map[KeyMapping::MAP_LEFT] = sf::Keyboard::Key::A;
        map[KeyMapping::MAP_RIGHT] = sf::Keyboard::Key::D;
        map[KeyMapping::MAP_UP] = sf::Keyboard::Key::W;
        map[KeyMapping::MAP_DOWN] = sf::Keyboard::Key::S;
    }
};

#endif
