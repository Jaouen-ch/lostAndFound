#pragma once

#include "utils.h"

class camera
{
private:
    sf::View view;

public:
    camera();
    ~camera() = default;

    void centerViewOnPosition(sf::Vector2f position);
    void setCamera(sf::RenderWindow* window);
};

