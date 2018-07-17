//
// Created by davide on 10/07/18.
//

#ifndef SPREADSHEET_DATACALCULATION_H
#define SPREADSHEET_DATACALCULATION_H

#include <memory>
#include "MySpreadsheet.h"

class ResultCalculation : public Observer {
public:
    explicit ResultCalculation(MySpreadsheet *su);

    ~ResultCalculation() override;

    bool checkString(int i);


private:

    double sum();

    void media(double sum);

    void max();

    void min();

    void mediana();

};


#endif //SPREADSHEET_DATACALCULATION_H
