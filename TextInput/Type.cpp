//
// Created by lenovo on 2021/5/25.
//

#include "Type.h"

Type::Type() {
    type_x = 10;
    type_y = 55;

    font.loadFromFile("../text/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition(sf::Vector2f(type_x,type_y));
    if (dark)
        text.setFillColor(sf::Color::White);
    else
        text.setFillColor(sf::Color::Black);

    history.pushHistory("");
}

void Type::setPosition(int x, int y) {
    type_x = x;
    type_y = y;
    text.setPosition(sf::Vector2f(type_x,type_y));
}

void Type::addEventHandler(sf::Event event) {
    if (event.type == sf::Event::TextEntered){
//        std::cout << event.text.unicode << " ";

        if (!history.emptyHistory())
            input = history.topHistory();

        if (event.text.unicode < 128 && event.text.unicode > 31) {
            input += event.text.unicode;

            history.pushHistory(input);
            text.setString(history.topHistory());
        }
        else if(event.text.unicode == 8 && !input.isEmpty())
        {
            input = input.substring(0, input.getSize()-1);

            history.pushHistory(input);
            text.setString(history.topHistory());
        }
        else if (event.text.unicode == 26  && history.sizeHistory() > 1)
        {
            history.popHistory();

            text.setString(history.topHistory());
        }
        else if (event.text.unicode == 13){
            input += "\n";

            history.pushHistory(input);
            text.setString(history.topHistory());
        }
    }
}

void Type::update() {
    text.setPosition(sf::Vector2f(type_x,type_y));

    if (dark)
        text.setFillColor(sf::Color::White);
    else
        text.setFillColor(sf::Color::Black);
}

void Type::draw(sf::RenderTarget &window) {
    window.draw(text);
}

std::string Type::getText() {
    return history.topHistory();
}

void Type::resetHistory() {
    history.resetHistory();
    history.pushHistory("");
    text.setString(history.topHistory());
}

void Type::pushText(std::string str) {
    history.pushHistory(str);
    text.setString(history.topHistory());
}