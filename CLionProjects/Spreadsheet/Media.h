//
// Created by davide on 17/07/18.
//

#ifndef SPREADSHEET_MEDIA_H
#define SPREADSHEET_MEDIA_H


#include "MySpreadsheet.h"

class Media: public Observer {
public:
    explicit Media(MySpreadsheet* s);

    ~Media() override;

    void compute() override;

private:

    MySpreadsheet* subjPtr;

};


#endif //SPREADSHEET_MEDIA_H
