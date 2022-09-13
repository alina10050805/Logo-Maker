//
// Created by lenovo on 2021/6/3.
//

#ifndef LOGOMAKER_COLORPICHER_H
#define LOGOMAKER_COLORPICHER_H

#include <sfml/graphics.hpp>
#include "../TopDropdownMenu/WindowData.h"

class ColorPicher {
private:
    const int BOX_SIZE = 1;
    sf::VertexArray colors = sf::VertexArray(sf::Points, 256*256);
    int box_x, box_y;
    bool choice;
    int choiceIndex;

public:
    enum mainColor {RED, YELLOW, GREEN, CYAN, BLUE, PURPLE};
    ColorPicher();
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    void setColor(mainColor colorChoice);
    void setPosition(int x, int y);
    sf::Color getIndexColor(int index);
    bool getChoice();
    void reChoice();
    int getChoiceIndex();
};

#include "ColorPicher.cpp"

#endif //LOGOMAKER_COLORPICHER_H
