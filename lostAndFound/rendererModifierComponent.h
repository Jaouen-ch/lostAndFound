#pragma once

#include "gameObject.h"
#include "assetsHandler.h"

class rendererModifierComponent : public component
{
private:
    gameObject* targetObject;

public:
    rendererModifierComponent(gameObject* _owner, gameObject* _targetObject);
    ~rendererModifierComponent() override = default;

    void setTargetObject(gameObject* newTargetObject);
    assetsHandler::texturesIndices getTexture();
    void setTexture(assetsHandler::texturesIndices newTexture);
};