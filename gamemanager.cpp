#include <chrono> //for time between clicks
#include <QThread>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

//for debugging
#include <iostream>



//game includes
#include "gamemanager.h"
#include "scoresystem.h"




GameManager::GameManager(QObject *parent) : QObject(parent)
{

}

GameManager::GameManager(ScoreSystem *scoreSystem)
{
    this->scoreSystem = scoreSystem;
}

int GameManager::generateRandomNumberInRange(int min, int max)
{
    boost::random::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

void GameManager::reportClick(int timeToClick, int id) {

    std::cout << "A GameBlock was clicked in "
              << timeToClick << " millisecond"
              << std::endl;

    if(timeToClick < MIN_TIME_TO_CLICK) {
        emit clickHandled(true, id);

        //give score, it is the time taken to click
        scoreSystem->setScore(MIN_TIME_TO_CLICK - timeToClick);

    } else { //it was a missed click!
        emit clickHandled(false, id);
    }

    //ask QML to add a new game sprite!
    //random delay until next spawn
    delay(generateRandomNumberInRange(100,800));
    emit spriteRequested();
}

void GameManager::newGame(){

    scoreSystem->resetScore();
    delay(3000); //wait for 3 seconds
    emit spriteRequested();
}


unsigned long GameManager::getCurrentTimeInMilliSeconds(){
    return std::chrono::system_clock::now().time_since_epoch() /
            std::chrono::milliseconds(1);
}

void GameManager::delay(int milliseconds)
{
#ifdef DEBUG
    std::cout << "Delaying for " << milliseconds << " milliseconds" << std::endl;
#endif
    QTime dieTime= QTime::currentTime().addMSecs(milliseconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
