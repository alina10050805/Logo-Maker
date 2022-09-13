//
// Created by lenovo on 2021/5/24.
//

#ifndef LOGOMAKER_SLIDER_H
#define LOGOMAKER_SLIDER_H

#include <sfml/graphics.hpp>
#include "../TopDropdownMenu/WindowData.h"

class Slider {
private:
    sf::CircleShape circle;
    sf::RectangleShape line;

    sf::Font font;
    sf::Text dataText;
    std::string dataStr;
    sf::Text valueText;
    std::string value;

    int line_x, line_y;
    int length, valueSize;
    double valueTimes;
    int valueInt;
    double valueDouble;
    bool floatNum;
    bool negative;

    int circle_x, circle_y;

public:
    Slider();
    Slider(std::string itemText, int x, int y, int range, int len, bool isFloat = false, bool isNegative = false);
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window);
    void update();
    int getValue();
    double getDoubleValue();
    void changeCirlePosition(int x);
    void setCirclePositionWithValue(int value);
    void setCirclePositionWithValue(double value);
};

#include "Slider.cpp"

#endif //LOGOMAKER_SLIDER_H
