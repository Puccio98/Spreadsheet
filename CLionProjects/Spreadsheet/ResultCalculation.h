//
// Created by davide on 10/07/18.
//

#ifndef SPREADSHEET_DATACALCULATION_H
#define SPREADSHEET_DATACALCULATION_H


#include "Observer.h"
#include "MySpreadsheet.h"

class ResultCalculation : public Observer {
public:
    explicit ResultCalculation(MySpreadsheet *su);

    ~ResultCalculation() override;

    void update() override;

    void media();

private:
    MySpreadsheet *sub;
};


#endif //SPREADSHEET_DATACALCULATION_H
