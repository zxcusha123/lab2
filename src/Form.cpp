#include "Form.h"

#include <cmath>
#include <iostream>

static void fill(char* str, unsigned int len, char c) {
    for (unsigned int i = 0; i < len; ++i) {
        str[i] = c;
    }
    str[len] = '\0'; // Тот самый терминальный ноль
}

void Triangle::draw() const
{
    char spaces[m_offset + 1];
    char top[m_leg_length + 1];

    fill(spaces, m_offset, ' ');
    fill(top, m_leg_length, '_');
        
    
    std::cout << spaces << '|' << top << std::endl;
    
    for(int i=0; i < m_leg_length; i++)
    {
        std::cout << spaces;
        std::cout << '|';
        for (int j=0; j < m_leg_length - i - 1; ++j)
            std::cout << ' ';
        std::cout << '/' << std::endl;
    }

}

void Circle::draw() const
{
    char spaces[m_offset + 1];

    fill(spaces, m_offset, ' ');
    
    const unsigned int diameter = 2 * m_radius;
    const unsigned int radiusSquared = m_radius * m_radius;
    
    for(int iRow = 0; iRow < diameter; ++iRow)
    {
        std::cout << spaces;
        for(int iCol = 0; iCol < diameter; ++iCol)
        {
            int x = iCol - m_radius;
            int y = iRow - m_radius;
            bool isInside = (x*x + y*y) <= radiusSquared;
            std::cout << (isInside ? '*' : ' ');
        }
        std::cout << std::endl;
    }

}