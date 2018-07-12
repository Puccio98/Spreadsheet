#include <gtest/gtest.h>
#include "main.h"

IMPLEMENT_APP_NO_MAIN(MyApp)

int main(){
    int argc = 0;
    char* argv = nullptr;
    return wxEntry(argc, &argv);
}

/*int main(int argc,char* argv[]){
    testing::InitGoogleTest(&argc ,argv);
    return RUN_ALL_TESTS();
}*/

bool MyApp::OnInit() {

    MySpreadsheet *simple = new MySpreadsheet(wxT("Spreadsheet"));
    auto calc = new ResultCalculation(simple);
    simple->Show(true);

}
