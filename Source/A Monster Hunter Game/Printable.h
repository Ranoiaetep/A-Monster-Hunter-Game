#pragma once

#include <ostream>

#include "GameObject.h"

/**
 Interface `Printable`, inherited from `GameObject`, that support `operator<<` for ostream output.
 Classes inherited from `Printable` should override `Print()` if need to change the behavior for `operator<<`.
 */
struct Printable : GameObject
{
    /**
     Constructor for `Printable`, takes in the name of the object.
     */
    Printable(const std::string& name);
    
    /**
     `Print` send `m_name` to designated stream.
     Classes inherited from `Printable` should override `Print` to change behavior for `operator<<`.
     */
    virtual std::ostream& Print(std::ostream& os) const;
    
    /**
     friend function `operator<<`, calls `Print()` internally.
     Classes inherited from `Printable` should override `Print` to change behavior for `operator<<` instead.
     */
    friend std::ostream& operator<< (std::ostream& os, const Printable& object);
};
