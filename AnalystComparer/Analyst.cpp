//
// Created by Kimba on 2/2/2017.
//

#include "Analyst.h"
#include "Utils.h"

int Analyst::load(std::ifstream& inputStream)
{
    if (!inputStream.is_open() || inputStream.eof())
    {
        std::cout << "Invalid input file" << std::endl;
        return -1;
    }

    m_name = getTrimmedLine(inputStream);

    if (!inputStream.is_open() || inputStream.eof())
    {
        std::cout << "Input file does not contain initials" << std::endl;
        return -1;
    }

    m_initials = getTrimmedLine(inputStream);

    return m_history.load(inputStream);




}