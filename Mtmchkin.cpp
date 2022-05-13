#include "Mtmchkin.h"


Mtmchkin :: Mtmchkin(const std::string playerName, const Card* cardsArray, int numOfCards)
        : m_cardsArray(new Card[numOfCards]),m_numOfCards(numOfCards) ,
          m_gameStatus(GameStatus::MidGame),m_nextCardIndex(0), m_player(playerName)
{
    for (int i=0; i<numOfCards; i++)
    {
        m_cardsArray[i]=cardsArray[i];
    }
}

Mtmchkin ::Mtmchkin(const Mtmchkin& game)
        : m_cardsArray(new Card[game.m_numOfCards]), m_numOfCards(game.m_numOfCards) ,
          m_gameStatus(game.m_gameStatus),m_nextCardIndex(game.m_nextCardIndex), m_player(game.m_player)
{
    for (int i=0; i<game.m_numOfCards; i++)
    {
        m_cardsArray[i]=game.m_cardsArray[i];
    }
}

Mtmchkin ::~Mtmchkin()
{
    delete[] m_cardsArray;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game)
{
    if (this == &game)
    {
        return *this;
    }
    m_player=game.m_player;
    delete[] m_cardsArray;
    m_cardsArray=new Card [game.m_numOfCards];
    m_numOfCards=game.m_numOfCards;
    m_nextCardIndex=game.m_nextCardIndex;
    for (int i=0; i<game.m_numOfCards; i++)
    {
        m_cardsArray[i]=game.m_cardsArray[i];
    }
    return *this;
}


GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}

void Mtmchkin::playNextCard()
{
    Card nextCard=m_cardsArray[m_nextCardIndex];
    nextCard.printInfo();
    nextCard.applyEncounter(m_player);
    m_player.printInfo();
    if(m_player.getLevel()==FINAL_LEVEL)
    {
        m_gameStatus=GameStatus::Win;
    }
    if(m_player.isKnockedOut())
    {
        m_gameStatus=GameStatus::Loss;
    }
    m_nextCardIndex++;
    if(m_nextCardIndex==m_numOfCards)
    {
        m_nextCardIndex=0;
    }
}
bool Mtmchkin:: isOver() const
{
    if((m_gameStatus==GameStatus::Win) || (m_gameStatus==GameStatus::Loss))
    {
        return true;
    }
    return false;
}
