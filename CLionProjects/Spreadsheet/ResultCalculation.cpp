//
// Created by davide on 10/07/18.
//

#include "ResultCalculation.h"

ResultCalculation::ResultCalculation(MySpreadsheet* su):subjPtr(su){
    cellsValues = new double[subjPtr->numOfCells];
    subjPtr->addObserver(this);
}

ResultCalculation::~ResultCalculation() {
    subjPtr->removeObserver(this);
}

void ResultCalculation::update() {
    wxString s;
    for(int i = 0; i < subjPtr->numOfCells;i++){
        s = subjPtr->cells[i]->GetValue();
        s.ToDouble(&cellsValues[i]);

        if(subjPtr->cells[i]->GetValue() == wxEmptyString)
            cellsValues[i] = 0;
    }
    double somma = sum();
    media(somma);
    max();
    min();

}

double ResultCalculation::sum() {
    double sum = 0;
    for(int i = 0; i < 60;i++)
        if(subjPtr->cells[i]->GetValue() != wxT("-"))
            sum = sum + cellsValues[i];
    wxString str = wxString::Format(wxT("%lf"),sum);
    subjPtr->results[0]->ChangeValue(str);

    return sum;
}

void ResultCalculation::media(double sum) {
    int count = 0;
    for(int i = 0; i < subjPtr->numOfCells;i++){
        if(subjPtr->cells[i]->GetValue() != wxEmptyString && subjPtr->cells[i]->GetValue() != wxT("-"))
            count++;
    }

    if(count != 0) {
        double media = sum / count;
        wxString str = wxString::Format(wxT("%lf"), media);
        subjPtr->results[1]->ChangeValue(str);
    } else
        subjPtr->results[1]->ChangeValue(wxT("No values"));

}

void ResultCalculation::max() {
    double max;
    bool b = true;
    int i = 0;
    while(b){
        if(subjPtr->cells[i]->GetValue() != wxEmptyString){
            max = cellsValues[i];
            b = false;
        }
        i++;
    }

    for(i = 0;i < subjPtr->numOfCells; i++){
        if(subjPtr->cells[i]->GetValue() != wxEmptyString)
            if(cellsValues[i] > max)
                max = cellsValues[i];
    }

    wxString str = wxString::Format(wxT("%lf"),max);
    subjPtr->results[2]->ChangeValue(str);
}

void ResultCalculation::min() {
    double min = 0;
}

bool ResultCalculation::checkString(int i) {

}




