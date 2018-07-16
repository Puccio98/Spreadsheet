//
// Created by davide on 12/07/18.
//
#include "gtest/gtest.h"
#include "../MySpreadsheet.h"
#include "../ResultCalculation.h"

TEST(ResultCalculationSuite,testingConstructor) {
    auto ptr = dynamic_cast<MySpreadsheet*> (wxTheApp->GetTopWindow());
    auto calc = new ResultCalculation(ptr);


}

TEST(ResultCalculationSuite, testingEvent){
    auto ptr = dynamic_cast<MySpreadsheet*> (wxTheApp->GetTopWindow());
    auto calc = new ResultCalculation(ptr);

    ptr->cells[0]->SetValue(wxT("5"));

    ASSERT_EQ(5,(calc->getCellsValues())[0]);
    ASSERT_FALSE(calc->checkString(1));
}

TEST(ResultCalculationSuite, testingCheckStringMethod){

}

