//
// Created by davide on 12/07/18.
//
#include "gtest/gtest.h"
#include "../MySpreadsheet.h"
#include "../ResultCalculation.h"

TEST(ResultCalculationSuite,testingConstructor) {
    auto ptr = dynamic_cast<MySpreadsheet*> (wxTheApp->GetTopWindow());
    auto calc = new ResultCalculation(ptr);

    ptr->cells[1]->SetValue(wxT("5"));
    ASSERT_TRUE(calc->checkString(1));
}

