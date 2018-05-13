#ifndef RESOURCE_H
#define RESOURCE_H

#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <SFML/Graphics/Font.hpp>

class ResourceManager {
    std::map<std::string, std::vector<unsigned char>> internalResourceMap;
    std::vector<sf::Texture *> texturePool;

public:
    ResourceManager();

    ~ResourceManager();

    void loadResourceIntoImage(sf::Image &image, std::string resourceName);

    void loadResourceIntoTexture(sf::Texture &texture, std::string resourceName);

    unsigned char *getResourceAddress(std::string resourceName);

    size_t getResourceSize(std::string resourceName);

    sf::Sprite getSpriteFromResourceName(std::string resourceName);

    sf::Font getFontFromResourceName(std::string resourceName);
};


#endif
