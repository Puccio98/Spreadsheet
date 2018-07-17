#include "main.h"
#include "Sum.h"
#include <memory>


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    MySpreadsheet* ptr = new MySpreadsheet(wxT("Spreadsheet"));
    auto sum = new Sum(ptr);
    ptr->Show(true);

    return true;
}
