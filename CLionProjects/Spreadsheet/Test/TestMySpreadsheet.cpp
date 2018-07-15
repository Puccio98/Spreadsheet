//
// Created by davide on 12/07/18.

#include "gtest/gtest.h"
#include "wx/wx.h"
#include "../MySpreadsheet.h"
#include "../main.h"



TEST(MySpreadsheetSuite,MySpreadsheetConstructor){
    wxSharedPtr <MySpreadsheet> ptr (new MySpreadsheet(("Window"),10));
    ASSERT_EQ(ptr->cells[0]->GetValue(),wxEmptyString);

}

