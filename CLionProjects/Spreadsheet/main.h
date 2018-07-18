//
// Created by davide on 07/07/18.
//

#include <wx/wx.h>
#include "MySpreadsheet.h"
#include "Sum.h"
#include "Media.h"
#include "Max.h"
#include "Min.h"
#include "Mediana.h"

class MyApp: public wxApp {
public:
    bool OnInit() override ;

private:
    MySpreadsheet* ptr;
    Sum* sum;
    Media* media;
    Mediana* mediana;
    Max* max;
    Min* min;
};


DECLARE_APP(MyApp)
