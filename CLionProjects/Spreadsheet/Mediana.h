//
// Created by davide on 17/07/18.
//

#ifndef SPREADSHEET_MEDIANA_H
#define SPREADSHEET_MEDIANA_H

#include "MySpreadsheet.h"

class Mediana: public Observer {

public:
    explicit Mediana(MySpreadsheet* s);

    ~Mediana() override;

    void compute() override;

private:
    MySpreadsheet* subjPtr;
};


#endif //SPREADSHEET_MEDIANA_H
