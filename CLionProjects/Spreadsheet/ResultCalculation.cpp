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
    }

    media();
    sum();
}

void ResultCalculation::media() {

}

void ResultCalculation::sum() {
    double sum = 0;
    for(int i = 0; i < 60;i++)
        sum = sum + cellsValues[i];
    wxString str = wxString::Format(wxT("%lf"),sum);
    subjPtr->results[4]->ChangeValue(str);
}




