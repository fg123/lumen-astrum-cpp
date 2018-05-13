#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/System.hpp>
#include <SFML/Graphics/View.hpp>
#include "UpdateListener.h"
#include "UserPreferences.h"
#include "Game.h"
#include "Layer.h"

class Camera : public UpdateListener, public Layer {
    UserPreferences &userPreferences;
    sf::View &view;

    sf::Vector2f position;
    float zoomTransition = 0.0;
    float zoom = 1.0;

    bool leftKeyDown = false;
    bool rightKeyDown = false;
    bool upKeyDown = false;
    bool downKeyDown = false;
public:
    Camera(Game &, UserPreferences &, sf::View &);

    void update(sf::Int32 deltaTime) override;

    bool onKeyDown(sf::Event::KeyEvent) override;

    bool onKeyUp(sf::Event::KeyEvent) override;

    bool onMouseWheeled(int) override;
};

#endif
