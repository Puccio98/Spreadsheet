//
// Created by davide on 17/07/18.
//

#include <algorithm>
#include "Mediana.h"

Mediana::Mediana(MySpreadsheet *s): subjPtr(s) {
    subjPtr->addObserver(this);
}

Mediana::~Mediana() {
    subjPtr->removeObserver(this);
}

void Mediana::compute() {
    double mediana = 0;
    std::vector<double> v;

    for (int i = 0; i < subjPtr->getNumOfCells(); i++)
        if (!subjPtr->getValues()[i].isEmpty)
            v.push_back(subjPtr->getValues()[i].value);

    std::sort(v.begin(), v.end());
    unsigned long size = v.size();

    if (size == 0)
        subjPtr->getResults()[4]->ChangeValue(wxT("No values"));

    else if (size % 2 == 0) {
        mediana = (v[size / 2 - 1] + v[size / 2]) / 2;
        wxString str = wxString::Format(wxT("%lf"), mediana);
        subjPtr->getResults()[4]->ChangeValue(str);

    } else {
        mediana = v[size / 2];
        wxString str = wxString::Format(wxT("%lf"), mediana);
        subjPtr->getResults()[4]->ChangeValue(str);
    }
}
