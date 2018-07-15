//
// Created by davide on 12/07/18.
//
#include "gtest/gtest.h"
#include "../MySpreadsheet.h"
#include "../ResultCalculation.h"

TEST(ResultCalculationSuite,testingConstructor){
    wxSharedPtr<MySpreadsheet> ptr (new MySpreadsheet(("Window"),20));
    auto calc = new ResultCalculation(ptr);
    ptr->cells[0]->SetValue(wxT("5"));
    ASSERT_TRUE(calc->checkString(0));
}

