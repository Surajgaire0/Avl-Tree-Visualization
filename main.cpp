
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Avl.hpp"
#include "UI.hpp"
#include "Node.hpp"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "AVL Tree");
    //window.setKeyRepeatEnabled(false);
    sf::View view(sf::FloatRect(0,0,window.getSize().x,window.getSize().y));
    view.setCenter(sf::Vector2f(window.getSize().x/2,window.getSize().y/2));
    sf::Clock clock;
    bool search1=false;

    Avl tree;
    UI ui;
    ui.settitle(window);
    Node *t; //search
    string str1="";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
        
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    //cout<<event.text.unicode<<endl;
                    if (event.text.unicode>=26 && event.text.unicode<=35)
                    {
                        //convert to ascii
                        char temp=event.text.unicode+22;
                        str1+=temp;
                        (ui.text).setString(str1);
                    }
                    else if (event.key.code==sf::Keyboard::Escape)
                        window.close();
                    else if (event.text.unicode==59)
                    {
                        str1.pop_back();
                        ui.text.setString(str1);
                    }
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Right:
                            view.move(sf::Vector2f(-4.f,0));
                            break;
                        case sf::Keyboard::Left:
                            view.move(sf::Vector2f(4.f,0.f));
                            break;
                        case sf::Keyboard::Down:
                            view.move(sf::Vector2f(0,-4.f));
                            break;
                        case sf::Keyboard::Up:
                            view.move(sf::Vector2f(0.f,4.f));;
                            break;
                        case sf::Keyboard::I:
                            //view.setSize(sf::Vector2f(view.getSize().x*0.99,view.getSize().x*0.95));
                            view.zoom(0.99f);
                            break;
                        case sf::Keyboard::O:
                            //view.setSize(sf::Vector2f(view.getSize().x*1.01,view.getSize().x*1.05));
                            view.zoom(1.01f);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            if (sf::Mouse::isButtonPressed((sf::Mouse::Left)))
            {
                if (ui.button[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y) && str1.empty()==false)
                {
                    //insert
                    if(tree.getroot()==NULL)
                        tree.setroot(tree.Insert(tree.getroot(),atoi(str1.c_str())));
                    else
                        tree.Insert(tree.getroot(),atoi(str1.c_str()));
                    str1.clear();
                    ui.text.setString(str1);
                }
                if (ui.button[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y) && str1.empty()==false)
                {
                    //deletion
                    tree.Delete(atoi(str1.c_str()),tree.getroot());
                    str1.clear();
                    ui.text.setString(str1);
                }
                
                if (ui.button[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y) && str1.empty()==false)
                {
                    if(!search1)
                    {
                        t=tree.Search(atoi(str1.c_str()),tree.getroot());
                        tree.setspcolor(t,search1,clock);
                    }
                    str1.clear();
                    ui.text.setString(str1);
                }
            }
        }

        if (search1==true)
        {
            if (clock.getElapsedTime().asMilliseconds()>1000)
            {
                tree.setbackcolor(t,search1);
            }
        }
        window.clear(sf::Color(87,80,80));
        window.setView(view);
        tree.setCordinate(tree.getroot(),250);
        tree.draw(tree.getroot(),window);
        window.setView(window.getDefaultView());
        ui.UIdraw(window);
        window.display(); 
    }
    return 0;
}




    