#include <sstream>
#include "Map.h"

Map::Map(Game &game, ResourceManager &resourceManager, sf::View &view) : resourceManager(resourceManager), view(view) {
    unsigned char *mapRaw = resourceManager.getResourceAddress("map.bin");
    width = mapRaw[0];
    height = mapRaw[1];
    for (int y = 0; y < height; y++) {
        map.emplace_back();
        for (int x = 0; x < width; x++) {
            map[y].emplace_back(static_cast<MapTile::Type>(mapRaw[2 + ((y * width) + x)]));
        }
    }
    MapTile::populateSpriteList(resourceManager, spriteMap);
}

void Map::draw(sf::RenderWindow &window) {
    window.setView(view);
    int yOffset = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            yOffset = (x % 2) * 55;
            //sf::Sprite ground(*resourceManager.getSpriteFromResourceName());
            spriteMap[map[y][x].type].setPosition(x * 96, (y * 111) + yOffset);
            window.draw(spriteMap[map[y][x].type]);
        }
    }
}
