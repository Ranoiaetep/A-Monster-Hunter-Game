#pragma once

#include "Living.h"
#include "Player.h"
#include "Material.h"
#include "Leveled.h"

/**
 `Monster` class, inherited from `Living` and `Leveled`.
 `Statted` is calculated by level and functions in `Formula.h`, and it creates a `Material` based on the level.
 The `Material` will be given to `Player` if it is defeated by a `Player`.
 */
class Monster : public Living, Leveled
{
public:
    /**
     Constructor takes in the level, and the `Stats` are calculated by level and functions in `Formula.h`.
     */
    Monster(const int level);
    
    /**
     Returns true if it is defeated by a `Player`, and it will give the `Material` to the `Player`.
     */
    bool DefeatedBy(Player& opponent);
private:
    Material m_material;
};
