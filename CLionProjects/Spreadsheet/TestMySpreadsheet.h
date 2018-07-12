//
// Created by davide on 12/07/18.
//

#ifndef SPREADSHEET_TESTMYSPREADSHEET_H
#define SPREADSHEET_TESTMYSPREADSHEET_H

#include <gtest/gtest.h>
#include "main.cpp"
#include "MySpreadsheet.cpp"

TEST(TestMySpreadsheet,testingCTor){
    auto ptr = new MySpreadsheet("window");
    ASSERT_EQ(wxT("window"),ptr->GetLabel());
}

#endif //SPREADSHEET_TESTMYSPREADSHEET_H
