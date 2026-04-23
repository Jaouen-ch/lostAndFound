#include "camera.h"

camera::camera()
{
    view = sf::View(sf::FloatRect({ 0, 0 }, { WINDOW_WIDTH, WINDOW_HEIGHT }));
}

void camera::centerViewOnPosition(sf::Vector2f position)
{
    view.setCenter(position);
}

void camera::setCamera(sf::RenderWindow* window)
{
    window->setView(view);
}