#include "buttonModifierComponent.h"

buttonModifierComponent::buttonModifierComponent(gameObject* _owner, gameObject* _targetObject)
    : component(_owner)
    ,targetObject(_targetObject)
{
}

void buttonModifierComponent::setGoodButton(bool newGoodButton)
{
    targetObject->goodButton = newGoodButton;
}
