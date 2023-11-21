#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

class Game
{
public:
    Game();
    void run();
private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    
    void processEvents();
    void update(sf::Time* deltatime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    
    float moveX = 0;
    float moveY = 0;
    float speed = 0.5f;
    
};
