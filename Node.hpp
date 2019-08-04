#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Node
{
    private:

    public:
        Node();
        int data;
        int height;
        Node *lchild , *rchild;
        sf::CircleShape circle;
        sf::VertexArray linestrip;
        sf::Text text;
        sf::Font font;
};