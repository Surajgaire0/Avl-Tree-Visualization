#include "UI.hpp"

UI::UI()
{
    fontLoad();
    rectmaking();
    buttonLoad();
}

void UI::fontLoad()
{
    if (!font.loadFromFile("Assets/unispace.ttf"))
    {
        cout<<"UI font not load";
    }
}

//button
void UI::buttonLoad()
{
    for (int i = 0; i < 3; i++)
    {
        static float k=110.f;
        button[i].setFillColor(sf::Color(255,0,255,150));
        button[i].setOutlineColor(sf::Color::Black);
        button[i].setOutlineThickness(2);
        button[i].setSize(sf::Vector2f(140.f,51.f));
        button[i].setPosition(sf::Vector2f(850.f,k));
        k+=80.f;

        string string2[3]= {"Insert", "Delete" , "Search"};
        buttontext[i].setCharacterSize(19);
        buttontext[i].setPosition(sf::Vector2f(button[i].getPosition().x+24,button[i].getPosition().y+15));
        buttontext[i].setString(string2[i]);
        buttontext[i].setFillColor(sf::Color::Black);
        buttontext[i].setFont(font);
    }
    
}

//text box
void UI::rectmaking()  
{
    rectangle.setFillColor(sf::Color::White);
    rectangle.setSize(sf::Vector2f(140.f,40.f));
    rectangle.setPosition(sf::Vector2f(850.00f,41.f));

    text.setCharacterSize(19);
    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setPosition(sf::Vector2f(rectangle.getPosition().x+4,rectangle.getPosition().y+10));
    //text.setString("");

    mesg.setCharacterSize(13);
    mesg.setFont(font);
    mesg.setString("Enter Number:");
    mesg.setFillColor(sf::Color(13,56,37));
    mesg.setPosition(sf::Vector2f(rectangle.getPosition().x,rectangle.getPosition().y-25));
}

void UI::settitle(sf::RenderWindow &window)
{
    titleText.setCharacterSize(40);
    titleText.setOutlineColor(sf::Color::Black);
    titleText.setOutlineThickness(2);
    titleText.setPosition(sf::Vector2f(window.getSize().x*3/9,window.getSize().y*1/29));
    titleText.setFont(font);
    titleText.setString("AVL TREE");
    titleText.setFillColor(sf::Color::Blue);
}
void UI::UIdraw(sf::RenderWindow &window)
{
    for (int i = 0; i < 3; i++)
    {
        window.draw(button[i]);
        window.draw(buttontext[i]);
    }

    window.draw(mesg);
    window.draw(rectangle);
    window.draw(titleText);
    window.draw(text);

}