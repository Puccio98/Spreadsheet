#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    MySpreadsheet* ptr = new MySpreadsheet(wxT("Spreadsheet"));
    auto sum = new Sum(ptr);
    auto media = new Media(ptr);
    auto max = new Max(ptr);
    auto min = new Min(ptr);
    auto mediana = new Mediana(ptr);
    ptr->Show(true);

    return true;
}
