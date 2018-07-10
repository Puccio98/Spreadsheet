//
// Created by davide on 10/07/18.
//

#include "ResultCalculation.h"

ResultCalculation::ResultCalculation(Subject* su): subject(su){
    subject->addObserver(this);
}

ResultCalculation::~ResultCalculation() {
    subject->removeObserver(this);
}

void ResultCalculation::update() {

}
