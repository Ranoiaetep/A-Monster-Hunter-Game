#include "Printable.h"

Printable::Printable(const std::string& name)
    : GameObject{name}
{}

std::ostream & Printable::Print(std::ostream &os) const
{
    return os << m_name;
}

std::ostream& operator<< (std::ostream& os, const Printable& object)
{
    return object.Print(os);
}
