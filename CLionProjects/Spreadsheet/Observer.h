//
// Created by davide on 10/07/18.
//

#ifndef SPREADSHEET_OBSERVER_H
#define SPREADSHEET_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};


#endif //SPREADSHEET_OBSERVER_H
