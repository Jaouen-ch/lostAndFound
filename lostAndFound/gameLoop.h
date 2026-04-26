#pragma once

#include "gameObject.h"
#include "rendererComponent.h"
#include "colliderComponent.h"
#include "clickableComponent.h"
#include "textComponent.h"
#include "rendererModifierComponent.h"
#include "transformModifierComponent.h"

class gameLoop
{
private:
    sf::Clock clock;
    sf::Time now = clock.getElapsedTime();
    sf::Time lastTime;
    float deltaTime = 0.0f;

    std::vector<gameObject*> objects = {};

public:
    gameLoop(sf::RenderWindow& window);
    ~gameLoop();

    void eventsHandler(sf::RenderWindow& window, const std::optional<sf::Event>& event);
    void update();
    void draw(sf::RenderWindow& window);
};