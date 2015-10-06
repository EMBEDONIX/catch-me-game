#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <scoresystem.h>

class GameManager : public QObject
{
    Q_OBJECT

public:
    explicit GameManager(QObject *parent = 0); //explicit constructor?
    GameManager(ScoreSystem *ScoreSystem);
    /**
     * @brief mScoreSystem Reference to ScoreSystem
     */
    ScoreSystem *scoreSystem; //score system

signals:
    void clickHandled(bool result, unsigned long id);
    void spriteRequested();


public slots:
    /**
     * @brief reportClick
     * @param timeToClick how long it took user to click, after game block was created
     */
    void reportClick(int timeToClick, int id);
    /**
     * @brief newGame reset the socre and start a new game
     */
    void newGame();

private:
    /**
     * @brief getCurrentTimeInMilliSeconds
     * @return  current time since epoch in milliseconds
     */
    unsigned long getCurrentTimeInMilliSeconds();
    //TODO check if ulong would not make problem in other platforms
    //SEE http://stackoverflow.com/questions/16177295/

    void delay(int seconds);
};

#endif // GAMEMANAGER_H
