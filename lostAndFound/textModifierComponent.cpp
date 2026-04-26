#include "textModifierComponent.h"
#include "counterComponent.h"
#include "textComponent.h"

textModifierComponent::textModifierComponent(gameObject* _owner, gameObject* _targetObject)
    : component(_owner)
    , targetObject(_targetObject)
{
}

void textModifierComponent::setTargetObject(gameObject* newTargetObject)
{
    targetObject = newTargetObject;
}

sf::String textModifierComponent::getText()
{
    auto comp = targetObject->getComponent<textComponent>();
    if (comp != nullptr)
    {
        return comp->getText();
    }
}

void textModifierComponent::setText(sf::String newText)
{
    auto comp = targetObject->getComponent<textComponent>();
    if (comp != nullptr)
    {
        comp->setText(newText);
    }
}
