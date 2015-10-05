#include "gamemanager.h"
#include "scoresystem.h"
#include <chrono> //for time between clicks



GameManager::GameManager(QObject *parent) : QObject(parent)
{


}

GameManager::GameManager(ScoreSystem *scoreSystem)
{
    this->scoreSystem = scoreSystem;
}

void GameManager::reportClick(int when) {
    int result = getCurrentTimeInMilliSeconds() - when;
    if(result > 0) {
        emit clickHandled(true);
        scoreSystem->setScore(result);
    } else { //it was a missed click!
        emit clickHandled(false);
    }
}

void GameManager::newGame(){
    scoreSystem->resetScore();
    emit stateChanged(true);
}


unsigned long GameManager::getCurrentTimeInMilliSeconds(){
    return std::chrono::system_clock::now().time_since_epoch() /
        std::chrono::milliseconds(1);
}
