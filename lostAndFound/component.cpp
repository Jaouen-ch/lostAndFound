#include "component.h"

component::component(gameObject* _owner)
    : owner(_owner)
{
}

void component::update(float deltaTime)
{
}

void component::draw(sf::RenderWindow& window)
{
}