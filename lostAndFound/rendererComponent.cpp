#include "rendererComponent.h"

rendererComponent::rendererComponent(gameObject* _owner, assetsHandler::texturesIndices index)
    : component(_owner)
    , textureIndex(index)
    , texture(assetsHandler::getAssets()->getTexture(index))
    , sprite(sf::Sprite(texture))
{
    sprite.setPosition(owner->getPosition());
    sprite.setScale({owner->getSize().x / texture.getSize().x, owner->getSize().y / texture.getSize().y});
}

void rendererComponent::update(float deltaTime)
{
    sprite.setPosition(owner->getPosition());
    sprite.setScale({owner->getSize().x / texture.getSize().x, owner->getSize().y / texture.getSize().y});
}

void rendererComponent::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

assetsHandler::texturesIndices rendererComponent::getTexture()
{
    return textureIndex;
}

void rendererComponent::setTexture(assetsHandler::texturesIndices index)
{
    textureIndex = index;
    texture = assetsHandler::getAssets()->getTexture(index);
    sprite.setTexture(texture);
}