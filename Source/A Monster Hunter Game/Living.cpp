#include "Living.h"

Living::Living(const std::string& name, int baseAttack, int baseDefense, int baseHealth)
    : Printable(name)
    , Statted(baseAttack, baseDefense, baseHealth)
{}

std::ostream& Living::Print(std::ostream &os) const
{
    os << m_name << "\n";
    os << m_stats.health << ", " << m_stats.attack << ", " << m_stats.defense;
    return os;
}

void Living::Attack(Living& opponent, std::size_t multiplier)
{
    opponent.m_stats.health -= (m_stats.attack - (opponent.m_stats.defense - 1)) * int(multiplier);
}

bool Living::DefeatedBy(Living& opponent)
{
    return !(0 < m_stats.health);
}
