#include "Item.h"

#include <functional>

Item::Item(const std::string& name, const int level)
    : Printable("Level " + std::to_string(level) + " " + name)
    , Leveled(level)
{}

bool Item::operator==(const Item& other) const
{
    return other.m_name == m_name;
}
