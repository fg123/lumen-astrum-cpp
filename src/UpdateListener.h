#ifndef UPDATE_LISTENER_H
#define UPDATE_LISTENER_H

#include <SFML/System.hpp>

class UpdateListener {
public:
    virtual void update(sf::Int32 deltaTime) = 0;
};

#endif