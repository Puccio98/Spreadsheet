#include "main.h"
#include "Sum.h"
#include "Media.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    MySpreadsheet* ptr = new MySpreadsheet(wxT("Spreadsheet"));
    auto sum = new Sum(ptr);
    auto media = new Media(ptr);
    ptr->Show(true);

    return true;
}
