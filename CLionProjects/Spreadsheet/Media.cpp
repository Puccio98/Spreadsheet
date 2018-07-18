//
// Created by davide on 17/07/18.
//

#include "Media.h"

Media::Media(MySpreadsheet* s): subjPtr(s) {
    subjPtr->addObserver(this);
}


Media::~Media() {
    subjPtr->removeObserver(this);
}


void Media::compute() {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < 60; i++)
        if (!subjPtr->getValues()[i].isEmpty) {
            sum = sum + subjPtr->getValues()[i].value;
            count++;
        }

    if (count != 0) {
        double media = sum / count;
        wxString str = wxString::Format(wxT("%lf"), media);
        subjPtr->getResults()[1]->ChangeValue(str);
    } else
        subjPtr->getResults()[1]->ChangeValue(wxT("No values"));

}
