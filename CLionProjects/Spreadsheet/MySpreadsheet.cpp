//
// Created by davide on 07/07/18.
//
#include "MySpreadsheet.h"
#include "ResultCalculation.h"


MySpreadsheet::MySpreadsheet(const wxString &t, int maxNumCells) : wxFrame(nullptr, wxID_ANY, t, wxDefaultPosition, wxSize(720, 480)) {
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
        cells.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(140, 30),0,wxTextValidator(wxFILTER_DIGITS)));
        gridSizer1->Add(cells[i], 1, wxALIGN_LEFT);
    }

    gridSizer2 = new wxGridSizer(2, 5, 10, 10);

    media = new wxStaticText(panel, wxID_ANY, wxT("Media:"));
    moda = new wxStaticText(panel, wxID_ANY, wxT("Moda:"));
    max = new wxStaticText(panel, wxID_ANY, wxT("Max:"));;
    min = new wxStaticText(panel, wxID_ANY, wxT("Min:"));;
    sum = new wxStaticText(panel, wxID_ANY, wxT("Somma:"));

    results.reserve(5);

    for (int i = 0; i < 5; i++)
        results.push_back(new wxTextCtrl(panel,wxID_EXECUTE,wxEmptyString,wxDefaultPosition,wxSize(120,30)));

    gridSizer2->Add(media, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(moda, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(max, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(min, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(sum, 1, wxALIGN_BOTTOM);

    gridSizer2->Add(results[0],wxALIGN_BOTTOM);
    gridSizer2->Add(results[1],wxALIGN_BOTTOM);
    gridSizer2->Add(results[2],wxALIGN_BOTTOM);
    gridSizer2->Add(results[3],wxALIGN_BOTTOM);
    gridSizer2->Add(results[4],wxALIGN_BOTTOM);

    boxSizer->Add(gridSizer1, 1, wxEXPAND);
    boxSizer->Add(gridSizer2, 1, wxEXPAND);

    panel->SetSizer(boxSizer);
}

void MySpreadsheet::handleUpdate(wxCommandEvent &) {
    notify();
}

void MySpreadsheet::addObserver(Observer *ob) {
    observersList.push_back(ob);
}

void MySpreadsheet::removeObserver(Observer *ob) {
    observersList.remove(ob);
}

void MySpreadsheet::notify() {
    auto s = static_cast<int>(observersList.size());
    wxString str = wxString::Format(wxT("%d"),s);
    results[1]->ChangeValue(str);

    for (const auto &it : observersList) {
        it->update();

    }
}


