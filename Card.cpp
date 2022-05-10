#include "Card.h"



Card::Card(CardType type, const CardStats& stats): m_effect(type), m_stats(stats)
{
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