//
// Created by lenovo on 2021/5/24.
//

#include "Slider.h"

Slider::Slider() {
    if (dark)
        line.setOutlineColor(sf::Color::White);
    else
        line.setOutlineColor(sf::Color::Black);

    line.setOutlineThickness(1);
}

Slider::Slider(std::string text, int x, int y, int range, int len, bool isFloat, bool isNegative) {
    floatNum = isFloat;
    negative = isNegative;
    font.loadFromFile("../text/OpenSans-Bold.ttf");
    valueSize = range;
    length = len;
    valueTimes = (1.0 * valueSize) / length;

    dataStr = text;
    dataText.setFont(font);
    dataText.setCharacterSize(20);
    dataText.setString(dataStr);
    dataText.setPosition(x,y);
    if (dark)
        dataText.setFillColor(sf::Color::White);
    else
        dataText.setFillColor(sf::Color::Black);

    line.setOutlineThickness(1);
    line.setSize(sf::Vector2f(length,0));
    line_x = dataText.findCharacterPos(text.length()).x + 13;
    line_y = dataText.findCharacterPos(text.length()).y + 12;
    line.setPosition(sf::Vector2f(line_x,line_y));
    if (dark)
        line.setOutlineColor(sf::Color::White);
    else
        line.setOutlineColor(sf::Color::Black);

    circle_x = line_x - 8;
    circle_y = line_y - 8;
    circle.setOutlineThickness(1);
    circle.setPosition(sf::Vector2f(circle_x,circle_y));
    circle.setRadius(8);
    if (dark)
    {
        circle.setOutlineColor(sf::Color::White);
        circle.setFillColor(sf::Color(192, 192, 192));
    }
    else
    {
        circle.setOutlineColor(sf::Color::Black);
        circle.setFillColor(sf::Color(192, 192, 192));
    }

    if (floatNum)
    {
        valueDouble = getDoubleValue();
        value = std::to_string(valueDouble);
        value = value.substr(0, value.find(".") + 2 + 1);
    }
    else
    {
        valueInt = getValue();
        value = std::to_string(valueInt);
    }
    valueText.setFont(font);
    valueText.setCharacterSize(20);
    valueText.setString(value);
    valueText.setPosition(line_x + length + 13, y);
    if (dark)
        valueText.setFillColor(sf::Color::White);
    else
        valueText.setFillColor(sf::Color::Black);
}

void Slider::draw(sf::RenderTarget &window) {
    window.draw(dataText);
    window.draw(line);
    window.draw(circle);
    window.draw(valueText);
}

void Slider::addEventHandler(sf::RenderWindow &window) {
    if (circle.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
        && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (sf::Mouse::getPosition(window).x >= line.getPosition().x
            && sf::Mouse::getPosition(window).x <= (line.getPosition().x + length))
        {
            changeCirlePosition(sf::Mouse::getPosition(window).x - 8);
            if (floatNum)
            {
                valueDouble = getDoubleValue();
                value = std::to_string(valueDouble);
            }
            else
            {
                valueInt = getValue();
                value = std::to_string(valueInt);
            }
        }
    }
}

void Slider::update() {
    circle.setPosition(sf::Vector2f(circle_x,circle_y));

    if (floatNum)
    {
        valueDouble = getDoubleValue();
        value = std::to_string(valueDouble);
        value = value.substr(0, value.find(".") + 2 + 1);
    }
    else
    {
        valueInt = getValue();
        value = std::to_string(valueInt);
    }
    valueText.setString(value);

    if (dark)
        dataText.setFillColor(sf::Color::White);
    else
        dataText.setFillColor(sf::Color::Black);

    if (dark)
        line.setOutlineColor(sf::Color::White);
    else
        line.setOutlineColor(sf::Color::Black);

    if (dark)
    {
        circle.setOutlineColor(sf::Color::White);
        circle.setFillColor(sf::Color(192, 192, 192));
    }
    else
    {
        circle.setOutlineColor(sf::Color::Black);
        circle.setFillColor(sf::Color(192, 192, 192));
    }

    if (dark)
        valueText.setFillColor(sf::Color::White);
    else
        valueText.setFillColor(sf::Color::Black);
}

int Slider::getValue() {
    if (negative)
        return (valueTimes * (circle.getPosition().x - line.getPosition().x + circle.getRadius())) - valueSize/2;
    else
        return valueTimes * (circle.getPosition().x - line.getPosition().x + circle.getRadius());
}

double Slider::getDoubleValue() {
    if (negative)
        return (valueTimes * (circle.getPosition().x - line.getPosition().x + circle.getRadius())) - valueSize/2.0;
    else
        return valueTimes * (circle.getPosition().x - line.getPosition().x + circle.getRadius());
}

void Slider::changeCirlePosition(int x) {
    circle_x = x;
}

void Slider::setCirclePositionWithValue(int value) {
    circle_x = line.getPosition().x + value/valueTimes - circle.getRadius();

    if (negative) {
        if (value<0)
            circle_x = line.getPosition().x - value / valueTimes - circle.getRadius();
        else
            circle_x = line.getPosition().x + value / valueTimes - circle.getRadius() + (length/2.0);
    }
}

void Slider::setCirclePositionWithValue(double value) {
    circle_x = line.getPosition().x + value/valueTimes - circle.getRadius();

    if (negative) {
        if (value<0)
            circle_x = line.getPosition().x - value / valueTimes - circle.getRadius();
        else
            circle_x = line.getPosition().x + value / valueTimes - circle.getRadius() + (length/2.0);
    }
}