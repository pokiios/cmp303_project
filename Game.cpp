#include "Game.h"

Game::Game():
mWindow(sf::VideoMode(1280, 720), "CMP303 Coursework"), mPlayer()
{
        mPlayer.setRadius(20.f);
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
    sf::Clock clock;
    while(mWindow.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(&deltaTime);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (isPressed == true)
    {
        switch(key)
        {
        case sf::Keyboard::W:
            moveY = -1;
            break;
        case sf::Keyboard::S:
            moveY = 1;
            break;
        case sf::Keyboard::A:
            moveX = -1;
           break;
        case sf::Keyboard::D:
            moveX = 1;
            break;
        default:
            moveX = 0;
            moveY = 0;
            break;
        }
    }
    else
    {
        moveX = 0;
        moveY = 0;
    }
}


void Game::update(sf::Time* deltaTime)
{
    sf::Vector2f movement(0.f,0.f);
    movement.x += moveX*speed;
    movement.y += moveY*speed;

    mPlayer.move(movement*deltaTime->asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

int main()
{
    Game game;
    game.run();
}
