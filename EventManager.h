#pragma once
#include <SFML/Window.hpp>

enum class EventType
{
    keyDown = sf::Event::KeyPressed,
    keyup = sf::Event::KeyReleased,
    mButtonDown = sf::Event::MouseButtonPressed,
    mButtonUp = sf::Event::MouseButtonReleased,
    windowResized = sf::Event::Resized,
    closed = sf::Event::Closed,
    gainedEvent = sf::Event::GainedFocus,
    lostFocus = sf::Event::LostFocus
};

class EventManager
{
public:
    EventManager();
    ~EventManager();
};
