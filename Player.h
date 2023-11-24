#pragma once
#include <SFML/System/Vector2.hpp>

class Player
{
public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity();
private:
    sf::Vector2f mVelocity;
};
