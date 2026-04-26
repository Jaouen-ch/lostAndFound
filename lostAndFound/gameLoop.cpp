#include "gameLoop.h"

gameLoop::gameLoop(sf::RenderWindow& window)
{
    objects.reserve(10);

    auto king = new gameObject({100, 300}, {120, 100}, 0);
    king->addComponent(new rendererComponent(king, assetsHandler::texturesIndices::king));
    objects.push_back(king);

    auto citizen = new gameObject({800, 300}, {100, 100}, 0);
    citizen->addComponent(new rendererComponent(citizen, assetsHandler::texturesIndices::miner));
    objects.push_back(citizen);

    auto choiceTexte = new gameObject({50.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f - 10.0f}, {WINDOW_WIDTH - 100.0f, WINDOW_HEIGHT/3.0f}, 0);
    choiceTexte->addComponent(new rendererComponent(choiceTexte, assetsHandler::texturesIndices::textBackground));
    choiceTexte->addComponent(new textComponent(choiceTexte, assetsHandler::fontsIndices::righteous, "abcdefghijklmnopqrstuvwxyz", {choiceTexte->getPosition().x + 130.0f, choiceTexte->getPosition().y + 40.0f}, 20));
    objects.push_back(choiceTexte);

    auto choiceButton1 = new gameObject({190.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f + 150.0f}, {(WINDOW_WIDTH - 100.0f)/2 - 180.0f, WINDOW_HEIGHT/3.0f - 200.0f}, 1);
    choiceButton1->addComponent(new rendererComponent(choiceButton1, assetsHandler::texturesIndices::button));
    choiceButton1->addComponent(new textComponent(choiceButton1, assetsHandler::fontsIndices::righteous, "Button 1", {choiceButton1->getPosition().x + 20.0f, choiceButton1->getPosition().y + 20.0f}, 20));
    choiceButton1->addComponent(new clickableComponent(choiceButton1, &window));
    choiceButton1->addComponent(new rendererModifierComponent(choiceButton1, citizen));
    choiceButton1->addComponent(new transformModifierComponent(choiceButton1, choiceButton1));
    objects.push_back(choiceButton1);

    auto choiceButton2 = new gameObject({190.0f + (WINDOW_WIDTH - 100.0f)/2 - 100.0f, WINDOW_HEIGHT - WINDOW_HEIGHT/3.0f + 150.0f}, {(WINDOW_WIDTH - 100.0f)/2 - 180.0f, WINDOW_HEIGHT/3.0f - 200.0f}, 2);
    choiceButton2->addComponent(new rendererComponent(choiceButton2, assetsHandler::texturesIndices::button));
    choiceButton2->addComponent(new textComponent(choiceButton2, assetsHandler::fontsIndices::righteous, "Button 1", {choiceButton2->getPosition().x + 20.0f, choiceButton2->getPosition().y + 20.0f}, 20));
    choiceButton2->addComponent(new clickableComponent(choiceButton2, &window));
    choiceButton2->addComponent(new rendererModifierComponent(choiceButton2, citizen));
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

    objects.push_back(gameObject({ 360, 20}, { 500, 15 }));
    objects[0].addComponent(new rendererComponent(&objects[0], assetsHandler::texturesIndices::blue));

    objects.push_back(gameObject({ 360, 40}, { 500, 15 }));
    objects[1].addComponent(new rendererComponent(&objects[1], assetsHandler::texturesIndices::red));
}

void gameLoop::eventsHandler(sf::RenderWindow& window, const std::optional<sf::Event>& event)
{
    if (event->is<sf::Event::Closed>())
    {
        window.close();
    }
    if (EventKarma->is<sf::Event::good>())
    {
        objects.push_back(gameObject({x-10,20}, 500,15}));
    }
    if (EventKarma->is<sf::Event::Bad>())
    {
        object.puch_back(gameObject({x+10, 20}, {500,15}));
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
