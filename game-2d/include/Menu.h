#ifndef MENU_H
#define MENU_H
#include <SFML\Graphics.hpp>\
#include "Tekst.h"

const int MAX_NUMBER_OF_ITEMS=3;
class Menu
{
    public:
        Menu(float width, float height);
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();

        virtual ~Menu();


    protected:

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif // MENU_H
