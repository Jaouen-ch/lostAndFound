#pragma once

#include "assetsHandler.h"
#include "gameObject.h"

class textComponent : public component
{
private:
    sf::Text text;

    sf::Vector2f positionDifference = {0.0f, 0.0f};

public:
    textComponent(gameObject* _owner, assetsHandler::fontsIndices font, sf::String text, sf::Vector2f position, unsigned int characterSize);
    ~textComponent() override = default;

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

    sf::String getText();
    void setText(sf::String newText);
    void setPosition(sf::Vector2f newPosition);
};