#pragma once

#include <iostream>
//#include <SFML/Graphics.hpp>
#include "Node.hpp"
using namespace std;

class Avl
{
    private:
        Node *root;
        Node *LLRotation(Node *);
        Node *LRRotation(Node *);
        Node *RLRotation(Node*);
        Node *RRRotation(Node *);
        int NodeHeight(Node *);
        int BalanceFactor(Node *);
        Node *pre(Node *);
        Node *succ(Node *);
    public:
        Avl();
        ~Avl();
        Node *Insert(Node * , int );
        Node *Delete (int key, Node *);
        Node *getroot();
        void setroot(Node *);
        void Preorder(Node *);
        void draw(Node *,sf::RenderWindow&);
        void setCordinate(Node *,int );

        // Node* singleRightRotate(Node* );
        // Node* singleLeftRotate(Node* );
        // Node* doubleLeftRotate(Node* );
        // Node* doubleRightRotate(Node* );
        void setbackcolor(Node *,bool &);

        Node *Search(int,Node *);
        void setspcolor(Node *,bool &, sf::Clock &);
};