//
// Created by davide on 12/07/18.
//
#include "gtest/gtest.h"
#include "../MySpreadsheet.h"
#include "../Sum.h"


TEST(CalculationSuite, testingSum) {
    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    auto sum = new Sum(ptr);

}

TEST(CalculationSuite, testingEvent) {
    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());

    ptr->getCells()[0]->SetValue(wxT("5"));


}

TEST(CalculationSuite, testingCheckStringMethod) {
    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());


    ptr->getCells()[0]->SetValue(wxT("1.4"));


    ptr->getCells()[0]->SetValue(wxEmptyString);

}


