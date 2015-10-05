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
    void clickHandled(bool result);
    void stateChanged(bool state);


public slots:
    /**
     * @brief reportClick
     * @param when the click has happened, since epoch in milliseconds
     */
    void reportClick(int when);
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

};

#endif // GAMEMANAGER_H
