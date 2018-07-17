//
// Created by davide on 17/07/18.
//

#include "Min.h"

Min::Min(MySpreadsheet *s):subjPtr(s) {
    subjPtr->addObserver(this);
}

Min::~Min() {
    subjPtr->removeObserver(this);
}

void Min::compute() {
    double min = 0;
    bool b = true;
    int i = 0;

    while (i < subjPtr->getNumOfCells() && b) {
        if (!subjPtr->getCellsValues()[i].isEmpty) {
            min = subjPtr->getCellsValues()[i].value;
            b = false;
        }
        i++;
    }

    if (b)
        subjPtr->results[3]->ChangeValue(wxT("No values"));

    else {
        while (i < subjPtr->getNumOfCells()) {

            if (!subjPtr->getCellsValues()[i].isEmpty)
                if (subjPtr->getCellsValues()[i].value < min)
                    min = subjPtr->getCellsValues()[i].value;
            i++;
        }

        wxString str = wxString::Format(wxT("%lf"), min);
        subjPtr->results[3]->ChangeValue(str);

    }
}
