#pragma once

#include "gameObject.h"

class counterComponent : public component
{
private:
    int count = 0;

public:
    counterComponent(gameObject* _owner);
    ~counterComponent() override = default;

    int getCount();
    void setCount(int value);
};
