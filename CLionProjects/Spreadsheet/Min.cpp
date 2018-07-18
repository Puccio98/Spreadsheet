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
        if (!subjPtr->getValues()[i].isEmpty) {
            min = subjPtr->getValues()[i].value;
            b = false;
        }
        i++;
    }

    if (b)
        subjPtr->getResults()[3]->ChangeValue(wxT("No values"));

    else {
        while (i < subjPtr->getNumOfCells()) {

            if (!subjPtr->getValues()[i].isEmpty)
                if (subjPtr->getValues()[i].value < min)
                    min = subjPtr->getValues()[i].value;
            i++;
        }

        wxString str = wxString::Format(wxT("%lf"), min);
        subjPtr->getResults()[3]->ChangeValue(str);

    }
}
