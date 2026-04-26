#include "gameLoop.h"

gameLoop::gameLoop(sf::RenderWindow& window)
{
    objects.reserve(10);
    objects.push_back(new gameObject({100, 300}, {120, 100}));
    objects[0]->addComponent(new rendererComponent(objects[0], assetsHandler::texturesIndices::king));

    objects.push_back(new gameObject({800, 300}, {100, 100}));
    objects[1]->addComponent(new rendererComponent(objects[1], assetsHandler::texturesIndices::miner));
}

gameLoop::~gameLoop()
{
    for (auto object : objects)
    {
        delete object;
        object = nullptr;
    }
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

    for (auto object : objects)
    {
        object->update(deltaTime);
    }
}

void gameLoop::draw(sf::RenderWindow& window)
{
    for (auto object : objects)
    {
        object->draw(window);
    }
}