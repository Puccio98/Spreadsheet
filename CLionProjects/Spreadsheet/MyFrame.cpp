//
// Created by davide on 07/07/18.
//

#include "MyFrame.h"

MyFrame::MyFrame(const wxString &t): wxFrame(NULL, wxID_ANY, t, wxDefaultPosition, wxSize(1080, 720)) {

    wxPanel * panel = new wxPanel(this,wxID_ANY);
    wxButton* button = new wxButton(panel,wxID_EXIT,wxT("Chiudi"),wxPoint(50,50));

    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnQuit));
    Center();

}
