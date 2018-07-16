//
// Created by davide on 12/07/18.

#include <wx/wx.h>
#include "gtest/gtest.h"
#include "../MySpreadsheet.h"
#include "../main.h"


TEST(MySpreadsheetSuite, testingConstructor) {

    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    ASSERT_EQ(ptr->GetSize(), wxSize(720, 480));
    ASSERT_EQ(ptr->numOfCells, 60);
    ASSERT_EQ(ptr->cells[0]->GetValue(), wxEmptyString);

}

TEST(MySpreadsheetSuite, testingEvent) {

    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    ptr->cells[0]->SetValue(wxT("4.3"));

    double d = 0;
    wxString s = ptr->cells[0]->GetValue();
    s.ToDouble(&d);
    ASSERT_DOUBLE_EQ(4.3, d);
    ASSERT_EQ(wxEmptyString, ptr->cells[1]->GetValue());

}

TEST(MySpreadsheetSuite, testingObserversList) {

    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    unsigned long int l = ptr->getObserversList().size();
    ASSERT_EQ(0, l);

    auto calc = new ResultCalculation(ptr);
    l = ptr->getObserversList().size();
    ASSERT_EQ(1, l);

    delete calc;
    l = ptr->getObserversList().size();
    ASSERT_EQ(0, l);
}