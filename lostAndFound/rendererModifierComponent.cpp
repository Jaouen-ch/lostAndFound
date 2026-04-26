#include "rendererModifierComponent.h"

#include "rendererComponent.h"

rendererModifierComponent::rendererModifierComponent(gameObject* _owner, gameObject* _targetObject)
    : component(_owner)
    , targetObject(_targetObject)
{
}

void rendererModifierComponent::setTargetObject(gameObject* newTargetObject)
{
    targetObject = newTargetObject;
}

sf::Texture rendererModifierComponent::getTexture()
{
    auto comp = targetObject->getComponent<rendererComponent>();
    if (comp != nullptr)
    {
        return comp->getTexture();
    }
}

void rendererModifierComponent::setTexture(assetsHandler::texturesIndices newTexture)
{
    auto comp = targetObject->getComponent<rendererComponent>();
    if (comp != nullptr)
    {
        comp->setTexture(newTexture);
    }
}