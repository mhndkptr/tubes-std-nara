#include "tubes.h"

int main()
{
    string input;
    menu_welcome();
    cin >> input;

    if(input == "Ya" || input == "YA" || input == "ya") {
        clearScreen();
        listProjek LP;
        createListProjek(LP);

        menu(LP);
    }
    return 0;
}
