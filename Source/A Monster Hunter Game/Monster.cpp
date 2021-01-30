#include "Monster.h"
#include "Formula.h"

#include <utility>


Monster::Monster(const int level)
    : Living("Level " + std::to_string(level) + " Monster",
             LevelToAttack(level),
             LevelToDefense(level),
             LevelToHealth(level))
    , Leveled(level)
    , m_material(level)
{}

bool Monster::DefeatedBy(Player& opponent)
{
    if(Living::DefeatedBy(opponent))
    {
        ++opponent.GetMaterialAmount(std::move(m_material));
        return true;
    }
    return false;
}
