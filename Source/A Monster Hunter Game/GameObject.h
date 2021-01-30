#pragma once

#include <string>

/**
 Interface `GameObject`, contents only the name of the object, with most object classes inherited from this interface.
 */
struct GameObject
{
    std::string m_name;
};
