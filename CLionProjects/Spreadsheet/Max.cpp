//
// Created by davide on 17/07/18.
//

#include "Max.h"

Max::Max(MySpreadsheet *s): subjPtr(s) {
    subjPtr->addObserver(this);
}

Max::~Max() {
    subjPtr->removeObserver(this);
}

void Max::compute() {
    double max = 0;
    bool b = true;
    int i = 0;

    while (i < subjPtr->getNumOfCells() && b) {
        if (!subjPtr->getValues()[i].isEmpty) {
            max = subjPtr->getValues()[i].value;
            b = false;
        }
        i++;
    }

    if (b)
        subjPtr->results[2]->ChangeValue(wxT("No values"));

    else {
        while (i < subjPtr->getNumOfCells()) {

            if (!subjPtr->getValues()[i].isEmpty)
                if (subjPtr->getValues()[i].value > max)
                    max = subjPtr->getValues()[i].value;
            i++;
        }

        wxString str = wxString::Format(wxT("%lf"), max);
        subjPtr->results[2]->ChangeValue(str);

    }
}

