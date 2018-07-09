//
// Created by davide on 07/07/18.
//

#include <memory.h>
#include "MySpreadsheet.h"



MySpreadsheet::MySpreadsheet(const wxString &t,int maxNumCells): wxFrame(nullptr, wxID_ANY, t, wxDefaultPosition, wxSize(720, 480)) {

    Centre();
    SetMinSize(wxSize(480,400));
    SetMaxSize(wxSize(840,600));

    boxSizer = new wxBoxSizer(wxVERTICAL);

    panel = new wxPanel(this);

    gridSizer1 = new wxGridSizer(10,6,0,0);

    cells.reserve(static_cast <unsigned long int> (maxNumCells));

    for(int i = 0; i < maxNumCells; i++) {
        cells.push_back (new wxTextCtrl(panel, wxID_ANY, wxEmptyString,wxDefaultPosition,wxSize(140,30)));
        gridSizer1->Add(cells[i], 1 ,wxALIGN_LEFT);
    }

    gridSizer2 = new wxGridSizer(2,5,10,10);

    wxStaticText* media = new wxStaticText(panel,wxID_ANY,wxT("Media:"));
    wxStaticText* moda = new wxStaticText(panel,wxID_ANY,wxT("Moda:"));
    wxStaticText* max = new wxStaticText(panel,wxID_ANY,wxT("Max:"));;
    wxStaticText* min = new wxStaticText(panel,wxID_ANY,wxT("Min:"));;
    wxStaticText* sum = new wxStaticText(panel,wxID_ANY,wxT("Somma:"));

    gridSizer2->Add(media,1,wxALIGN_BOTTOM);
    gridSizer2->Add(moda,1,wxALIGN_BOTTOM);
    gridSizer2->Add(max,1,wxALIGN_BOTTOM);
    gridSizer2->Add(min,1,wxALIGN_BOTTOM);
    gridSizer2->Add(sum,1,wxALIGN_BOTTOM);

    boxSizer->Add(gridSizer1,1);
    boxSizer->Add(gridSizer2,1);

    panel->SetSizer(boxSizer);

}
