#include "Dictionary.h"

#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <iterator>

std::string& Dictionary::operator[](std::size_t index)
{
    return m_dictionary[index];
}

std::size_t Dictionary::Size()
{
    return m_dictionary.size();
}

Dictionary::Dictionary()
    : m_fileStream(m_fileName)
    , m_dictionary(std::istream_iterator<std::string>(m_fileStream),
                   std::istream_iterator<std::string>())
{
    m_fileStream.close();
}
