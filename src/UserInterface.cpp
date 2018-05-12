//
// Created by Felix on 5/9/2018.
//

#include "UserInterface.h"
#include "Util.h"

UserInterface::UserInterface(Game &game, ResourceManager &resourceManager, sf::View &view) : view(view), game(game) {
    game.registerUpdateListener(*this);
    drawableComponents.push_back(resourceManager.getSpriteFromResourceName("topRight.png"));
    drawableComponents.push_back(resourceManager.getSpriteFromResourceName("bottomLeft.png"));
    drawableComponents.push_back(resourceManager.getSpriteFromResourceName("bottomRight.png"));
}

void UserInterface::draw(sf::RenderWindow &window) {
    window.setView(view);
    for (auto &sprite : drawableComponents) {
        window.draw(sprite);
    }
}

void UserInterface::update(sf::Int32 deltaTime) {
    using namespace Util::Sprite;
    alignSprite(game, drawableComponents[0], Align::TOP | Align::RIGHT);
    alignSprite(game, drawableComponents[1], Align::BOTTOM | Align::LEFT);
    alignSprite(game, drawableComponents[2], Align::BOTTOM | Align::RIGHT);
}
