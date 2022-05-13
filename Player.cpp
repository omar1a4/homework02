#include "Player.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const char* LINE_DIVIDE  = "------------------------";

void Player::printInfo() const
{
    cout << "Player Details:" << endl;
    cout << "Name: " << m_name << endl;
    cout << "Level: " << m_level << endl;
    cout << "Force: " << m_force << endl;
    cout << "HP: " << m_Hp << endl;
    cout << "Coins: " << m_coins << endl;
    cout << LINE_DIVIDE << endl;
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
    if(force<0)
    {
        return;
    }
    m_force+=force;
}
void Player::heal(int hpBoost)
{
    if (hpBoost<=0)
    {
        return;
    }
    m_Hp+=hpBoost;
    if (m_Hp>m_maxHp)
    {
        m_Hp=m_maxHp;
    }
}
void Player::damage(int hpDamage)
{
    if(hpDamage<=0)
    {
        return;
    }
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
    if (coins<=0)
    {
        return;
    }
    m_coins+=coins;
}
bool Player::pay(int payment)
{
    if(payment<=0)
    {
        return true ;
    }
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
