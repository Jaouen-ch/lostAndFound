#include "colliderComponent.h"

colliderComponent::colliderComponent(gameObject* _owner, sf::Vector2f _position, sf::Vector2f _size)
    : component(_owner)
    , position(_position)
    , size(_size)
{
    positionDifference = position - owner->getPosition();
    sizeDifference = size - owner->getPosition();
}

void colliderComponent::update(float deltaTime)
{
    position = owner->getPosition() + positionDifference;
    size = owner->getSize() + sizeDifference;
}