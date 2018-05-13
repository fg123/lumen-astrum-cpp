#ifndef MAP_H
#define MAP_H

#include "UpdateListener.h"
#include "ResourceManager.h"
#include "MapTile.h"
#include "Game.h"
#include "Layer.h"

class Map : public Layer {
    ResourceManager &resourceManager;
    std::vector<std::vector<MapTile>> map;
    int width;
    int height;
    std::map<MapTile::Type, sf::Sprite> spriteMap;
    sf::View &view;

public:
    Map(Game &, ResourceManager &, sf::View &);

    void draw(sf::RenderWindow &window) override;
};


#endif
