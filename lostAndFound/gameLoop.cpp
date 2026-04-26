#include "gameLoop.h"

#include "transformModifierComponent.h"

gameLoop::gameLoop(sf::RenderWindow& window)
{
    objects.reserve(10);

    auto choiceTexte = new gameObject({50.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f - 10.0f}, {WINDOW_WIDTH - 100.0f, WINDOW_HEIGHT/3.0f});
    choiceTexte->addComponent(new rendererComponent(choiceTexte, assetsHandler::texturesIndices::textBackground));
    choiceTexte->addComponent(new textComponent(choiceTexte, assetsHandler::fontsIndices::righteous, "abcdefghijklmnopqrstuvwxyz", {choiceTexte->getPosition().x + 130.0f, choiceTexte->getPosition().y + 40.0f}, 20));
    objects.push_back(choiceTexte);

    auto choiceButton1 = new gameObject({190.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f + 150.0f}, {(WINDOW_WIDTH - 100.0f)/2 - 180.0f, WINDOW_HEIGHT/3.0f - 200.0f});
    choiceButton1->addComponent(new rendererComponent(choiceButton1, assetsHandler::texturesIndices::button));
    choiceButton1->addComponent(new textComponent(choiceButton1, assetsHandler::fontsIndices::righteous, "Button 1", {choiceButton1->getPosition().x + 20.0f, choiceButton1->getPosition().y + 20.0f}, 20));
    choiceButton1->addComponent(new clickableComponent(choiceButton1, &window));
    choiceButton1->addComponent(new rendererModifierComponent(choiceButton1, choiceButton1));
    choiceButton1->addComponent(new transformModifierComponent(choiceButton1, choiceButton1));
    objects.push_back(choiceButton1);

    auto choiceButton2 = new gameObject({190.0f + (WINDOW_WIDTH - 100.0f)/2 - 100.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f + 150.0f}, {(WINDOW_WIDTH - 100.0f)/2 - 180.0f, WINDOW_HEIGHT/3.0f - 200.0f});
    choiceButton2->addComponent(new rendererComponent(choiceButton2, assetsHandler::texturesIndices::button));
    choiceButton2->addComponent(new textComponent(choiceButton2, assetsHandler::fontsIndices::righteous, "Button 1", {choiceButton2->getPosition().x + 20.0f, choiceButton2->getPosition().y + 20.0f}, 20));
    choiceButton2->addComponent(new clickableComponent(choiceButton2, &window));
    choiceButton2->addComponent(new rendererModifierComponent(choiceButton2, choiceButton2));
    choiceButton2->addComponent(new transformModifierComponent(choiceButton2, choiceButton2));
    objects.push_back(choiceButton2);

}

gameLoop::~gameLoop()
{
    for (auto object : objects)
    {
        delete object;
        object = nullptr;
    }
}

void gameLoop::eventsHandler(sf::RenderWindow& window, const std::optional<sf::Event>& event)
{
    if (event->is<sf::Event::Closed>())
    {
        window.close();
    }
}

void gameLoop::update()
{
    lastTime = now;
    now = clock.getElapsedTime();
    deltaTime = now.asSeconds() - lastTime.asSeconds();

    for (auto object : objects)
    {
        object->update(deltaTime);
    }
}

void gameLoop::draw(sf::RenderWindow& window)
{
    for (auto object : objects)
    {
        object->draw(window);
    }
}