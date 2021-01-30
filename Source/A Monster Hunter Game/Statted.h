#pragma once

#include "Stat.h"

/**
 Interface `Statted`, that contains a `Stats`, and support `Stats& GetStats()` and `Stats GetStats() const`.
 */
struct Statted
{
    Statted(int attack, int defense, int health)
        : m_stats(attack, defense, health)
    {}
    
    Stats& GetStats() { return m_stats; }
    Stats GetStats() const { return m_stats; }
protected:
    Stats m_stats;
};
