#pragma once

/**
 Interface `Leveled`, that takes in a int for level, and support `operator<`.
 */
struct Leveled
{
    /**
     Constructor that takes in the level.
     */
    Leveled(const int level)
        : m_level(level)
    {}
    
    /**
     Return the level as int.
     */
    const int GetLevel() const { return m_level; }
    
    /**
     Custom `operator<` that compare by level.
     */
    virtual bool operator< (const Leveled& other) const
    {
        return m_level < other.m_level;
    }
protected:
    int m_level;
};
