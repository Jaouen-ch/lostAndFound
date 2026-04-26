#include "clickableComponent.h"
#include "textComponent.h"
#include "counterModifierComponent.h"

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
        auto counterModifierComp = owner->getComponent<counterModifierComponent>();
        if (counterModifierComp != nullptr)
        {
            counterModifierComp->setCount(counterModifierComp->getCount() + 1);
        }
    }
    if (click)
    {
        auto textComp = owner->getComponent<textComponent>();
        if (textComp != nullptr)
        {
            textComp->setText("aaaaaa");
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