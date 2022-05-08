#ifndef PLAYER_H
#define PLAYER_H
#include<string>


class Player
{
private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_Hp;
    int m_coins;
    
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_MAX_FORCE = 5;

public:
    Player(std::string name, int maxHp = DEFAULT_MAX_HP, int maxForce = DEFAULT_MAX_FORCE);
    Player(const Player& other) = default; /////////////////////////////////////////////////////////////////////////////////
    void operator=(const Player& other);  //////////////////////////////////////////////////////////////////////////////////
    ~Player() = default;
    
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int force);
    void heal(int hpBoost);
    void damage(int hpDamage);
    bool isKnockedOut() const;
    void addCoins(int coins);
    bool pay(int payment);
    int getAttackStrength() const;
};

#endif