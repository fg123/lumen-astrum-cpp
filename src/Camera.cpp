
#include "Camera.h"

Camera::Camera(Game &game, UserPreferences &userPreferences, sf::View &view) :
        userPreferences(userPreferences), view(view) {
    game.registerUpdateListener(*this);
}

void Camera::update(sf::Int32 deltaTime) {
    if (upKeyDown) position.y -= 5 * deltaTime;
    if (downKeyDown) position.y += 5 * deltaTime;
    if (leftKeyDown) position.x -= 5 * deltaTime;
    if (rightKeyDown) position.x += 5 * deltaTime;
    view.setCenter(position);
    view.zoom(zoomTransition + 1);
    zoom *= zoomTransition + 1;
    zoomTransition *= 0.97;
}

bool Camera::onKeyDown(sf::Event::KeyEvent key) {
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_LEFT)) leftKeyDown = true;
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_RIGHT)) rightKeyDown = true;
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_DOWN)) downKeyDown = true;
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_UP)) upKeyDown = true;
    return false;
}

bool Camera::onKeyUp(sf::Event::KeyEvent key) {
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_LEFT)) leftKeyDown = false;
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_RIGHT)) rightKeyDown = false;
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_DOWN)) downKeyDown = false;
    if (key.code == userPreferences.getKey(KeyMapping::CAMERA_UP)) upKeyDown = false;
    return false;
}

bool Camera::onMouseWheeled(int value) {
    zoomTransition = (value * 0.025f);
    return false;
}


