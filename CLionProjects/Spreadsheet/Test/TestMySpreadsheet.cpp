//
// Created by davide on 12/07/18.

#include "gtest/gtest.h"
#include "wx/wx.h"
#include "../MySpreadsheet.h"
#include "../main.h"


class MySpreadsheetSuite : public testing::Test{
public:
    void SetUp() override {

    }
};

TEST_F(MySpreadsheetSuite,MySpreadsheetConstructor){

    std::unique_ptr<MySpreadsheet> ptr (new MySpreadsheet(wxT("window")));
    ASSERT_EQ(wxSize(720,480),ptr->GetSize());


}

