#include "main.h"
#include <memory>


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    MySpreadsheet* ptr = new MySpreadsheet(wxT("Spreadsheet"));
    auto calc = new ResultCalculation(ptr);
    ptr->Show(true);

    return true;
}
