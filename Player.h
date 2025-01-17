#ifndef PLAYER_H
#define PLAYER_H
#include<string>

const int INITIAL_COINS=0;
const int INITIAL_LEVEL=1;
const int FINAL_LEVEL=10;

class Player
{

public:
    /*
     * C'tor of Player class
     *
     * @param name - The player name.
     * @param maxHp - The max value of health points.
     * @param maxforce - The maximum desired player force.
     * @return
     *      A new instance of Player.
    */
    Player(std::string name, int maxHp = DEFAULT_MAX_HP, int maxForce = DEFAULT_MAX_FORCE):
    m_name(name),m_level(INITIAL_LEVEL),m_force(maxForce),m_maxHp(maxHp),m_Hp(maxHp),m_coins(INITIAL_COINS)
    {
        if(m_force<=0)
        {
            m_force=DEFAULT_MAX_FORCE;
        }
        if(m_maxHp<=0)
        {
            m_maxHp=DEFAULT_MAX_FORCE;
        }
    }

    /*
     * Default copy c'tor.
    */
    Player(const Player& other) = default;

    /*
     * Default assignment operator.
     */
    Player& operator=(const Player& other)=default;

    /*
     * Default d'tor
     */
    ~Player() = default;

    /*
    * Prints the details of the player.
    *
    * @return
    *      void
    */
    void printInfo() const;


    /*
     * Raises the level of the player by 1.
     *
     * @return
     *      void
     */
    void levelUp();

    /*
     * Returns the player level.
     *
     * @return
     *      The player's level.
     */
    int getLevel() const;

    /*
     * Raises the player's power points.
     * @param force - The desired force boost.
     *
     * @return
     *      void
     */
    void buff(int force);

    /*
     * Increases the player's health points.
     * @param hpBoost - The health points to be added to the player's Hp.
     *
     * @return
     *      void
     */
    void heal(int hpBoost);


    /*
     * Decreases the player's health points.
     * @param hpDamage - The health points to be reduced from the player's Hp.
     *
     * @return
     *      void
     */
    void damage(int hpDamage);

    /*
     * Checks if the health points of the player is zero.
     *
     * @return
     *     true -if the player's HP is zero.
     *     false -otherwise.
     */
    bool isKnockedOut() const;

    /*
     * Add coins to the player's total coins.
     * @param coins - The coins to be added to the player's total coins.
     *
     * @return
     *      void
     */
    void addCoins(int coins);


    /*
     * Lowers the player's coins.
     * @param payment - The amount the player should pay.
     *
     * @return
     *      true: if the player had enough coins to pay.
     *      false: otherwise.
     */
    bool pay(int payment);

    /*
     * Returns the attack strength.
     *
     * @return
     *      The player's level + the player's force.
     */
    int getAttackStrength() const;

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_Hp;
    int m_coins;

    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_MAX_FORCE = 5;
};

#endif
