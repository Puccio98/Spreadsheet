#include "main.h"
#include "MySpreadsheet.h"

IMPLEMENT_APP(MyApp)


bool MyApp::OnInit() {

    MySpreadsheet *simple = new MySpreadsheet(wxT("Spreadsheet"),60);
    simple->Show(true);

    return true;

}
