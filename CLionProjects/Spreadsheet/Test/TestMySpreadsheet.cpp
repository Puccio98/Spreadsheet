//
// Created by davide on 12/07/18.

#include "gtest/gtest.h"
#include "../MySpreadsheet.h"

TEST(TestMySpreadsheet,test){
    auto ptr = new MySpreadsheet("window");
    ASSERT_EQ(wxSize(720,480),ptr->GetSize());
}

