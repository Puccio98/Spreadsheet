#include <wx/string.h>

int main() {

    wxString hello;
    hello.Printf("Ciao");

    wxPuts(hello);
    return 0;
}