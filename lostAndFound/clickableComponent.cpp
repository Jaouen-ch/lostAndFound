#include "clickableComponent.h"

#include "buttonModifierComponent.h"
#include "utils.h"
#include "engineRandom.h"
#include "textComponent.h"
#include "counterModifierComponent.h"
#include "rendererModifierComponent.h"
#include "textModifierComponent.h"
#include "transformModifierComponent.h"

clickableComponent::clickableComponent(gameObject* _owner, sf::RenderWindow* _window, float _delay)
    : component(_owner)
    , window(_window)
    , delay(_delay)
{
    timer = delay;
}

clickableComponent::clickableComponent(gameObject* _owner, sf::RenderWindow* _window)
    : clickableComponent(_owner, _window, 0.0f)
{
}

void clickableComponent::update(float deltaTime)
{
    bool click = false;
    timer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !wasButtonLeftPressed && timer >= delay)
    {
        wasButtonLeftPressed = true;
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (mousePosition.x > owner->getPosition().x && mousePosition.x < owner->getPosition().x + owner->getSize().x &&
            mousePosition.y > owner->getPosition().y && mousePosition.y < owner->getPosition().y + owner->getSize().y)
        {
            timer = 0.0f;
            click = true;
        }
    }
    if (click)
    {
        int nb = engineRandom::getRandomNumber(4, 8);
        auto counterModifierComp = owner->getComponent<counterModifierComponent>();
        auto rendererModifierComp = owner->getComponent<rendererModifierComponent>();
        auto transformModifierComp = owner->getComponent<transformModifierComponent>();
        auto textModifierComp = owner->getComponent<textModifierComponent>();
        auto buttonModifierComp = owner->getComponent<buttonModifierComponent>();
        if (counterModifierComp != nullptr)
        {
            counterModifierComp->setCount(counterModifierComp->getCount() + 1);
        }
        if (rendererModifierComp != nullptr)
        {
            rendererModifierComp->setTexture(static_cast<assetsHandler::texturesIndices>(nb));
        }
        if (transformModifierComp != nullptr && owner->button != 0)
        {
            if (owner->goodButton)
            {
                transformModifierComp->setSize({transformModifierComp->getSize().x + (WINDOW_WIDTH - 100.0f)/10, transformModifierComp->getSize().y});
            }
            else
            {
                transformModifierComp->setSize({transformModifierComp->getSize().x - (WINDOW_WIDTH - 100.0f)/10, transformModifierComp->getSize().y});
            }
        }
        if (textModifierComp != nullptr && buttonModifierComp != nullptr && owner->button != 0)
        {
            switch (nb)
            {
            case 4:
                textModifierComp->setText("a");
                if (owner->button == 1)
                {
                    owner->goodButton = false;
                    buttonModifierComp->setGoodButton(true);
                }
                else
                {
                    owner->goodButton = true;
                    buttonModifierComp->setGoodButton(false);
                }
                break;
            case 5:
                textModifierComp->setText("b");
                if (owner->button == 1)
                {
                    owner->goodButton = false;
                    buttonModifierComp->setGoodButton(true);
                }
                else
                {
                    owner->goodButton = true;
                    buttonModifierComp->setGoodButton(false);
                }
                break;
            case 6:
                textModifierComp->setText("c");
                if (owner->button == 1)
                {
                    owner->goodButton = false;
                    buttonModifierComp->setGoodButton(true);
                }
                else
                {
                    owner->goodButton = true;
                    buttonModifierComp->setGoodButton(false);
                }
                break;
            case 7:
                textModifierComp->setText("d");
                if (owner->button == 1)
                {
                    owner->goodButton = false;
                    buttonModifierComp->setGoodButton(true);
                }
                else
                {
                    owner->goodButton = true;
                    buttonModifierComp->setGoodButton(false);
                }
                break;
            case 8:
                textModifierComp->setText("e");
                if (owner->button == 1)
                {
                    owner->goodButton = false;
                    buttonModifierComp->setGoodButton(true);
                }
                else
                {
                    owner->goodButton = true;
                    buttonModifierComp->setGoodButton(false);
                }
                break;
            }
        }
    }
    if (wasButtonLeftPressed && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        wasButtonLeftPressed = false;
    }
}

void clickableComponent::setWindow(sf::RenderWindow* newWindow)
{
    window = newWindow;
}

void clickableComponent::setDelay(float newDelay)
{
    delay = newDelay;
}