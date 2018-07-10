//
// Created by davide on 07/07/18.
//
#include <wx/wx.h>
#include <vector>
#include "Subject.h"

#ifndef SPREADSHEET_MYFRAME_H
#define SPREADSHEET_MYFRAME_H

class MySpreadsheet: public wxFrame, public Subject{
public:
    explicit MySpreadsheet(const wxString& t,int maxNumCells);

    void handleUpdate(wxCommandEvent & WXUNUSED(event));

    void initializeWindow(int maxNumCells);

    void addObserver(const Observer* ob) override;

    void removeObserver(const Observer* ob) override;

    void notify() override;

    std::vector <wxTextCtrl*> cells;
    std::vector <wxTextCtrl*> results;

private:
    wxPanel* panel;
    wxBoxSizer* boxSizer;
    wxGridSizer* gridSizer1;
    wxGridSizer* gridSizer2;

    wxStaticText *media;
    wxStaticText *moda;
    wxStaticText *max;
    wxStaticText *min;
    wxStaticText *sum;

};



#endif //SPREADSHEET_MYFRAME_H
