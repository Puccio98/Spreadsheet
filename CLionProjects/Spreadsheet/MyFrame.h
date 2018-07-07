//
// Created by davide on 07/07/18.
//
#include <wx/wx.h>
#ifndef SPREADSHEET_MYFRAME_H
#define SPREADSHEET_MYFRAME_H


class MyFrame: public wxFrame{
public:
    MyFrame(const wxString& t);

    void OnQuit(wxCommandEvent & WXUNUSED(event)){
        Close(true);
    }
};


#endif //SPREADSHEET_MYFRAME_H
