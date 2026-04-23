#include "gameLoop.h"

gameLoop::gameLoop(sf::RenderWindow& window)
{
    objects.reserve(10);
    objects.push_back(gameObject({0, 0}, {100, 100}));
    objects[0].addComponent(new rendererComponent(&objects[0], assetsHandler::texturesIndices::defaultTexture));
}

void gameLoop::eventsHandler(sf::RenderWindow& window, const std::optional<sf::Event>& event)
{
    if (event->is<sf::Event::Closed>())
    {
        window.close();
    }
}

void gameLoop::update()
{
    lastTime = now;
    now = clock.getElapsedTime();
    deltaTime = now.asSeconds() - lastTime.asSeconds();

    for (auto& object : objects)
    {
        object.update(deltaTime);
    }
}

void gameLoop::draw(sf::RenderWindow& window)
{
    for (auto& object : objects)
    {
        object.draw(window);
    }
}