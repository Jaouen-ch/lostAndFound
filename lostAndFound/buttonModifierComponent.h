#pragma once

#include "gameObject.h"

class buttonModifierComponent : public component
{
private:
    gameObject* targetObject;

public:
    buttonModifierComponent(gameObject* _owner, gameObject* _targetObject);
    ~buttonModifierComponent() override = default;

    void setGoodButton(bool newGoodButton);
};