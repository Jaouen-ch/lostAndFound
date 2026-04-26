#pragma once

#include "gameObject.h"

class transformModifierComponent : public component
{
private:
    gameObject* targetObject;

public:
    transformModifierComponent(gameObject* _owner, gameObject* _targetObject);
    ~transformModifierComponent() override = default;

    void setTargetObject(gameObject* newTargetObject);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getSize();
    void setSize(sf::Vector2f newSize);
};