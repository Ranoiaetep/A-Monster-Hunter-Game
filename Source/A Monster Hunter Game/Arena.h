#pragma once

#include "Monster.h"
#include "Leveled.h"

/**
 `Arena` class, inherited from `Leveled`.
 It will create a `Monster` based on level, and `Player` will fight that `Monster`.
 */
class Arena : Leveled
{
public:
    /**
     Constructor that takes in the level.
     */
    Arena(const int level);
    
    /**
     `Player` will fight the `Monster`, until one of them is dead.
     */
    bool Proceed();    
private:
    Monster m_monster;
};
