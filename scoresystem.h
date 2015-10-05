#ifndef SCORESYSTEM_H
#define SCORESYSTEM_H

#include <QObject>

/**
 * @brief The ScoreSystem class
 * This class is inteded to keep track of player's score and show the score
 *
 * @author Saeid Yazdani
 */
class ScoreSystem : public QObject
{
    Q_OBJECT

    //property for tracking player's score
    Q_PROPERTY(QString score READ score NOTIFY scoreChanged)

public:
    explicit ScoreSystem(QObject *parent = 0); //constructor
    /**
     * @brief score
     * @return current score as QString
     */
    QString score() const { return mScoreText;} //returns score string
    /**
     * @brief resetScore resets score to 0
     */
    void resetScore();
    /**
     * @brief setScore Set the current score
     * @param score How much add to current score?
     */
    void setScore(int score);



signals:
    void scoreChanged();

public slots:

private:
    int mScore;
    QString mScoreText;
};

#endif // SCORESYSTEM_H
