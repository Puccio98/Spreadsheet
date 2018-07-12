//
// Created by davide on 07/07/18.
//


#ifndef SPREADSHEET_MYFRAME_H
#define SPREADSHEET_MYFRAME_H

#include <wx/wx.h>
#include <vector>
#include <list>
#include "Subject.h"

class MySpreadsheet: public wxFrame, public Subject {
public:
    explicit MySpreadsheet(const wxString& t,int maxNumCells = 60);

    void handleUpdate(wxCommandEvent & WXUNUSED(event));

    void initializeWindow();

    void addObserver(Observer* ob) override;

    void removeObserver(Observer* ob) override;

    void notify() override;

    std::vector <wxTextCtrl*> cells;
    std::vector <wxTextCtrl*> results;
    int numOfCells;

private:
    wxPanel* panel;
    wxBoxSizer* boxSizer;
    wxGridSizer* gridSizer1;
    wxGridSizer* gridSizer2;

    wxStaticText *media;
    wxStaticText *mediana;
    wxStaticText *max;
    wxStaticText *min;
    wxStaticText *sum;

    std::list <Observer*> observersList;

};



#endif //SPREADSHEET_MYFRAME_H
