//
// Created by davide on 07/07/18.
//

#include "MySpreadsheet.h"


MySpreadsheet::MySpreadsheet(const wxString &t): wxFrame(nullptr, wxID_ANY, t, wxDefaultPosition, wxSize(720, 480)) {

    panel1 = new wxPanel(this,wxID_ANY);

    gridSizer = new wxGridSizer(10,5,1,1);

    for(int i = 0; i < 30; i++) {
        storage[i] = new wxTextCtrl(panel1, wxID_ANY, wxEmptyString);
        gridSizer->Add(storage[i], 1 ,wxALIGN_CENTER);
    }

    panel1->SetSizer(gridSizer);

    Centre();

}
