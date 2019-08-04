#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class UI
{
    private:
        sf::RectangleShape rectangle;
        sf::Text buttontext[3];
        sf::Text mesg;
        sf::Text titleText;
        sf::Font font;
    public:
        UI();
        sf::Text text;
        sf::RectangleShape button[3];
        void fontLoad();
        void buttonLoad();
        void rectmaking();
        void UIdraw(sf::RenderWindow &);
        void settitle(sf::RenderWindow&);
};