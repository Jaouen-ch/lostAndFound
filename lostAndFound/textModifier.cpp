#include "textModifier.h"
#include "counterComponent.h"
#include "textComponent.h"

textModifier::textModifier(gameObject* _owner, gameObject* _targetObject)
    : component(_owner)
    , targetObject(_targetObject)
{
}

void textModifier::setTargetObject(gameObject* newTargetObject)
{
    targetObject = newTargetObject;
}

sf::String textModifier::getText()
{
    auto comp = targetObject->getComponent<textComponent>();
    if (comp != nullptr)
    {
        return comp->getText();
    }
}

void textModifier::setText(sf::String newText)
{
    auto comp = targetObject->getComponent<textComponent>();
    if (comp != nullptr)
    {
        comp->setText(newText);
    }
}
