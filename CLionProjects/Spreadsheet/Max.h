//
// Created by davide on 17/07/18.
//

#ifndef SPREADSHEET_MAX_H
#define SPREADSHEET_MAX_H


#include "Observer.h"
#include "MySpreadsheet.h"

class Max: public Observer {
public:

    explicit Max(MySpreadsheet* s);

    ~Max() override;

    void compute() override;

private:
    MySpreadsheet* subjPtr;
};

#endif //SPREADSHEET_MAX_H
