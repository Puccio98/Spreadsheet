#include <wx/wx.h>



class MyFrame: public wxFrame{
public:
    MyFrame(const wxString& t): wxFrame(NULL, wxID_ANY, t, wxDefaultPosition, wxSize(1080, 720)) {
        SetIcon(wxIcon());
        Center();
    }
};


class MyApp: public wxApp{
    bool OnInit() override{
        MyFrame *simple = new MyFrame(wxT("Test 1"));
        simple->Show(true);

        return true;
    }
};

IMPLEMENT_APP(MyApp)


