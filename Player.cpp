#include "Player.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const char* LINE_DIVIDER  = "------------------------";
const int INITIAL_LEVEL=1;
const int INITIAL_COINS=0;
const int FINAL_LEVEL=10;

Player::Player(std::string name, int maxHp, int maxForce)
{
    m_name=name;
    m_level=INITIAL_LEVEL;     ///////////////////////////////////////////////////////////////
    m_force=maxForce;
    m_maxHp=maxHp;
    m_Hp=maxHp;
    m_coins=INITIAL_COINS;    ///////////////////////////////////////////////////////////////
}

void Player::printInfo() const
{
    cout << "Player Details:" << endl;
    cout << "Name: " << m_name << endl;
    cout << "Level: " << m_level << endl;
    cout << "Force: " << m_force << endl;
    cout << "HP: " << m_Hp << endl;
    cout << "Coins: " << m_coins << endl;
    cout << LINE_DIVIDER << endl;
}

void Player::levelUp()
{
  m_level + = (m_level == FINAL_LEVEL) ? 0 : 1;
}

int Player::getLevel()
{
    return m_level;
}