//
// Created by davide on 10/07/18.
//

#ifndef SPREADSHEET_DATACALCULATION_H
#define SPREADSHEET_DATACALCULATION_H

#include "MySpreadsheet.h"

class ResultCalculation : public Observer {
public:
    explicit ResultCalculation(MySpreadsheet *su);

    ~ResultCalculation() override;
    void update() override;

    void media();

    void sum();

private:
    MySpreadsheet *subjPtr;
    double * cellsValues;
};


#endif //SPREADSHEET_DATACALCULATION_H
