#include "gameLoop.h"

#include "textModifierComponent.h"

gameLoop::gameLoop(sf::RenderWindow& window)
{
    objects.reserve(10);

    auto background = new gameObject({0, 0}, {WINDOW_WIDTH, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f - 10.0f}, 0);
    background->addComponent(new rendererComponent(background, assetsHandler::texturesIndices::background));
    objects.push_back(background);

    auto king = new gameObject({440, 257}, {80, 80}, 0);
    king->addComponent(new rendererComponent(king, assetsHandler::texturesIndices::king));
    objects.push_back(king);

    auto citizen = new gameObject({1000, 384}, {80, 80}, 0);
    citizen->addComponent(new rendererComponent(citizen, assetsHandler::texturesIndices::miner));
    objects.push_back(citizen);

    auto choiceTexte = new gameObject({50.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f - 10.0f}, {WINDOW_WIDTH - 100.0f, WINDOW_HEIGHT/3.0f}, 0);
    choiceTexte->addComponent(new rendererComponent(choiceTexte, assetsHandler::texturesIndices::textBackground));
    choiceTexte->addComponent(new textComponent(choiceTexte, assetsHandler::fontsIndices::righteous, "abcdefghijklmnopqrstuvwxyz", {choiceTexte->getPosition().x + 130.0f, choiceTexte->getPosition().y + 40.0f}, 20));
    objects.push_back(choiceTexte);

    auto choiceButton1 = new gameObject({190.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f + 150.0f}, {(WINDOW_WIDTH - 100.0f)/2 - 180.0f, WINDOW_HEIGHT/3.0f - 200.0f}, 1);
    choiceButton1->addComponent(new rendererComponent(choiceButton1, assetsHandler::texturesIndices::button));
    choiceButton1->addComponent(new textComponent(choiceButton1, assetsHandler::fontsIndices::righteous, "Choice 1", {choiceButton1->getPosition().x + 20.0f, choiceButton1->getPosition().y + 20.0f}, 20));
    choiceButton1->addComponent(new clickableComponent(choiceButton1, &window));
    choiceButton1->addComponent(new rendererModifierComponent(choiceButton1, citizen));
    choiceButton1->addComponent(new textModifierComponent(choiceButton1, choiceTexte));
    objects.push_back(choiceButton1);

    auto choiceButton2 = new gameObject({190.0f + (WINDOW_WIDTH - 100.0f)/2 - 100.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f + 150.0f}, {(WINDOW_WIDTH - 100.0f)/2 - 180.0f, WINDOW_HEIGHT/3.0f - 200.0f}, 2);
    choiceButton2->addComponent(new rendererComponent(choiceButton2, assetsHandler::texturesIndices::button));
    choiceButton2->addComponent(new textComponent(choiceButton2, assetsHandler::fontsIndices::righteous, "Choice 1", {choiceButton2->getPosition().x + 20.0f, choiceButton2->getPosition().y + 20.0f}, 20));
    choiceButton2->addComponent(new clickableComponent(choiceButton2, &window));
    choiceButton2->addComponent(new rendererModifierComponent(choiceButton2, citizen));
    choiceButton2->addComponent(new textModifierComponent(choiceButton2, choiceTexte));
    objects.push_back(choiceButton2);

    auto red = new gameObject({ 50.0f, 20}, {WINDOW_WIDTH - 100.0f, 20.0f }, 0);
    red->addComponent(new rendererComponent(red, assetsHandler::texturesIndices::red));
    objects.push_back(red);

    auto blue = new gameObject({ 50.0f, 20}, {(WINDOW_WIDTH - 100.0f)/2, 20.0f }, 0);
    blue->addComponent(new rendererComponent(blue, assetsHandler::texturesIndices::blue));
    objects.push_back(blue);

    choiceButton1->addComponent(new buttonModifierComponent(choiceButton1, choiceButton2));
    choiceButton1->addComponent(new transformModifierComponent(choiceButton1, blue));
    choiceButton2->addComponent(new buttonModifierComponent(choiceButton2, choiceButton1));
    choiceButton2->addComponent(new transformModifierComponent(choiceButton2, blue));
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

    if (objects[7]->getSize().x == 0)
    {
        auto defeat = new gameObject({0.0f, 0.0f}, {0.0f, 0.0f}, 0);
        defeat->addComponent(new textComponent(defeat, assetsHandler::fontsIndices::righteous, "Defeat !", {WINDOW_WIDTH/2 - 100.0f, WINDOW_HEIGHT/2 - 15}, 30));
        objects.push_back(defeat);
    }
    else if (objects[7]->getSize().x == WINDOW_WIDTH - 100.0f)
    {
        auto victory = new gameObject({0.0f, 0.0f}, {0.0f, 0.0f}, 0);
        victory->addComponent(new textComponent(victory, assetsHandler::fontsIndices::righteous, "Victory !", {WINDOW_WIDTH/2 - 100.0f, WINDOW_HEIGHT/2 - 25}, 30));
        objects.push_back(victory);
    }
    else
    {
        for (auto object : objects)
        {
            object->update(deltaTime);
        }
    }
}

void gameLoop::draw(sf::RenderWindow& window)
{
    for (auto object : objects)
    {
        object->draw(window);
    }
}
