//
// Created by davide on 12/07/18.

#include <wx/wx.h>
#include "gtest/gtest.h"
#include "../MySpreadsheet.h"
#include "../main.h"


TEST(MySpreadsheetSuite, testingConstructor) {

    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    ASSERT_EQ(ptr->GetSize(), wxSize(720, 480));
    ASSERT_EQ(ptr->getNumOfCells(), 60);
    ASSERT_EQ(ptr->getCells()[0]->GetValue(), wxEmptyString);
    ASSERT_TRUE(ptr->getValues()[0].isEmpty);

}

TEST(MySpreadsheetSuite, testingEvent) {

    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    ptr->getCells()[0]->SetValue(wxT("4.3"));
    ptr->getCells()[1]->SetValue(wxT("0"));

    double d = 0;
    wxString s = ptr->getCells()[0]->GetValue();
    s.ToDouble(&d);
    ASSERT_DOUBLE_EQ(4.3, d);

    s = ptr->getCells()[1]->GetValue();
    s.ToDouble(&d);
    ASSERT_DOUBLE_EQ(0,d);

    ptr->getCells()[0]->SetValue(wxT("-1e3"));
    s = ptr->getCells()[0]->GetValue();
    s.ToDouble(&d);
    ASSERT_DOUBLE_EQ(-1000,d);
}

TEST(MySpreadsheetSuite, testingCellsValues){

    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    ptr->getCells()[0]->SetValue(wxT("14"));
    ptr->getCells()[1]->SetValue(wxT("-7"));

    ASSERT_DOUBLE_EQ(14,ptr->getValues()[0].value);
    ASSERT_FALSE(ptr->getValues()[0].isEmpty);

    ASSERT_DOUBLE_EQ(-7,ptr->getValues()[1].value);
    ASSERT_FALSE(ptr->getValues()[1].isEmpty);

    ptr->getCells()[0]->SetValue(wxEmptyString);
    ASSERT_TRUE(ptr->getValues()[0].isEmpty);
    ASSERT_TRUE(ptr->getValues()[2].isEmpty);
}


TEST(MySpreadsheetSuite, testingObserversList) {

    auto ptr = dynamic_cast<MySpreadsheet *> (wxTheApp->GetTopWindow());
    unsigned long int l = ptr->getObserversList().size();
    ASSERT_EQ(0, l);

    auto sum = new Sum(ptr);
    auto max = new Max(ptr);
    auto min = new Min(ptr);
    auto media = new Media(ptr);
    auto mediana = new Mediana(ptr);
    l = ptr->getObserversList().size();
    ASSERT_EQ(5, l);

    delete sum;
    delete max;
    l = ptr->getObserversList().size();
    ASSERT_EQ(3, l);

    delete min;
    delete media;
    delete mediana;
    l = ptr->getObserversList().size();
    ASSERT_EQ(0, l);

}