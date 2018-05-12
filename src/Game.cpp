#include <iostream>
#include "Game.h"
#include "KeyMapping.h"

Game::Game(ResourceManager &resourceManager, sf::View &cameraView, sf::View &regularView) :
        resourceManager(resourceManager),
        cameraView(cameraView),
        regularView(regularView) {
    setWindowSize(sf::Vector2u(WIN_WIDTH, WIN_HEIGHT));
}

void Game::draw(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
    window.setView(regularView);
    for (auto i = layers.rbegin(); i != layers.rend(); ++i) {
        (*i)->draw(window);
    }
    window.display();
}

void Game::update(sf::Int32 deltaTime) {
    for (auto children: updateListeners) {
        children->update(deltaTime);
    }
}

void Game::addLayer(Layer &layer) {
    layers.push_front(&layer);
}

void Game::registerUpdateListener(UpdateListener &updateListener) {
    updateListeners.push_back(&updateListener);
}

void Game::setWindowSize(sf::Vector2u size) {
    windowSize = size;
    cameraView.setSize(windowSize.x, windowSize.y);
    regularView.setSize(windowSize.x, windowSize.y);
    regularView.setCenter((int) (windowSize.x / 2), (int) (windowSize.y / 2));
}

