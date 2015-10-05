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
    mScoreText = mScoreText.arg(mScore);
    emit scoreChanged();
}

void ScoreSystem::resetScore() {
    mScore = 0;
    setScore(0);
}



