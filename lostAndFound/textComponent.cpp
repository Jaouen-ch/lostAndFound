#include "textComponent.h"
#include "counterComponent.h"

textComponent::textComponent(gameObject* _owner, assetsHandler::fontsIndices font, sf::String _text, sf::Vector2f position, unsigned int characterSize)
    : component(_owner)
    , text(sf::Text(assetsHandler::getAssets()->getFont(font), _text, characterSize))
{
    positionDifference = position - owner->getPosition();
    text.setPosition(owner->getPosition() + positionDifference);
}

void textComponent::update(float deltaTime)
{
    text.setPosition(owner->getPosition() + positionDifference);
    auto comp = owner->getComponent<counterComponent>();
    if (comp != nullptr)
    {
        text.setString(std::to_string(comp->getCount()));
    }
}

void textComponent::draw(sf::RenderWindow& window)
{
    window.draw(text);
}

sf::String textComponent::getText()
{
    return text.getString();
}

void textComponent::setText(sf::String newText)
{
    text.setString(newText);
}

void textComponent::setPosition(sf::Vector2f newPosition)
{
    positionDifference = newPosition - owner->getPosition();
    text.setPosition(owner->getPosition() + positionDifference);
}