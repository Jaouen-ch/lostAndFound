#pragma once

#include "gameObject.h"

class textModifier : public component
{
private:
    gameObject* targetObject;

public:
    textModifier(gameObject* _owner, gameObject* _targetObject);
    ~textModifier() override = default;

    void setTargetObject(gameObject* newTargetObject);
    sf::String getText();
    void setText(sf::String newText);
};