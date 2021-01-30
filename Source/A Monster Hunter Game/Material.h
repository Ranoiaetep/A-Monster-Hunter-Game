#pragma once

#include "Item.h"

/**
 `Material` class, inherited from `Item`, can be droped by `Monster` and pickup by `Player`, can later be forged to `Equipment` in `Forge`.
 */
class Material : public Item
{
public:
    /**
     Constructor takes in the level of the material.
     */
    Material(const int level)
        : Item("Material", level)
    {}
};
