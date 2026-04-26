#pragma once

#include "assetsHandler.h"
#include "gameObject.h"

class rendererComponent final : public component
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    rendererComponent(gameObject* _owner, assetsHandler::texturesIndices index);
    ~rendererComponent() override = default;

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

    sf::Texture getTexture();
    void setTexture(assetsHandler::texturesIndices index);
};
