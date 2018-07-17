//
// Created by davide on 12/07/18.
//
#include "gtest/gtest.h"
#include "../MySpreadsheet.h"


TEST(ResultCalculationSuite, testingConstructor) {
    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    auto calc = new ResultCalculation(ptr);

    ASSERT_EQ(0,(calc->getCellsValues())[0]);
    ASSERT_EQ(0,(calc->getCellsValues())[20]);
    ASSERT_EQ(0,(calc->getCellsValues())[40]);
}

TEST(ResultCalculationSuite, testingEvent) {
    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    auto calc = new ResultCalculation(ptr);

    ptr->cells[0]->SetValue(wxT("5"));

    ASSERT_EQ(5, (calc->getCellsValues())[0]);
    ASSERT_FALSE(calc->checkString(1));
}

TEST(ResultCalculationSuite, testingCheckStringMethod) {
    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    auto calc = new ResultCalculation(ptr);

    ptr->cells[0]->SetValue(wxT("1.4"));
    ASSERT_TRUE(calc->checkString(0));

    ptr->cells[0]->SetValue(wxEmptyString);
    ASSERT_FALSE(calc->checkString(0));
}


