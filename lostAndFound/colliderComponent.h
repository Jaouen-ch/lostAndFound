#pragma once

#include "gameObject.h"

class colliderComponent final : public component
{
private:
    sf::Vector2f position;
    sf::Vector2f size;

    sf::Vector2f positionDifference = {0.0f, 0.0f};
    sf::Vector2f sizeDifference = {0.0f, 0.0f};

public:
    colliderComponent(gameObject* _owner, sf::Vector2f _position, sf::Vector2f _size);
    virtual ~colliderComponent() override = default;

    virtual void update(float deltaTime) override;
};