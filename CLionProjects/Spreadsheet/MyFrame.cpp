//
// Created by davide on 07/07/18.
//

#include "MyFrame.h"

MyFrame::MyFrame(const wxString &t): wxFrame(nullptr, wxID_ANY, t, wxDefaultPosition, wxSize(1080, 720)) {

    wxPanel * panel = new wxPanel(this,wxID_ANY);
    auto boxSizer = new wxBoxSizer(wxHORIZONTAL);

    auto gridSizer = new wxGridSizer(4,4,3,3);


    gridSizer->Add(new wxTextCtrl(panel, -1), 1,wxALIGN_CENTER);
    gridSizer->Add(new wxTextCtrl(panel, -1), 2,wxALIGN_CENTER);
    gridSizer->Add(new wxTextCtrl(panel,wxID_ANY,wxT("Ciao")),1,wxALIGN_CENTER);


    boxSizer->Add(gridSizer, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

    Centre();

}
