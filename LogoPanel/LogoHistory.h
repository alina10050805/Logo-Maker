//
// Created by lenovo on 2021/6/1.
//

#ifndef LOGOMAKER_LOGOHISTORY_H
#define LOGOMAKER_LOGOHISTORY_H

#include <stack>
#include "../TopDropdownMenu/File.h"

class LogoHistory {
private:
    stack<FileData> stackData;

public:
    LogoHistory();
    void pushHistory(FileData data);
    FileData topHistory();
    void popHistory();
    bool emptyHistory();
    int sizeHistory();
    void resetHistory();
};

#include "LogoHistory.cpp"

#endif //LOGOMAKER_LOGOHISTORY_H
