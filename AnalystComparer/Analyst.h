//
// Created by Kimba on 2/2/2017.
//

#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H

#include <string>
#include <fstream>

#include "History.h"
#include "PurchaseSale.h"

class Analyst {

private:
    std::string m_name;
    std::string m_initials;
    History m_history;

public:
    int load(std::ifstream& inputStream);
    float getStockProformence(std::string symbol);

    std::string getName()
    {
        return m_name;
    }

    std::string getInitials()
    {
        return m_initials;
    }

    History getHistory()
    {
        return m_history;
    }

};


#endif //ANALYSTCOMPARER_ANALYST_H
