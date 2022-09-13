//
// Created by lenovo on 2021/5/24.
//

#ifndef LOGOMAKER_LOGOPANEL_H
#define LOGOMAKER_LOGOPANEL_H

#include "../TopDropdownMenu/File.h"
#include "LogoImageSaver.h"
//#include "LogoHistory.h"

class LogoPanel {
private:
    sf::RectangleShape background;
    sf::Font font;
    sf::Text logoText;
    sf::Text shadow;

    int text_x, text_y;
    int text_size;
    std::string textStr;
    int alphaNum;
    std::string fontFile;
    sf::Color textColor;
    sf::Color backgroundColor;

    bool haveShadow;
    int shadow_x, shadow_y;
    double shadow_skew;

    const int BACKGROUND_WIDTH = 1200;
    const int BACKGROUND_HEIGHT = 564;
    const int BACKGROUND_X = 0;
    const int BACKGROUND_Y = 34;

public:
    LogoPanel();
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window);
    void update();

    int getText_X();
    int getText_Y();
    int getTextSize();
    int getAlphaNum();
    int getShadow_X();
    int getShadow_Y();
    double getShadowSkew();
    std::string getFontFile();
    std::string getText();
    sf::Color getTextColor();
    sf::Color getBackgroundColor();
    bool getShadow();
    FileData getData();

    void changeTextStr(std::string str);
    void changeTextSize(int size);
    void changeTextPosition(int x, int y);
    void changeAlphaNum(int alpha);
    void changeShadowPosition(int x, int y);
    void changeShadowSkew(double num);
    void changeTextFont(std::string file);
    void changeTextColor(sf::Color color);
    void changeBackgroundColor(sf::Color color);
    void setShadow(bool shadowHave);
    void readData(FileData dataStr);

    void saveLogoImage(sf::RenderWindow& window, std::string fileName);
};

#include "LogoPanel.cpp"

#endif //LOGOMAKER_LOGOPANEL_H
