//
// Created by lenovo on 2021/5/24.
//

#include "OperationPanel.h"

OperationPanel::OperationPanel() {
    panel.setOutlineThickness(2);
    panel.setSize(sf::Vector2f(1198, 298));
    panel.setPosition(2,600);
    if (dark)
    {
        panel.setOutlineColor(sf::Color::White);
        panel.setFillColor(sf::Color::Black);
    }
    else
    {
        panel.setOutlineColor(sf::Color::Black);
        panel.setFillColor(sf::Color::White);
    }

    initialSliders();
}

void OperationPanel::initialSliders() {
    logoText.setText(logoPanel.getText());
    fontMenu.findFontChoice(logoPanel.getFontFile());

    textOpacity.setCirclePositionWithValue(logoPanel.getAlphaNum());
    fontSize.setCirclePositionWithValue(logoPanel.getTextSize());
    skew.setCirclePositionWithValue(logoPanel.getShadowSkew());

    text_x_axis.setCirclePositionWithValue(logoPanel.getText_X());
    text_y_axis.setCirclePositionWithValue(logoPanel.getText_Y());

    shadow_x_axis.setCirclePositionWithValue(logoPanel.getShadow_X());
    shadow_y_axis.setCirclePositionWithValue(logoPanel.getShadow_Y());

    textColorButton.setColor(logoPanel.getTextColor());
    backgroundColor.setColor(logoPanel.getBackgroundColor());

    shadowChoice.setChoice(logoPanel.getShadow());
}

void OperationPanel::setData(FileData data) {
    logoPanel.readData(data);
    initialSliders();
}

void OperationPanel::draw(sf::RenderTarget &window) {
    window.draw(panel);

    logoText.draw(window);

    textOpacity.draw(window);
    fontSize.draw(window);

    text_x_axis.draw(window);
    text_y_axis.draw(window);

    shadowChoice.draw(window);
    if (shadowChoice.getChoice())
    {
        shadow_x_axis.draw(window);
        shadow_y_axis.draw(window);
        skew.draw(window);
    }

    logoPanel.draw(window);

    backgroundColor.draw(window);
    textColorButton.draw(window);

    fontMenu.draw(window);
}

void OperationPanel::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    logoText.addEventHandler(event);

    textOpacity.addEventHandler(window);
    fontSize.addEventHandler(window);

    text_x_axis.addEventHandler(window);
    text_y_axis.addEventHandler(window);

    shadowChoice.addEventHandler(window, event);
    if (shadowChoice.getChoice())
    {
        shadow_x_axis.addEventHandler(window);
        shadow_y_axis.addEventHandler(window);
        skew.addEventHandler(window);
    }

    fontMenu.addEventHandler(window, event);

    if (!textColorButton.getOpen())
        backgroundColor.addEventHandler(window, event);

    textColorButton.addEventHandler(window, event);

//    logoPanel.addEventHandler(window);
}

void OperationPanel::update() {
    if (textColorButton.getOpen() && backgroundColor.getOpen())
        backgroundColor.resetOpen();

    logoPanel.changeTextStr(logoText.getinputText());
    logoPanel.changeTextSize(fontSize.getValue());
    logoPanel.changeShadowSkew(skew.getDoubleValue());
    logoPanel.changeTextPosition(text_x_axis.getValue(), text_y_axis.getValue());
    logoPanel.changeAlphaNum(textOpacity.getValue());
    logoPanel.changeShadowPosition(shadow_x_axis.getValue(), shadow_y_axis.getValue());
    logoPanel.changeTextFont(fontMenu.getFontFile());
    logoPanel.changeTextColor(textColorButton.getColor());
    logoPanel.changeBackgroundColor(backgroundColor.getColor());
    logoPanel.setShadow(shadowChoice.getChoice());

    logoText.update();

    textOpacity.update();
    fontSize.update();

    text_x_axis.update();
    text_y_axis.update();

    shadowChoice.update();
    if (shadowChoice.getChoice())
    {
        shadow_x_axis.update();
        shadow_y_axis.update();
        skew.update();
    }

    fontMenu.update();

    textColorButton.update();
    backgroundColor.update();

    logoPanel.update();

    if (dark)
    {
        panel.setOutlineColor(sf::Color::White);
        panel.setFillColor(sf::Color::Black);
    }
    else
    {
        panel.setOutlineColor(sf::Color::Black);
        panel.setFillColor(sf::Color::White);
    }
}

FileData OperationPanel::getData() {
    FileData temp = logoPanel.getData();

    return temp;
}

void OperationPanel::saveLogoImage(sf::RenderWindow &window, std::string fileName) {
    logoPanel.saveLogoImage(window, fileName);
}