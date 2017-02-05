//
// Created by Kimba on 2/2/2017.
//

#ifndef ANALYSTCOMPARER_PURCHASESALE_H
#define ANALYSTCOMPARER_PURCHASESALE_H

#include <iostream>
#include <fstream>
#include <string>

class PurchaseSale {

private:
    std::string m_symbol;
    int m_quantity;
    int m_purchaseDateTime;
    int m_purchasePrice;
    int m_purchaseFee;
    int m_saleDateTime;
    int m_salePrice;
    int m_saleFee;

public:
    PurchaseSale(std::ifstream& inputStream);

    std::string getSymbol();

    int getPurchaseDateTime();

    int getSaleDateTime();

    int computeInvestmentAmount();
    int computeProfitLoss();



};


#endif //ANALYSTCOMPARER_PURCHASESALE_H
