#pragma once

#include "Living.h"
#include "Equipment.h"
#include "Material.h"

#include <map>

/**
 `Player` class, a singleton class inherited from `Living`.
 It can `Equip()` to get better `Stats`, and have a `map<Material, int>` to track materials it have gathered.
 */
class Player : public Living
{
public:
    /**
     static GetInstance() as of singleton pattern.
     */
    static Player& GetInstance()
    {
        static Player instance;
        return instance;
    }
    
    /**
     Equip() will change `Stats` to the `Equipment`'s `Stats`.
     */
    void Equip(const Equipment& equipment);
    
    /**
     Get access to int from `m_materialList` based on the `Material` passed in.
     */
    int& GetMaterialAmount(Material&& material);
    
    /**
     Overriden `Print()` to also print materials the player have.
     */
    std::ostream& Print(std::ostream& os) const override;
    
    /**
     Return `m_materialList` by reference.
     */
    std::map<Material, int>& GetMaterialList() { return m_materialList; }
    
    /**
     Overriden `DefeatedBy()` to also reset `Stats` to its max value.
     */
    bool DefeatedBy(Living& opponent) override;
    
    /**
     Reset `Stats` to its max value.
     */
    void Reset();

    /**
     Deleted copy constructor and copy assignment operator as of singleton pattern.
     */
    Player(Player const&) = delete;
    void operator=(Player const&) = delete;
private:
    /**
     Private default constructor as of singleton pattern.
     */
    Player(std::string name = "Player");
    Stats m_maxStats;
    std::map<Material, int> m_materialList;
};
