//
// Created by davide on 10/07/18.
//

#ifndef SPREADSHEET_SUBJECT_H
#define SPREADSHEET_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void addObserver(Observer* ob) = 0;
    virtual void removeObserver(Observer* ob) = 0;
    virtual void notify(wxCommandEvent & WXUNUSED(event)) = 0;
};


#endif //SPREADSHEET_SUBJECT_H
