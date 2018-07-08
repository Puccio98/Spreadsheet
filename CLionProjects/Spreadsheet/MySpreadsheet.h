//
// Created by davide on 07/07/18.
//
#include <wx/wx.h>

#ifndef SPREADSHEET_MYFRAME_H
#define SPREADSHEET_MYFRAME_H

class MySpreadsheet: public wxFrame{
public:
    explicit MySpreadsheet(const wxString& t);

    void OnQuit(wxCommandEvent & WXUNUSED(event)){
        Close(true);
    }


private:
    wxPanel* panel1;
    wxPanel* panel2;
    wxGridSizer* gridSizer;
    wxTextCtrl* storage[30];
};



#endif //SPREADSHEET_MYFRAME_H
