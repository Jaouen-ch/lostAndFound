#include "counterModifierComponent.h"

#include "counterComponent.h"

counterModifierComponent::counterModifierComponent(gameObject* _owner, gameObject* _targetObject)
    : component(_owner)
    , targetObject(_targetObject)
{
}

void counterModifierComponent::setTargetObject(gameObject* newTargetObject)
{
    targetObject = newTargetObject;
}

int counterModifierComponent::getCount()
{
    auto comp = targetObject->getComponent<counterComponent>();
    if (comp != nullptr)
    {
        return comp->getCount();
    }
}

void counterModifierComponent::setCount(int value)
{
    auto comp = targetObject->getComponent<counterComponent>();
    if (comp != nullptr)
    {
        comp->setCount(value);
    }
}
