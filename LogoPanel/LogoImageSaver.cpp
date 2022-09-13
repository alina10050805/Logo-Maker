//
// Created by lenovo on 2021/6/6.
//

#include "LogoImageSaver.h"

void LogoImageSaver::saveImage(sf::RenderWindow &window, int x, int y, int width, int height, std::string fileName)
{
    sf::Texture logoWindow;
    logoWindow.create(window.getSize().x, window.getSize().y);
    logoWindow.update(window);

    sf::Image temp = logoWindow.copyToImage();
    sf::Image logoImage;
    sf::Vector2i logoPosition(x, y);
    sf::Vector2i logoSize(width, height);
    sf::IntRect intRect(logoPosition, logoSize);
    logoImage.create(width, height);
    logoImage.copy(temp, 0, 0, intRect, false);
    logoImage.saveToFile(FILENAME_PREFIX + fileName + FILENAME_SUFFIX);
}