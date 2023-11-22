#include "Window.h"

Window::Window()
{
    Setup("Window", sf::Vector2u(1920.f,1080.f));
}

Window::Window(const string& title, const sf::Vector2u& size)
{
    Setup(title, size);
}

Window::~Window()
{
    Destroy();
}

void Window::Setup(const string& title, const sf::Vector2u& size)
{
    mIsFullScreen = false;
    mWindowTitle = title;
    mWindowSize = size;
    mIsDone = false;
    Create();
}

void Window::Create()
{
    auto style = (mIsFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    mWindow.create({mWindowSize.x, mWindowSize.y, 32}, mWindowTitle, style);
}

void Window::Destroy()
{
    mWindow.close();
}

void Window::update()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            mIsDone = true;
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
        {
            toggleFullScreen();
        }
    }
}

void Window::toggleFullScreen()
{
    mIsFullScreen = !mIsFullScreen;
    Destroy();
    Create();
}

void Window::beginDraw()
{
    mWindow.clear(sf::Color::Black);
}
void Window::endDraw()
{
    mWindow.display();
}

bool Window::isDone()
{
    return mIsDone;
}

bool Window::isFullScreen()
{
    return mIsFullScreen;
}

sf::Vector2u Window::GetWindowSize()
{
    return mWindowSize;
}

void Window::Draw(sf::Drawable& drawable)
{
    mWindow.draw(drawable);
}







