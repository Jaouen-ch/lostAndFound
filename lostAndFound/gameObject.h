#pragma once

#include "utils.h"
#include "component.h"

class gameObject
{
private:
    sf::Vector2f position;
    sf::Vector2f size;
    std::vector<component*> components = {};

public:
    int button = 0;
    bool goodButton = false;

    gameObject(sf::Vector2f _position, sf::Vector2f _size, int _button);
    ~gameObject();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    void addComponent(component* newComponent);

    template <typename T> T* getComponent()
    {
    for (auto comp : components)
    {
        auto* downcastComponent = dynamic_cast<T*>(comp);
        if (downcastComponent != nullptr)
        {
            return downcastComponent;
        }
    }
    return nullptr;
    }

    template <typename T> bool hasComponent()
    {
    for (auto comp : components)
    {
        if (auto* downcastComponent = dynamic_cast<T*>(comp) != nullptr)
        {
            return true;
        }
    }
    return false;
    }

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getSize();
    void setSize(sf::Vector2f newSize);
};
