#include "Arena.h"
#include "Dictionary.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <cstdlib>

Arena::Arena(const int level)
    : Leveled(level)
    , m_monster(level)
{}

bool Arena::Proceed()
{
    Player& player = Player::GetInstance();
    Dictionary& dictionary = Dictionary::GetInstance();
    std::cout << "\n" << player << "\n" << m_monster << "\n\n";
    bool result = false;
    while (!player.DefeatedBy(m_monster) && !m_monster.DefeatedBy(player))
    {
        std::string& prompt = dictionary[std::rand() % dictionary.Size()];
        std::cout << prompt << "\n";
        std::string input = *std::istream_iterator<std::string>(std::cin);
        std::cout << "\n";
        if(prompt == input)
        {
            player.Attack(m_monster, prompt.size());
            result = true;
        }
        else
        {
            m_monster.Attack(player, std::ceil(prompt.size() / 4.));
            result = false;
        }
        std::cout << player << "\n" << m_monster << "\n\n";
    }
    result ? std::cout << "You won the fight!\n\n" << player
    : std::cout << "You lose the fight!\n";
    std::cout << "\n";
    player.Reset();
    return result;
}
