//
// Created by davide on 07/07/18.
//


#ifndef SPREADSHEET_MYFRAME_H
#define SPREADSHEET_MYFRAME_H

#include <wx/wx.h>
#include <vector>
#include <list>
#include "Subject.h"

struct cellValue {
    double value;
    bool isEmpty;
};

class MySpreadsheet : public wxFrame, public Subject {
public:
    explicit MySpreadsheet(const wxString &windowName, int maxNumCells = 60);

    ~MySpreadsheet() override;

    void initializeWindow();

    void addObserver(Observer *ob) override;

    void removeObserver(Observer *ob) override;

    void notify(wxCommandEvent & WXUNUSED(event)) override;

    const std::list<Observer *> &getObserversList() const;

    int getNumOfCells() const;

    cellValue *getCellsValues() const;

    std::vector<wxTextCtrl *> results;

private:

    int numOfCells;
    cellValue* cellsValues;

    std::vector<wxTextCtrl *> cells;

    wxStaticText *media;
    wxStaticText *mediana;
    wxStaticText *max;
    wxStaticText *min;
    wxStaticText *sum;

    wxPanel *panel;
    wxBoxSizer *boxSizer;
    wxGridSizer *gridSizer1;
    wxGridSizer *gridSizer2;

    std::list<Observer *> observersList;

};


#endif //SPREADSHEET_MYFRAME_H
