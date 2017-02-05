//
// Created by Kimba on 2/2/2017.
//

#include <iostream>
#include <fstream>
#include <mftransform.h>


#include "History.h"
#include "PurchaseSale.h"
#include "Utils.h"


int History::loadPurchaseSales(std::ifstream& inputStream)
{
    m_purchaseSales = new PurchaseSale*[m_purchaseSalesCount];

    for (int i = 0; i < m_purchaseSalesCount; i++)
    {
        m_purchaseSales[i] = nullptr;
    }

    int recordsRead = 0;
    int recordsLoaded = 0;

    while(recordsRead < m_purchaseSalesCount && inputStream.is_open() && !inputStream.eof())
    {
        PurchaseSale* purchaseSale = new PurchaseSale(inputStream);
        if (purchaseSale->getSymbol() != "")
        {
            m_purchaseSales[recordsLoaded++] = purchaseSale;
        }
        recordsRead++;
    }

    int result = 0;
    if (recordsLoaded < m_purchaseSalesCount)
    {
        result = -1;
    }
    return result;
}

int History::load(std::ifstream& inputStream)
{
    if(!inputStream.is_open() || inputStream.eof())
    {
        std::cout << "Input file does not contain simulation days" << std::endl;
        return -1;
    }

    std::string line = getTrimmedLine(inputStream);
    m_simulationDays = std::stoi(line);

    if(!inputStream.is_open() || inputStream.eof())
    {
        std::cout << "Input file does not initial money amount" << std::endl;
        return -1;
    }

    line = getTrimmedLine(inputStream);
    m_seedMoney = std::stoi(line);

    if(!inputStream.is_open() || inputStream.eof())
    {
        std::cout << "Input file does not purchase-sales count" << std::endl;
        return -1;
    }

    line = getTrimmedLine(inputStream);
    m_purchaseSalesCount = std::stoi(line);

    return loadPurchaseSales(inputStream);
}

int History::getSimulationDays()
{
    return m_simulationDays;
}

int History::getInitialMoney()
{
    return m_seedMoney;
}



int History::computeTotalProfitLoss(std::ifstream& inputStream)
{
    m_purchaseSales = new PurchaseSale*[m_purchaseSalesCount];

    for (int i = 0; i < m_purchaseSalesCount; i++)
    {
        m_purchaseSales[i] = nullptr;
    }

    int recordsRead = 0;
    int recordsLoaded = 0;

    while(recordsRead < m_purchaseSalesCount && inputStream.is_open() && !inputStream.eof())
    {
        PurchaseSale* purchaseSale = new PurchaseSale(inputStream);
        if (purchaseSale->getSymbol() != "")
        {
            m_purchaseSales[recordsLoaded++] = purchaseSale;
            int temp = m_purchaseSales[recordsLoaded]->computeProfitLoss();
            int totalProfitLoss;
            totalProfitLoss += temp;
            return totalProfitLoss;
        }
        recordsRead++;

    }
}

int History::computeProfitLossPerDay(std::ifstream& inputStream)
{
    int temp;

    load(inputStream);
    int ProLossPD;
    temp = computeTotalProfitLoss(inputStream);

    ProLossPD = temp / m_simulationDays;

    return ProLossPD;
}