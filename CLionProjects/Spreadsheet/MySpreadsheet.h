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
    explicit MySpreadsheet(const wxString& t,int maxNumCells);

    void handleUpdate(wxCommandEvent & WXUNUSED(event));

    void initializeWindow(int maxNumCells);

    void addObserver(Observer* ob) override;

    void removeObserver(Observer* ob) override;

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

    std::list <Observer*> observersList;

};



#endif //SPREADSHEET_MYFRAME_H
