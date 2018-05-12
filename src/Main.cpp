
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "ResourceManager.h"
#include "Game.h"
#include "Drawable.h"
#include "Camera.h"
#include "Map.h"
#include "UserInterface.h"

#define WIN_TITLE "Lumen Astrum"

int main() {
    ResourceManager resourceManager;
    UserPreferences userPreferences;
    sf::View cameraView(sf::FloatRect(0, 0, WIN_WIDTH, WIN_HEIGHT));
    sf::View regularView(sf::FloatRect(0, 0, WIN_WIDTH, WIN_HEIGHT));
    sf::View scalingView(sf::FloatRect(0, 0, WIN_WIDTH, WIN_HEIGHT));
    Game game(resourceManager, cameraView, regularView);

    Camera camera(game, userPreferences, cameraView);
    Map map(game, resourceManager, cameraView);
    UserInterface userInterface(game, resourceManager, regularView);

    Drawable backgroundDrawable(resourceManager, "background.png", scalingView);
    game.addLayer(backgroundDrawable);
    game.addLayer(map);
    game.addLayer(camera);
    game.addLayer(userInterface);

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), WIN_TITLE,
                            sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
    sf::Image icon;
    resourceManager.loadResourceIntoImage(icon, "icon.png");
    window.setIcon(128, 128, icon.getPixelsPtr());
    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    // TODO: Cleanup
                    return 0;
                case sf::Event::KeyPressed:
                    game.onKeyDown(event.key);
                    break;
                case sf::Event::KeyReleased:
                     game.onKeyUp(event.key);
                    break;
                case sf::Event::MouseWheelMoved:
                    game.onMouseWheeled(event.mouseWheel.delta);
                    break;
                case sf::Event::TextEntered:

                    break;
                case sf::Event::Resized:
                    game.setWindowSize(sf::Vector2u(event.size.width, event.size.height));
                    break;
                default:
                    break;

            }
        }
        game.update(deltaClock.restart().asMilliseconds());
        game.draw(window);
    }

    return 0;
}
