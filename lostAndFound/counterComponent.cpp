#include "counterComponent.h"

counterComponent::counterComponent(gameObject* _owner)
    : component(_owner)
{
}

int counterComponent::getCount()
{
    return count;
}

void counterComponent::setCount(int value)
{
    count = value;
}