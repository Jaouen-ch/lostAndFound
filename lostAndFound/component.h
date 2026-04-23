#pragma once

#include "utils.h"

class gameObject;

class component
{
protected:
    gameObject* owner;

public:
    component(gameObject* _owner);
    virtual ~component() = default;

    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window);
};