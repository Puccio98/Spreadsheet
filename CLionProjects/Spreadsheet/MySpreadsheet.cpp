//
// Created by davide on 07/07/18.
//

#include <memory.h>
#include "MySpreadsheet.h"


MySpreadsheet::MySpreadsheet(const wxString &t, int maxNumCells) : wxFrame(nullptr, wxID_ANY, t, wxDefaultPosition,
                                                                           wxSize(720, 480)) {
    Centre();
    SetMinSize(wxSize(480, 400));
    SetMaxSize(wxSize(860, 600));

    initializeWindow(maxNumCells);

    Connect(wxID_EXECUTE, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MySpreadsheet::handleUpdate));

}

void MySpreadsheet::initializeWindow(int maxNumCells) {

    boxSizer = new wxBoxSizer(wxVERTICAL);
    panel = new wxPanel(this);
    gridSizer1 = new wxGridSizer(10, 6, 0, 0);

    cells.reserve(static_cast <unsigned long int> (maxNumCells));

    for (int i = 0; i < maxNumCells; i++) {
        cells.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(140, 30)));
        gridSizer1->Add(cells[i], 1, wxALIGN_LEFT);
    }

    gridSizer2 = new wxGridSizer(2, 5, 10, 10);

    media = new wxStaticText(panel, wxID_ANY, wxT("Media:"));
    moda = new wxStaticText(panel, wxID_ANY, wxT("Moda:"));
    max = new wxStaticText(panel, wxID_ANY, wxT("Max:"));;
    min = new wxStaticText(panel, wxID_ANY, wxT("Min:"));;
    sum = new wxStaticText(panel, wxID_ANY, wxT("Somma:"));

    gridSizer2->Add(media, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(moda, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(max, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(min, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(sum, 1, wxALIGN_BOTTOM);

    boxSizer->Add(gridSizer1, 1, wxEXPAND);
    boxSizer->Add(gridSizer2, 1, wxEXPAND);

    panel->SetSizer(boxSizer);
}

void MySpreadsheet::handleUpdate(wxCommandEvent &) {
    //cells[10]->SetHelpText(wxT());
}


