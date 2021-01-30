#pragma once

#include "Printable.h"
#include "Leveled.h"

/**
 Interface `Item`, inherited from `Printable` and `Leveled`,  with `operator==` defined.
 */
struct Item : Printable, Leveled
{
    /**
     Constructor for `Item`, that takes in the name and level of the item.
     */
    Item(std::string name = "N/A" , const int level = 0);
    
    /**
     Custom `operator==` that compares by name.
     */
    virtual bool operator== (const Item& other) const;
};
