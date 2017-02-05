//
// Created by Kimba on 2/2/2017.
//

#ifndef ANALYSTCOMPARER_HISTORY_H
#define ANALYSTCOMPARER_HISTORY_H

#include <iostream>
#include <fstream>
#include "PurchaseSale.h"

class History
{
private:
    int m_simulationDays;
    int m_seedMoney;
    PurchaseSale** m_purchaseSales = nullptr;
    int m_purchaseSalesCount;
    int m_currentPurchaseSale;

public:
    int load(std::ifstream& inputStream);
    PurchaseSale** loadPurchaseSales(std::ifstream& inputStream);

    int getSimulationDays();

    int getInitialMoney();

    int computeTotalProfitLoss(std::ifstream& inputStream);
    int computeProfitLossPerDay(std::ifstream& inputStream);
    PurchaseSale nextPurchaseSale();




};


#endif //ANALYSTCOMPARER_HISTORY_H
