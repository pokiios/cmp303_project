#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

#define MAX_MENU 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();
    void moveUp();
    void moveDown();
    void draw(sf::RenderWindow& window);
    void initMenu(float width, float height);
private:
    int selectedIndex;
    sf::Font font;
    sf::Text menu[MAX_MENU];
};
