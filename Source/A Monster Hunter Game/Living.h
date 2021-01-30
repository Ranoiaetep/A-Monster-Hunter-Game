#pragma once

#include "Printable.h"
#include "Stat.h"
#include "Statted.h"

#include <cstddef>

/**
 Interface `Living`, inherited from `Printable` and `Statted`. It can `Attack()` and `DefeatedBy()` another `Living`.
 */
struct Living : Printable, Statted
{
    /**
     Constructor that takes in name and base attack, defense, and health for `Stats`.
     */
    Living(const std::string& name, int baseAttack = 1, int baseDefense = 0, int baseHealth = 10);
    
    /**
     Overriden `Print()` to also print the `Stats`.
     */
    std::ostream & Print(std::ostream &os) const override;
    
    /**
     `Attack` will deal damage to the opponent `Living`.
     */
    void Attack(Living& opponent, std::size_t multiplier = 1);
    
    /**
     Returns true if health goes to 0 or below.
     */
    virtual bool DefeatedBy(Living& opponent);
};
