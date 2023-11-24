#include "Game.h"

Game::Game() : window("CMP303 Coursework", sf::Vector2u(1280, 720))
{
    // Setting up Class Members
    player.setRadius(20.f);
    player.setPosition(window.GetWindowSize().x/2, window.GetWindowSize().y/2);
    player.setFillColor(sf::Color::Cyan);
}

Game::~Game()
{
    
}

void Game::update()
{
    window.update(); // Update Window Events
    window.Draw(player);
    window.endDraw(); // Display
}

void Game::render()
{
}

void Game::handleInput()
{
    
}

Window* Game::getWindow()
{
    return &window;
}

sf::Time Game::GetElapsed()
{
    return tElapsed;
}

void Game::restartClock()
{
    tElapsed = clock.restart();
}

// MAIN METHOD
void main(int argc, void** argv[])
{
    // Program Entry Point
    Game game; // Creating Game Object
    while(!game.getWindow()->isDone())
    {
        // Game Loop
        game.handleInput();
        game.update();
        game.render();
        game.restartClock(); // Restarting the Clock
    }
}










