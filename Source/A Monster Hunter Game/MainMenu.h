#pragma once

#include "Arena.h"
#include "Forge.h"

#include <iostream>
#include <iterator>
#include <cctype>

/**
 The main interface player will encounter with. It can then guide player to either `Arena` or `Forge`.
 */
class MainMenu
{
public:
    MainMenu() = default;
    
    /**
     Display main menu, and guide player to either `Arena` or `Forge`, and return false if player wants to quit.
     */
    bool Proceed();
    
    /**
     Display menu for arena, and proceed to arena functions.
     */
    void ToArena();
    
    /**
     Display menu for forge, and proceed to forge functions.
     */
    void ToForge();
private:
    /**
     Remembers the max level player has access to so far.
     */
    int m_maxLevel = 1;
};
