#include "transformModifierComponent.h"

transformModifierComponent::transformModifierComponent(gameObject* _owner, gameObject* _targetObject)
    : component(_owner)
    , targetObject(_targetObject)
{
}

void transformModifierComponent::setTargetObject(gameObject* newTargetObject)
{
    targetObject = newTargetObject;
}

void transformModifierComponent::setPosition(sf::Vector2f newPosition)
{
    targetObject->setPosition(newPosition);
}

sf::Vector2f transformModifierComponent::getPosition()
{
    return targetObject->getPosition();
}

void transformModifierComponent::setSize(sf::Vector2f newSize)
{
    targetObject->setSize(newSize);
}

sf::Vector2f transformModifierComponent::getSize()
{
    return targetObject->getSize();
}