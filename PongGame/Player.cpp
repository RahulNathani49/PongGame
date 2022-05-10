#include "Player.h"
Player::Player(int score)
    :score(0)
{

}

int Player::getScore()
{
    return score;
}

void Player::setScore(int score)
{
    this->score = score;
}
