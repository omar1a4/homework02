#include "Card.h"



Card::Card(CardType type, const CardStats& stats): m_effect(type), m_stats(stats)
{
}

void Card :: applyEncounter(Player& player) const
{
    if (m_effect == CardType::Battle)
    {
       if(player.getAttackStrength() >= m_stats.force)
       {
           player.levelUp();
           player.addCoins(m_stats.loot);
       }
       else
       {
           player.damage(m_stats.hpLossOnDefeat);
       }
    }
    if (m_effect == CardType ::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
    }
    if (m_effect == CardType ::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.buff);
        }
    }
    if (m_effect == CardType ::Treasure)
    {
       player.addCoins(m_stats.loot);
    }

}

void Card::printInfo() const
{
    if(m_effect == CardType::Battle)
    {
        printBattleCardInfo(m_stats);
    }
    else if(m_effect == CardType::Buff)
    {
        printBuffCardInfo(m_stats);
    }
    else if(m_effect == CardType::Heal)
    {
        printHealCardInfo(m_stats);
    }
    else if(m_effect == CardType::Treasure)
    {
        printTreasureCardInfo(m_stats);
    }
}
