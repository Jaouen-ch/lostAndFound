#include "gameLoop.h"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    auto window = sf::RenderWindow(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Lost And Found", sf::Style::Default, sf::State::Windowed, settings);
    window.setVerticalSyncEnabled(true);

    auto currentGameLoop = gameLoop(window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            currentGameLoop.eventsHandler(window, event);
        }

        currentGameLoop.update();
        window.clear();
        currentGameLoop.draw(window);
        window.display();
    }
}