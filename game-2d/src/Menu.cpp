#include "Menu.h"
#include <iostream>
Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("fonts/open-sans.ttf"))
    {
        std::cout<<"Error font loading...";
    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("PLAY!");
    menu[0].setPosition(sf::Vector2f(width/2,height/4*1));


}
void Menu::draw(sf::RenderWindow &window)
{
    for(int i=0;i<3;i++)
    {
        window.draw(menu[i]);
    }
}
Menu::~Menu()
{
    //dtor
}
