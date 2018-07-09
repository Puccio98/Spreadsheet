//
// Created by davide on 07/07/18.
//
#include <wx/wx.h>
#include <vector>

#ifndef SPREADSHEET_MYFRAME_H
#define SPREADSHEET_MYFRAME_H

class MySpreadsheet: public wxFrame{
public:
    explicit MySpreadsheet(const wxString& t,int maxNumCells);

    void OnQuit(wxCommandEvent & WXUNUSED(event)){
        Close(true);
    }


private:
    wxPanel* panel;
    wxBoxSizer* boxSizer;
    wxGridSizer* gridSizer1;
    wxGridSizer* gridSizer2;
    std::vector <wxTextCtrl*> cells;

};



#endif //SPREADSHEET_MYFRAME_H
