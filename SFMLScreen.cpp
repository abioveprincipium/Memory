#include "SFMLScreen.h"
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>

SFMLScreen:: SFMLScreen(){
    font.loadFromFile("../hp.ttf");
    title.setCharacterSize(30);title.setFont(font);title.setString("Memory Game");
}


MainMenu::MainMenu(){
    active = true;
    button1.setSize({150, 75});button1.setPosition(300, 300);button1.setFillColor(sf::Color::White);

    button1Text.setFont(font);button1Text.setCharacterSize(30);button1Text.setPosition(305, 305);
    button1Text.setString("Play");button1Text.setFillColor(sf::Color::Black);

    button2.setSize({150, 75});button2.setPosition(300, 400);button2.setFillColor(sf::Color::White);

    button2Text.setFont(font);button2Text.setCharacterSize(30);button2Text.setPosition(305, 405);
    button2Text.setString("Exit");button2Text.setFillColor(sf::Color::Black);
}
void MainMenu::drawScreen(sf::RenderWindow &window){

    window.draw(button1);
    window.draw(button2);
    window.draw(button1Text);
    window.draw(button2Text);
}
GameCtrl::GameCtrl(){

    std::vector<sf::Vector2f> positions;
    for (int i = 0; i < 2; i++) for(int j = 0; j < 5; j++) positions.emplace_back(sf::Vector2f(j,i));

    zerowanie();
    for(int i = 0; i < 5; i++){

        Card one(pary[i].one);
        Card two(pary[i].two);

        one.text.setFont(font);
        two.text.setFont(font);


        int rand1 = rand() % positions.size();
        int rand2 = rand() % positions.size();

        one.setPos(50 + 55*positions[rand1].x, 50 + 55*positions[rand1].y);
        positions.erase(positions.begin()+rand1);

        two.setPos(50 + 55*positions[rand2].x, 50 + 55*positions[rand2].y);
        positions.erase(positions.begin()+rand2);

        one.pairindex = cards.size()+1;
        two.pairindex = cards.size();

        cards.emplace_back(one);
        cards.emplace_back(two);

    }
}

void GameCtrl::zerowanie(){

    click1 = -1; //zeruje zmienne
    click2 = -1;
}

void GameCtrl::resetGame(){

    cards.clear();

    std::vector<sf::Vector2f> positions;
    for (int i = 0; i < 2; i++) for(int j = 0; j < 5; j++) positions.emplace_back(sf::Vector2f(j,i));

    zerowanie();
    for(int i = 0; i < 5; i++){

        Card one(pary[i].one);
        Card two(pary[i].two);

        one.text.setFont(font);
        two.text.setFont(font);

        int rand1 = rand() % positions.size();
        int rand2 = rand() % positions.size();

        one.setPos(50 + 55*positions[rand1].x, 50 + 55*positions[rand1].y);
        positions.erase(positions.begin()+rand1);


        two.setPos(50 + 55*positions[rand2].x, 50 + 55*positions[rand2].y);
        positions.erase(positions.begin()+rand2);

        one.pairindex = cards.size()+1;
        two.pairindex = cards.size();

        cards.emplace_back(one);
        cards.emplace_back(two);

    }
}

void GameCtrl::gameLogic(int i){

//        Card *jeden;
//        Card *dwa;
//        if (jeden == NULL)
//        {

//        }
//        if (jeden != NULL && dwa != NULL)
//        {
//            if (jeden->para == dwa)
//        }
    if (click1 == -1 && !cards[i].isOk)
    {
        click1 = i;
    }
    else if (click2 == -1 && !cards[i].isOk)
    {
        click2 = i;
    }
    else if (i != click1 && i != click2 && !cards[i].isOk)
    {
        if (click1 != -1 && click2 != -1)
        {
            if (click2 == cards[click1].pairindex || click1 == cards[click2].pairindex)
            {
                //sa te same
                cards[click1].isOk = true;
                cards[click2].isOk = true;
            }
            else
            {
                //nie sa te same
                cards[click1].isOpen = false;
                cards[click2].isOpen = false;
            }
        }
        zerowanie();
        click1 = i;
    }
}

void GameCtrl::drawScreen(sf::RenderWindow &window){

    for(int i = 0; i < cards.size(); i++) {
        cards[i].drawCard(window);
    }
}


EndScreen::EndScreen(){

    text.setFont(font);text.setCharacterSize(30);text.setPosition(305, 305);text.setString("You won! CONGRATS!");
}
void EndScreen::drawScreen(sf::RenderWindow &window){
    window.draw(text);
}
