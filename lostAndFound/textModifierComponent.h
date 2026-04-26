#pragma once

#include "gameObject.h"

class textModifierComponent : public component
{
private:
    gameObject* targetObject;

public:
    textModifierComponent(gameObject* _owner, gameObject* _targetObject);
    ~textModifierComponent() override = default;

    void setTargetObject(gameObject* newTargetObject);
    sf::String getText();
    void setText(sf::String newText);
};