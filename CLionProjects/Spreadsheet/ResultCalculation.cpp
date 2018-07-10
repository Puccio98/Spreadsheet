//
// Created by davide on 10/07/18.
//

#include "ResultCalculation.h"

ResultCalculation::ResultCalculation(MySpreadsheet* su):sub(su){
    sub->addObserver(this);
}

ResultCalculation::~ResultCalculation() {
    sub->removeObserver(this);
}

void ResultCalculation::update() {
    media();
}

void ResultCalculation::media() {
    (*sub).results[0]->ChangeValue(wxT("23"));
}
