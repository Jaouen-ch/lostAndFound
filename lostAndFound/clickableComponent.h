#pragma once

#include "gameObject.h"

class clickableComponent : public component
{
private:
    sf::RenderWindow* window;
    float delay = 0.0f;
    float timer = 0.0f;
    bool wasButtonLeftPressed = false;

public:
    clickableComponent(gameObject* _owner, sf::RenderWindow* _window, float _delay);
    clickableComponent(gameObject* _owner, sf::RenderWindow* _window);
    ~clickableComponent() override = default;

    void update(float deltaTime) override;

    void setWindow(sf::RenderWindow* newWindow);
    void setDelay(float newDelay);
};
