#ifndef GAME_H
#define GAME_H

#include "UpdateListener.h"
#include "ResourceManager.h"
#include "Layer.h"
#include "State.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <deque>

class Game : public UpdateListener, public LayerEvents {
    ResourceManager &resourceManager;
    sf::View &regularView;
    sf::View &cameraView;
    // In order is top to bottom
    std::deque<Layer *> layers;
    std::vector<UpdateListener *> updateListeners;
    sf::Vector2u windowSize;
    State gameState;
    Side mySide = Side::RED;

public:
    Game(ResourceManager &, sf::View &, sf::View &);

    void draw(sf::RenderWindow &) override;

    void update(sf::Int32) override;

    void pushLayer(Layer &);

    void registerUpdateListener(UpdateListener &updateListener);

    void setWindowSize(sf::Vector2u size);

    void applyStateChange(std::unique_ptr<StateChange> stateChange);

    sf::Vector2u getWindowSize() { return windowSize; }

    State &getState() { return gameState; }

    Side getSide() { return mySide; }

    Side getOpponentSide() { return mySide == Side::RED ? Side::BLUE : Side::RED; }

    Player &me() {
        return getPlayer(getSide());
    }

    Player &opponent() {
        return getPlayer(getOpponentSide());
    }

    std::time_t getTimestamp() {
        return time(0) - gameState.startTime;
    }

    Player &getPlayer(Side side) {
        return side == Side::RED ? gameState.redPlayer : gameState.bluePlayer;
    }

    bool onClickEvent(sf::Mouse::Button button) override {
        for (auto layer : layers) {
            if (layer->onClickEvent(button)) return true;
        }
    }

    bool onKeyDown(sf::Event::KeyEvent event) override {
        for (auto layer : layers) {
            if (layer->onKeyDown(event)) return true;
        }
    }

    bool onKeyUp(sf::Event::KeyEvent event) override {
        for (auto layer : layers) {
            if (layer->onKeyUp(event)) return true;
        }
    }

    bool onMouseWheeled(int value) override {
        for (auto layer : layers) {
            if (layer->onMouseWheeled(value)) return true;
        }
    }

    bool onTextEntered(sf::Event::TextEvent event) override {
        for (auto layer : layers) {
            if (layer->onTextEntered(event)) return true;
        }
    }
};

#endif