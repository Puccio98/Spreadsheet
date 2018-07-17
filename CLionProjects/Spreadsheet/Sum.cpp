//
// Created by davide on 17/07/18.
//

#include "Sum.h"

Sum::Sum(MySpreadsheet* s): subjPtr(s) {
    subjPtr->addObserver(this);
}

Sum::~Sum() {
    subjPtr->removeObserver(this);
}

void Sum::compute() {
    double sum = 0;
    bool b = true;

    for (int i = 0; i < 60; i++)
        if (!subjPtr->getCellsValues()[i].isEmpty) {
            sum = sum + subjPtr->getCellsValues()[i].value;
            b = false;
        }

    if (b)
        subjPtr->results[0]->ChangeValue(wxT("No values"));

    else {

        wxString str = wxString::Format(wxT("%lf"), sum);
        subjPtr->results[0]->ChangeValue(str);

    }

}




