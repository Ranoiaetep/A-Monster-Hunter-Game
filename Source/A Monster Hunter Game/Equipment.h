#pragma once

#include "Stat.h"
#include "Item.h"
#include "Formula.h"

/**
 `Equipment` class, inherited from `Item` and `Statted`, can be forged from `Material`, and add `Stats` to `Player`.
 `Statted` is calculated by level and functions in `Formula.h`.
 `Player` will take `Equipment`'s stats upon held.
 */
class Equipment : public Item, public Statted
{
public:
    /**
     Constructor taking in the level of the `Equipment`. `Stats` will be calculated by level and functions in `Formula.h`.
     */
    Equipment(const int level)
        : Item("Equipment", level)
        , Statted(LevelToAttack(level),
                  LevelToDefense(level),
                  LevelToHealth(level))
    {}
};
