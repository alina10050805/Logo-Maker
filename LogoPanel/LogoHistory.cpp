//
// Created by lenovo on 2021/6/1.
//

#include "LogoHistory.h"

LogoHistory::LogoHistory() {

}

void LogoHistory::pushHistory(FileData data) {
    stackData.push(data);
}

FileData LogoHistory::topHistory() {
    return stackData.top();
}

void LogoHistory::popHistory() {
    stackData.pop();
}

bool LogoHistory::emptyHistory() {
    return stackData.empty();
}

int LogoHistory::sizeHistory() {
    return stackData.size();
}

void LogoHistory::resetHistory() {
    while (!stackData.empty())
    {
        stackData.pop();
    }
}