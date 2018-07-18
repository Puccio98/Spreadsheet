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
        if (!subjPtr->getValues()[i].isEmpty) {
            sum = sum + subjPtr->getValues()[i].value;
            b = false;
        }

    if (b)
        subjPtr->getResults()[0]->ChangeValue(wxT("No values"));

    else {

        wxString str = wxString::Format(wxT("%lf"), sum);
        subjPtr->getResults()[0]->ChangeValue(str);

    }

}

