#include "scoresystem.h"

ScoreSystem::ScoreSystem(QObject *parent) : QObject(parent),
    mScore(0),
    mScoreText("Score: %1")
{
    setScore(0);
}

void ScoreSystem::setScore(int score)
{
    mScore += score;
    mScoreText = QString("Score: %1").arg(mScore);
    emit scoreChanged();
}

void ScoreSystem::resetScore() {
    mScore = 0;
    setScore(0);
}



