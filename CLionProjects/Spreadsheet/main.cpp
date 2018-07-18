#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    ptr = new MySpreadsheet(wxT("Spreadsheet"));
    sum = new Sum(ptr);
    media = new Media(ptr);
    max = new Max(ptr);
    min = new Min(ptr);
    mediana = new Mediana(ptr);
    ptr->Show(true);

    return true;
}
