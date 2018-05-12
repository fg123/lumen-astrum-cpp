//
// Created by Felix on 5/9/2018.
//

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "Layer.h"
#include "UpdateListener.h"
#include "Game.h"

class UserInterface : public UpdateListener, public Layer {
    std::vector<sf::Sprite> drawableComponents;
    Game &game;
    sf::View& view;
public:
    UserInterface(Game &, ResourceManager &, sf::View&);

    void draw(sf::RenderWindow &window) override;

    void update(sf::Int32 deltaTime) override;
};


#endif
