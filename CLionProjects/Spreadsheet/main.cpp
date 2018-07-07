#include "main.h"
#include "MyFrame.h"

IMPLEMENT_APP(MyApp)


bool MyApp::OnInit() {

    MyFrame *simple = new MyFrame(wxT("Spreadsheet"));
    simple->Show(true);

    return true;

}
