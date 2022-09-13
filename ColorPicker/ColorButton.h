//
// Created by lenovo on 2021/6/3.
//

#ifndef LOGOMAKER_COLORBUTTON_H
#define LOGOMAKER_COLORBUTTON_H

#include "ColorBox.h"
//#include "ColorPicher.h"

class ColorButton {
private:
    ColorBox colorBox;
//    ColorPicher colorPicher;
    const int BOX_WIDTH = 30;
    const int BOX_HEIGHT = 30;
    sf::Font font;
    sf::Text colorText;
    sf::RectangleShape colorChoice;
    int box_x, box_y;
    bool open;

public:
    ColorButton(std::string str, int x, int y);
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    sf::Color getColor();
    void setColor(sf::Color color);
    bool getOpen();
    void resetOpen();
};

#include "ColorButton.cpp"

#endif //LOGOMAKER_COLORBUTTON_H
