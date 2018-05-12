#ifndef MAPTILE_H
#define MAPTILE_H

struct MapTile {
    enum class Type : int {
        EMPTY = 0,
        DEFAULT_TILE,
        BRUSH_TILE,
        MINERAL_TILE,
        BIG_MINERAL_TILE,
        ROCK,
        HIGH_TILE,
        LOW_TILE
    };
    Type type;

    explicit MapTile(Type type) : type(type) {};

    static void populateSpriteList(ResourceManager &resourceManager, std::map<Type, sf::Sprite> &mapToPopulate) {
        mapToPopulate[MapTile::Type::EMPTY] = sf::Sprite();
        mapToPopulate[MapTile::Type::DEFAULT_TILE] = resourceManager.getSpriteFromResourceName("defaultTile.png");
        mapToPopulate[MapTile::Type::BRUSH_TILE] = resourceManager.getSpriteFromResourceName("brushTile.png");
        mapToPopulate[MapTile::Type::MINERAL_TILE] = resourceManager.getSpriteFromResourceName("mineralTile.png");
        mapToPopulate[MapTile::Type::BIG_MINERAL_TILE] = resourceManager.getSpriteFromResourceName(
                "bigMineralTile.png");
        mapToPopulate[MapTile::Type::ROCK] = resourceManager.getSpriteFromResourceName("rockTile.png");
        mapToPopulate[MapTile::Type::HIGH_TILE] = resourceManager.getSpriteFromResourceName("highTile.png");
        mapToPopulate[MapTile::Type::LOW_TILE] = resourceManager.getSpriteFromResourceName("lowTile.png");
    }
};

#endif
