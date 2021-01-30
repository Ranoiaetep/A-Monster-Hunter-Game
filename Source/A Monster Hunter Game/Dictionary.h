#pragma once

#include <string>
#include <vector>
#include <cstddef>
#include <fstream>

/**
 A singleton class `Dictionary`, stores words from a tsv file into a vector upon initialized.
 */
struct Dictionary
{
    /**
     static GetInstance() as of singleton pattern.
     */
    static Dictionary& GetInstance()
    {
        static Dictionary instance;
        return instance;
    }
    
    /**
     Use operator[] to get direct access to underlying `vector<string> m_dictionary`.
     */
    std::string& operator[](std::size_t index);
    
    /**
     Return the size of underlying `vector<string> m_dictionary`.
     */
    std::size_t Size();
    
    /**
     Deleted copy constructor and copy assignment operator as of singleton pattern.
     */
    Dictionary(Dictionary const&) = delete;
    void operator=(Dictionary const&) = delete;

private:
    std::string m_fileName = "Dictionary";
    std::fstream m_fileStream;
    std::vector<std::string> m_dictionary;
    
    /**
     Private default constructor as of singleton pattern.
     */
    Dictionary();
};
