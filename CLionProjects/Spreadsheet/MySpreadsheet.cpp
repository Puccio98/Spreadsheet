//
// Created by davide on 07/07/18.
//
#include "MySpreadsheet.h"
#include "ResultCalculation.h"


MySpreadsheet::MySpreadsheet(const wxString &windowName, int maxNumCells) :
        wxFrame(nullptr, wxID_ANY, windowName, wxDefaultPosition, wxSize(720, 480)),
        numOfCells(maxNumCells) {

    Centre();
    SetMinSize(wxSize(480, 400));
    SetMaxSize(wxSize(860, 600));

    initializeWindow();

    Connect(wxEVT_TEXT, wxTextEventHandler(MySpreadsheet::notify));

}

void MySpreadsheet::initializeWindow() {

    boxSizer = new wxBoxSizer(wxVERTICAL);
    panel = new wxPanel(this);
    gridSizer1 = new wxGridSizer(10, 6, 0, 0);

    cells.reserve(static_cast <unsigned long int> (numOfCells));

    for (int i = 0; i < numOfCells; i++) {
        cells.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(140, 30), 0,
                                       wxTextValidator(wxFILTER_NUMERIC)));
        gridSizer1->Add(cells[i], 1, wxALIGN_LEFT);
    }

    gridSizer2 = new wxGridSizer(2, 5, 10, 10);

    media = new wxStaticText(panel, wxID_ANY, wxT("Media:"));
    sum = new wxStaticText(panel, wxID_ANY, wxT("Somma:"));
    max = new wxStaticText(panel, wxID_ANY, wxT("Max:"));
    min = new wxStaticText(panel, wxID_ANY, wxT("Min:"));
    mediana = new wxStaticText(panel, wxID_ANY, wxT("Mediana:"));

    results.reserve(5);

    for (int i = 0; i < 5; i++)
        results.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(120, 30)));

    gridSizer2->Add(sum, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(media, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(max, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(min, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(mediana, 1, wxALIGN_BOTTOM);


    gridSizer2->Add(results[0], wxALIGN_BOTTOM);
    gridSizer2->Add(results[1], wxALIGN_BOTTOM);
    gridSizer2->Add(results[2], wxALIGN_BOTTOM);
    gridSizer2->Add(results[3], wxALIGN_BOTTOM);
    gridSizer2->Add(results[4], wxALIGN_BOTTOM);

    boxSizer->Add(gridSizer1, 1, wxEXPAND);
    boxSizer->Add(gridSizer2, 1, wxEXPAND);

    panel->SetSizer(boxSizer);
}

void MySpreadsheet::addObserver(Observer *ob) {
    observersList.push_back(ob);
}

void MySpreadsheet::removeObserver(Observer *ob) {
    observersList.remove(ob);
}

void MySpreadsheet::notify(wxCommandEvent &) {
    for (const auto &it : observersList)
        it->update();
}

