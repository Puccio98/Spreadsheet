//
// Created by davide on 10/07/18.
//

#include "ResultCalculation.h"

ResultCalculation::ResultCalculation(MySpreadsheet* su):subjPtr(su){
    subjPtr->addObserver(this);
}

ResultCalculation::~ResultCalculation() {
    subjPtr->removeObserver(this);
}

void ResultCalculation::update() {
    media();
}

void ResultCalculation::media() {
    (*subjPtr).results[0]->ChangeValue(wxT("1010"));
}

