//
// Created by davide on 10/07/18.
//

#include <algorithm>
#include "ResultCalculation.h"


void ResultCalculation::update() {


    min();
    mediana();

}

void ResultCalculation::min() {

    double min = 0;
    bool b = true;

    for (int i = 0; i < subjPtr->getNumOfCells() && b; i++) {
        if (checkString(i)) {
            min = cellsValues[i];
            b = false;
        }
    }

    if (!b) {
        for (int i = 0; i < subjPtr->getNumOfCells(); i++) {
            if (checkString(i)) {
                if (cellsValues[i] < min)
                    min = cellsValues[i];
            }
        }
        wxString str = wxString::Format(wxT("%lf"), min);
        subjPtr->results[3]->ChangeValue(str);

    } else
        subjPtr->results[3]->ChangeValue(wxT("No values"));

}

void ResultCalculation::mediana() {

    double mediana = 0;
    std::vector<double> v;

    for (int i = 0; i < subjPtr->getNumOfCells(); i++)
        if (checkString(i))
            v.push_back(cellsValues[i]);

    std::sort(v.begin(), v.end());
    unsigned long size = v.size();

    if (size == 0)
        subjPtr->results[4]->ChangeValue(wxT("No values"));

    else if (size % 2 == 0) {
        mediana = (v[size / 2 - 1] + v[size / 2]) / 2;
        wxString str = wxString::Format(wxT("%lf"), mediana);
        subjPtr->results[4]->ChangeValue(str);

    } else {
        mediana = v[size / 2];
        wxString str = wxString::Format(wxT("%lf"), mediana);
        subjPtr->results[4]->ChangeValue(str);
    }

}

bool ResultCalculation::checkString(int i) {

    wxString str = subjPtr->cells[i]->GetValue();

    if (!str.IsEmpty() && str != wxT("-"))
        return true;
    else
        return false;
}


