#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <scoresystem.h>

//using boost for math operations

//We use mt19937 with the default seed as a source of randomness.
//The numbers produced will be the same every time the program is run
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>


#define MIN_TIME_TO_CLICK 1000

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
    int generateRandomNumberInRange(int min, int max);

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

    //random number generator according to mt19937
    boost::random::mt19937 gen;
};

#endif // GAMEMANAGER_H
