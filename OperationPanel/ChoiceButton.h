//
// Created by lenovo on 2021/6/7.
//

#ifndef LOGOMAKER_CHOICEBUTTON_H
#define LOGOMAKER_CHOICEBUTTON_H

#include <sfml/graphics.hpp>
#include "../TopDropdownMenu/WindowData.h"

class ChoiceButton {
private:
    const int RECT_SIZE = 20;
    sf::Font font;
    sf::RectangleShape button;
    sf::RectangleShape showChoice;
    sf::Text buttonStr;
    bool choice;

public:
    ChoiceButton(std::string str, int x, int y);
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    bool getChoice();
    void setChoice(bool choiceValue);
};

#include "ChoiceButton.cpp"

#endif //LOGOMAKER_CHOICEBUTTON_H
