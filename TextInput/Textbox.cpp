//
// Created by lenovo on 2021/5/25.
//

#include "Textbox.h"

TextBox::TextBox(std::string str, int x, int y) {
    font.loadFromFile("../text/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString(str);
    text.setPosition(sf::Vector2f(x,y));
    if (dark)
        text.setFillColor(sf::Color::White);
    else
        text.setFillColor(sf::Color::Black);

    text_x = text.findCharacterPos(str.length()).x + 13;
    text_y = text.findCharacterPos(str.length()).y;
    textBox.setOutlineThickness(2);
    textBox.setSize(sf::Vector2f(box_width,box_height));
    textBox.setPosition(sf::Vector2f(text_x,text_y));
    if (dark)
    {
        textBox.setOutlineColor(sf::Color::White);
        textBox.setFillColor(sf::Color::Black);
    }
    else
    {
        textBox.setOutlineColor(sf::Color::Black);
        textBox.setFillColor(sf::Color::White);
    }

    type.setPosition(text_x, text_y);
}

TextBox::TextBox(std::string str, int x, int y, int width) {
    font.loadFromFile("../text/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString(str);
    text.setPosition(sf::Vector2f(x,y));
    if (dark)
        text.setFillColor(sf::Color::White);
    else
        text.setFillColor(sf::Color::Black);

    box_width = width;
    text_x = text.findCharacterPos(str.length()).x + 13;
    text_y = text.findCharacterPos(str.length()).y;
    textBox.setOutlineThickness(2);
    textBox.setSize(sf::Vector2f(width,box_height));
    textBox.setPosition(sf::Vector2f(text_x,text_y));
    if (dark)
    {
        textBox.setOutlineColor(sf::Color::White);
        textBox.setFillColor(sf::Color::Black);
    }
    else
    {
        textBox.setOutlineColor(sf::Color::Black);
        textBox.setFillColor(sf::Color::White);
    }

    type.setPosition(text_x, text_y);
}

void TextBox::draw(sf::RenderTarget &window) {
    window.draw(textBox);
    window.draw(text);

    type.draw(window);
}

void TextBox::addEventHandler(sf::Event event) {

    type.addEventHandler(event);
}

void TextBox::update() {
    type.update();

    if (dark)
        text.setFillColor(sf::Color::White);
    else
        text.setFillColor(sf::Color::Black);

    if (dark)
    {
        textBox.setOutlineColor(sf::Color::White);
        textBox.setFillColor(sf::Color::Black);
    }
    else
    {
        textBox.setOutlineColor(sf::Color::Black);
        textBox.setFillColor(sf::Color::White);
    }
}

std::string TextBox::getinputText() {
    return type.getText();
}

void TextBox::resetType() {
    type.resetHistory();
}

void TextBox::setText(std::string str) {
    type.pushText(str);
}