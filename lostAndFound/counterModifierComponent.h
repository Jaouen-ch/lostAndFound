#pragma once

#include "gameObject.h"

class counterModifierComponent : public component
{
private:
    gameObject* targetObject;

public:
    counterModifierComponent(gameObject* _owner, gameObject* _targetObject);
    ~counterModifierComponent() override = default;

    void setTargetObject(gameObject* newTargetObject);
    int getCount();
    void setCount(int value);
};