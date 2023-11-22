#pragma once

#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Window
{
public:
    Window();
    Window(const string& title, const sf::Vector2u& size);
    ~Window();

    void beginDraw(); // Clear Window
    void endDraw(); // Display the Changes.

    void update();

    bool isDone();
    bool isFullScreen();
    sf::Vector2u GetWindowSize();

    void toggleFullScreen();
    void Draw(sf::Drawable&);
private:
    void Setup(const string&, const sf::Vector2u& size);
    void Destroy();
    void Create();

    sf::RenderWindow mWindow;
    sf::Vector2u mWindowSize;
    string mWindowTitle;
    bool mIsDone;
    bool mIsFullScreen;
};
