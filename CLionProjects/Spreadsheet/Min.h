//
// Created by davide on 17/07/18.
//

#ifndef SPREADSHEET_MIN_H
#define SPREADSHEET_MIN_H


#include "Observer.h"
#include "MySpreadsheet.h"

class Min: public Observer {
public:
    explicit Min(MySpreadsheet* s);

    ~Min() override;

    void compute() override;

private:
    MySpreadsheet* subjPtr;
};


#endif //SPREADSHEET_MIN_H
