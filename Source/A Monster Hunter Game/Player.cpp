#include "Player.h"

Player::Player(std::string name)
    : Living(name)
    , m_maxStats(m_stats)
    , m_materialList{}
{}

void Player::Equip(const Equipment& equipment)
{
    m_stats = equipment.GetStats();
    m_maxStats = m_stats;
}

int& Player::GetMaterialAmount(Material&& material)
{
    return m_materialList[material];
}

bool Player::DefeatedBy(Living& opponent)
{
    if (Living::DefeatedBy(opponent))
    {
        Reset();
        return true;
    }
    return false;
}

void Player::Reset()
{
    m_stats = m_maxStats;
}

std::ostream& Player::Print(std::ostream& os) const
{
    Living::Print(os);
    os << "\n";
    for(auto [material, number] : m_materialList)
    {
        if (number)
        {
            os << "\t" << material << ":" << number << "\n";
        }
    }
    return os;
}
