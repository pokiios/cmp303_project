#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Window.h"

class Game
{
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
    Window* getWindow();

    sf::Time GetElapsed();
    void restartClock();
private:
    Window window;
    sf::CircleShape player;

    sf::Clock clock;
    sf::Time tElapsed;
};
