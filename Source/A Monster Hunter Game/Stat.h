#pragma once

#include "Printable.h"

/**
 `Stat` class, inherited from `Printable`, with some operator defined for math operations.
 */
struct Stat : Printable
{
    /**
     Constructor that takes in a string and an int.
     */
    Stat(int stat = 0, std::string name = "");

    /**
     Overriden `Print()` to print both name and value.
     */
    std::ostream& Print(std::ostream& os) const override;
    
    int value;

    /**
     Custom copy assignment operator, to only copy `value`.
     */
    void operator= (const Stat& other);
    
    /**
     Custom and friend math operators to do simple math operations.
     */
    Stat& operator-= (const Stat& other);
    Stat& operator*= (const int multiplier);
    bool operator< (const Stat& other) const;
        
    friend Stat operator- (Stat lhs, const Stat& rhs);
    friend Stat operator* (Stat lhs, int rhs);
    friend Stat operator* (int lhs, Stat rhs);
    friend bool operator< (int lhs, const Stat& rhs);
};

/**
 `Stats` class, that wraps 3 `Stat`, Attack, Defense, Health, into a single object.
 */
struct Stats
{
    Stats(int attack, int defense, int health)
        : attack(attack, "Attack")
        , defense(defense, "Defense")
        , health(health, "Health")
    {}
    
    Stat attack;
    Stat defense;
    Stat health;
};
