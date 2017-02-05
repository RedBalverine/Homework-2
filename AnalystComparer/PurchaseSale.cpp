//
// Created by Kimba on 2/2/2017.
//

#include <iostream>
#include <fstream>
#include <string>

#include "PurchaseSale.h"
#include "Utils.h"

PurchaseSale::PurchaseSale(std::ifstream& inputStream)
{
    if(!inputStream.is_open() || inputStream.eof())
    {
        return;
    }

    std::string line = getTrimmedLine(inputStream);

    std::string areas[8];

    if(split(line, ',', areas, 8))
    {
        m_symbol = areas[0];
        m_quantity = std::stoi(areas[1]);
        m_purchaseDateTime = std::stoi(areas[2]);
        m_purchasePrice = std::stoi(areas[3]);
        m_purchaseFee = std::stoi(areas[4]);
        m_saleDateTime = std::stoi(areas[5]);
        m_salePrice = std::stoi(areas[6]);
        m_saleFee = std::stoi(areas[7]);
    }
}

int PurchaseSale::computeInvestmentAmount()
{
    int InvestmentAmount = 0;

    if (m_symbol != "")
    {
        InvestmentAmount = (m_quantity * m_purchasePrice) + m_purchaseFee + m_saleFee;
    }

    return InvestmentAmount;
}

int PurchaseSale::computeProfitLoss()
{
    int ProfitLoss = 0;

    if (m_symbol != "")
    {
        ProfitLoss = (m_salePrice * m_quantity) - computeInvestmentAmount();
    }

    return ProfitLoss;
}

int PurchaseSale::getPurchaseDateTime()
{
    return m_purchaseDateTime;
}

int PurchaseSale::getSaleDateTime()
{
    return m_saleDateTime;
}

std::string PurchaseSale::getSymbol()
{
    return m_symbol;
}