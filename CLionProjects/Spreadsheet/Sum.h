//
// Created by davide on 17/07/18.
//

#ifndef SPREADSHEET_SUM_H
#define SPREADSHEET_SUM_H


#include "Observer.h"
#include "MySpreadsheet.h"

class Sum: public Observer {
public:
    Sum(MySpreadsheet* s);

    virtual ~Sum();

    void compute() override;

private:

    MySpreadsheet* subjPtr;

};


#endif //SPREADSHEET_SUM_H
