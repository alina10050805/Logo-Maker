//
// Created by lenovo on 2021/6/6.
//

#ifndef LOGOMAKER_LOGOIMAGESAVER_H
#define LOGOMAKER_LOGOIMAGESAVER_H

#include <sfml/graphics.hpp>

class LogoImageSaver {
private:
    const std::string FILENAME_PREFIX = "../logoImage/";
    const std::string FILENAME_SUFFIX = ".jpg";
public:
    void saveImage(sf::RenderWindow &window, int x, int y, int width, int height, std::string fileName);
};

#include "LogoImageSaver.cpp"

#endif //LOGOMAKER_LOGOIMAGESAVER_H
