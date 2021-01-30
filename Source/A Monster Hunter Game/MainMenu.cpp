#include "MainMenu.h"
#include "Formula.h"

bool MainMenu::Proceed()
{
    std::cout << "Choose your option:\n";
    std::cout << "\tA. go to arena\n";
    std::cout << "\tF. go to forge\n";
    std::cout << "\tQ. quit\n";
    switch (std::toupper(*std::istream_iterator<unsigned char>(std::cin)))
    {
        case 'A':
            ToArena();
            break;
        case 'F':
            ToForge();
            break;
        case 'Q':
            return false;
        default:
            break;
    }
    return true;
}

void MainMenu::ToArena()
{
    std::cout << "Enter the level you want to proceed (max " << m_maxLevel<< "): ";
    if(int level = *std::istream_iterator<int>(std::cin); level <= m_maxLevel)
    {
        Arena arena(level);
        if(arena.Proceed() && level == m_maxLevel)
        {
            ++m_maxLevel;
        }
    }
    else
    {
        ToArena();
    }
}

void MainMenu::ToForge()
{
    Player& player = Player::GetInstance();
    Forge& forge = Forge::GetInstance();
    for(auto &[material, amount] : player.GetMaterialList())
    {
        if (material.GetLevel() > forge.GetMaxLevel())
        {
            std::cout << material.GetLevel() << ". " << Equipment(material.GetLevel()) << " is available, you have " << amount << "/" << kMaterialToEquipmentCost << " materials.\n";
        }
    }
    if (player.GetMaterialList().size())
    {
        std::cout << "\nChoose one you would like to purchase: ";
        if(int level = *std::istream_iterator<int>(std::cin); level <= m_maxLevel)
        {
            forge.ForgeEquipment(level);
        }
    }
    else
    {
        std::cout << "\nNo available items!";
    }
}
