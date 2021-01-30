#pragma once

#include "Player.h"
#include "Formula.h"
#include "Leveled.h"

/**
 A singleton class `Forge`, where player forge `Equipment` with thier `Material`.
 */
class Forge : public Leveled
{
public:
    /**
     static GetInstance() as of singleton pattern.
     */
    static Forge& GetInstance()
    {
        static Forge instance;
        return instance;
    }
    
    /**
     Forge `Equipment` from `Material` based on `level`, return true if forge successfully, or false if not.
     */
    bool ForgeEquipment(const int level);
    
    /**
     Return the max level of `Equipment` player can forge so far.
     */
    const int GetMaxLevel() const { return m_level; }
    
    /**
     Deleted copy constructor and copy assignment operator as of singleton pattern.
     */
    Forge(Forge const&) = delete;
    void operator=(Forge const&) = delete;
private:
    /**
     Private default constructor as of singleton pattern.
     */
    Forge()
    : Leveled(0)
    {}
};
