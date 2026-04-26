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
        int nb = engineRandom::getRandomNumber(4, 9);
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
            if (!(firstClick && owner->button == 2))
            {
                rendererModifierComp->setTexture(static_cast<assetsHandler::texturesIndices>(nb));
            }
            if (rendererModifierComp->getTexture() != assetsHandler::texturesIndices::oldMan)
            {
                firstClick = false;
            }
        }
        if (transformModifierComp != nullptr && owner->button != 0)
        {
            if (firstClick && owner->button == 2)
            {
                transformModifierComp->setSize({0.0f, transformModifierComp->getSize().y});
            }
            else
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
        }
        if (textModifierComp != nullptr && buttonModifierComp != nullptr && owner->button != 0)
        {
            if (!(firstClick && owner->button == 2))
            {
                switch (nb)
                {
                case 4:
                    textModifierComp->setText(L"Messire, nous les mineurs risquons nos vies tout les\njours pour quelques pièces. Auriez-vous la grandeur de\nbaisser les taxes sur le fer ?");
                    if (owner->button == 1)
                    {
                        owner->goodButton = true;
                        buttonModifierComp->setGoodButton(false);
                    }
                    else
                    {
                        owner->goodButton = false;
                        buttonModifierComp->setGoodButton(true);
                    }
                    break;
                case 5:
                    textModifierComp->setText(L"Je me présente à vous aujourd'hui car mon village s'est\nfait attaquer par une bande de brigands. Pourriez-vous\ny envoyer des soldats pour les repousser ?");
                    if (owner->button == 1)
                    {
                        owner->goodButton = true;
                        buttonModifierComp->setGoodButton(false);
                    }
                    else
                    {
                        owner->goodButton = false;
                        buttonModifierComp->setGoodButton(true);
                    }
                    break;
                case 6:
                    textModifierComp->setText(L"Mon roi, la famine entrave le royaume. Pourriez-vous\norganiser des distributions de vivres pour soulager\nle peuple ?");
                    if (owner->button == 1)
                    {
                        owner->goodButton = true;
                        buttonModifierComp->setGoodButton(false);
                    }
                    else
                    {
                        owner->goodButton = false;
                        buttonModifierComp->setGoodButton(true);
                    }
                    break;
                case 7:
                    textModifierComp->setText(L"Bonjour messire. Laissez moi me présenter, je suis\nGontran, un simple marchand itinérant. J'aimerais\ndévelopper un commerce lucratif dans votre beau\nroyaume. Pourriez vous réinstaurer l'esclavage ?");
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
                    textModifierComp->setText(L"Enchanté de vous rencontrer messire. Je me présente\naujourd'hui devant vous pour vous demander de vider\nles cimetières de la ville car ils propagent les maladies.");
                    if (owner->button == 1)
                    {
                        owner->goodButton = true;
                        buttonModifierComp->setGoodButton(false);
                    }
                    else
                    {
                        owner->goodButton = false;
                        buttonModifierComp->setGoodButton(true);
                    }
                    break;
                case 9:
                    textModifierComp->setText(L"Sire, nous avons attrapé un voleur à l'étalage,\ndevons-nous le pendre en place publique ?");
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