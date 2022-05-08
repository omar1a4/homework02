#include "Player.h"
#include <iostream>
#include <cassert>
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
    m_level=INITIAL_LEVEL;
    m_force=maxForce;
    m_maxHp=maxHp;
    m_Hp=maxHp;
    m_coins=INITIAL_COINS;
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
    m_level += (m_level == FINAL_LEVEL) ? 0 : 1;
}

int Player::getLevel()const
{
    return m_level;
}
void Player::buff(int force)
{
    assert(force>0);
    m_force+=force;
}
void Player::heal(int hpBoost)
{
    assert(hpBoost>0);
    m_Hp+=hpBoost;
   if (m_Hp>m_maxHp)
   {
       m_Hp=m_maxHp;
   }
}
void Player::damage(int hpDamage)
{
    assert(hpDamage>0);
    m_Hp-=hpDamage;
    if(m_Hp<0)
    {
        m_Hp=0;
    }
}
bool Player::isKnockedOut()const
{
    if (m_Hp==0)
    {
        return  true;
    }
    return false;
}
void Player::addCoins(int coins)
{
    assert(coins>0);
    m_coins+=coins;
}
bool Player::pay(int payment)
{
    assert(payment>0);
    if (m_coins>=payment)
    {
        m_coins-=payment;
        return true;
    }
    return false;
}
int Player::getAttackStrength() const
{
    return m_level+m_force;
}

