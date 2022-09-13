//
// Created by lenovo on 2021/5/24.
//

#include "LogoPanel.h"

LogoPanel::LogoPanel() {
    haveShadow = false;

    backgroundColor = sf::Color(192, 192, 192);
    background.setFillColor(backgroundColor);
    background.setSize(sf::Vector2f(BACKGROUND_WIDTH,BACKGROUND_HEIGHT));
    background.setPosition(BACKGROUND_X,BACKGROUND_Y);

    text_x = 200;
    text_y = 300;
    text_size = 50;
    textStr = "";
    alphaNum = 255;
    textColor = sf::Color(0, 0, 0, alphaNum);
    fontFile = "../text/OpenSans-Bold.ttf";
    font.loadFromFile(fontFile);
    logoText.setFont(font);
    logoText.setCharacterSize(text_size);
    logoText.setString(textStr);
    logoText.setPosition(sf::Vector2f(text_x,text_y));
    logoText.setFillColor(textColor);
//    logoText.move(100.f, 100.f);

    shadow_x = 200;
    shadow_y = 400;
    shadow_skew = -0.5;
    shadow.setFont(font);
    shadow.setCharacterSize(text_size);
    shadow.setString(textStr);
    shadow.setPosition(sf::Vector2f(shadow_x,shadow_y));
    shadow.setFillColor(sf::Color::White);
//    shadow.move(100.f,250.f);
    shadow.setScale(1,shadow_skew);
}

void LogoPanel::draw(sf::RenderTarget &window) {
    font.loadFromFile(fontFile);
    logoText.setFont(font);
    window.draw(background);
    window.draw(logoText);

    if (haveShadow)
        window.draw(shadow);
}

void LogoPanel::addEventHandler(sf::RenderWindow &window) {

}

void LogoPanel::update() {
    background.setFillColor(backgroundColor);

    textColor = sf::Color(textColor.r, textColor.g, textColor.b, alphaNum);
    font.loadFromFile(fontFile);
    logoText.setFont(font);
    logoText.setString(textStr);
    logoText.setCharacterSize(text_size);
    logoText.setPosition(sf::Vector2f(text_x,text_y));
    logoText.setFillColor(sf::Color(0, 0, 0, alphaNum));
    logoText.setFillColor(textColor);

    shadow.setFont(font);
    shadow.setCharacterSize(text_size);
    shadow.setString(textStr);
    shadow.setPosition(sf::Vector2f(shadow_x,shadow_y));
    shadow.setScale(1,shadow_skew);
}

int LogoPanel::getText_X() {
    return text_x;
}

int LogoPanel::getText_Y() {
    return text_y;
}

int LogoPanel::getTextSize() {
    return text_size;
}

int LogoPanel::getAlphaNum() {
    return alphaNum;
}

int LogoPanel::getShadow_X() {
    return shadow_x;
}

int LogoPanel::getShadow_Y() {
    return shadow_y;
}

double LogoPanel::getShadowSkew() {
    return shadow_skew;
}

std::string LogoPanel::getFontFile() {
    return fontFile;
}

std::string LogoPanel::getText() {
    return textStr;
}

sf::Color LogoPanel::getTextColor() {
    return textColor;
}

sf::Color LogoPanel::getBackgroundColor() {
    return backgroundColor;
}

bool LogoPanel::getShadow() {
    return haveShadow;
}

FileData LogoPanel::getData() {
    FileData temp;

    temp.text_position_x = text_x;
    temp.text_position_y = text_y;
    temp.textSize = text_size;
    temp.text_str = textStr;
    temp.alpha = alphaNum;
    temp.fontFileName = fontFile;

    temp.shadow_position_x = shadow_x;
    temp.shadow_position_y = shadow_y;
    temp.skew = shadow_skew;
    temp.textColor = textColor;
    temp.backgroundColor = backgroundColor;

    temp.shadowHave = haveShadow;

    return temp;
}

void LogoPanel::changeTextStr(std::string str) {
    textStr = str;
}

void LogoPanel::changeTextSize(int size) {
    text_size = size;
}

void LogoPanel::changeTextPosition(int x, int y) {
    text_x = x;
    text_y = y;
}

void LogoPanel::changeAlphaNum(int alpha) {
    alphaNum = alpha;
}

void LogoPanel::changeShadowPosition(int x, int y) {
    shadow_x = x;
    shadow_y = y;
}

void LogoPanel::changeShadowSkew(double num) {
    shadow_skew = num;
}

void LogoPanel::changeTextFont(std::string file) {
    fontFile = file;
}

void LogoPanel::changeTextColor(sf::Color color) {
    textColor = color;
}

void LogoPanel::changeBackgroundColor(sf::Color color) {
    backgroundColor = color;
}

void LogoPanel::setShadow(bool shadowHave) {
    haveShadow = shadowHave;
}

void LogoPanel::readData(FileData dataStr) {
    text_x = dataStr.text_position_x;
    text_y = dataStr.text_position_y;
    text_size = dataStr.textSize;
    textStr = dataStr.text_str;
    alphaNum = dataStr.alpha;
    fontFile = dataStr.fontFileName;

    shadow_x = dataStr.shadow_position_x;
    shadow_y = dataStr.shadow_position_y;
    shadow_skew = dataStr.skew;

    textColor = dataStr.textColor;
    backgroundColor = dataStr.backgroundColor;

    haveShadow = dataStr.shadowHave;
}

void LogoPanel::saveLogoImage(sf::RenderWindow &window, std::string fileName) {
    LogoImageSaver logoImageSaver;
    logoImageSaver.saveImage(window, background.getPosition().x, background.getPosition().y, BACKGROUND_WIDTH, BACKGROUND_HEIGHT, fileName);
}