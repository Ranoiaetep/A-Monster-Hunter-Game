#include "Forge.h"

#include <iostream>
#include <algorithm>

bool Forge::ForgeEquipment(const int level)
{
    Player& player = Player::GetInstance();
    std::map<Material, int>& materialList = player.GetMaterialList();
    auto it = std::find_if(materialList.begin(), materialList.end(), [level](auto &pair){
        auto & [material, amount] = pair;
        return material.GetLevel() == level;
    });
    if (it != materialList.end())
    {
        auto & [material, amount] = *it;
        if (amount >= kMaterialToEquipmentCost)
        {
            Equipment equipment(level);
            amount -= kMaterialToEquipmentCost;
            player.Equip(equipment);
            m_level = level;
            std::cout << equipment << " forged!\n\n" << player << "\n";
            return true;
        }
    }
    std::cout << "Not enough material\n\n";
    return false;
}
