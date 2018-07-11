#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    MySpreadsheet *simple = new MySpreadsheet(wxT("Spreadsheet"),60);
    auto calc = new ResultCalculation(simple);
    simple->Show(true);

    return true;

}
