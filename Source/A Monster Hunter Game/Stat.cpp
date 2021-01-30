#include "Stat.h"

Stat::Stat(int stat, const std::string& name)
    : Printable(name)
    , value(stat)
{}

std::ostream& Stat::Print(std::ostream& os) const
{
    return os << m_name << ":" << value;
}

void Stat::operator= (const Stat& other)
{
    value = other.value;
}

Stat& Stat::operator-= (const Stat& other)
{
    value -= other.value;
    return *this;
}

Stat operator- (Stat lhs, const Stat& rhs)
{
    return lhs -= rhs;
}

Stat& Stat::operator*= (const int multiplier)
{
    value *= multiplier;
    return *this;
}

Stat operator* (Stat lhs, int rhs)
{
    return lhs *= rhs;
}

Stat operator* (int lhs, Stat rhs)
{
    return rhs *= lhs;
}

bool Stat::operator< (const Stat& other) const
{
    return value < other.value;
}

bool operator< (int lhs, const Stat& rhs)
{
    return lhs < rhs.value;
}
