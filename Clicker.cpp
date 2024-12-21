#include "windows.h"
#include <iostream>
#include <string>

using namespace std;
static HWND hwnd;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float interval;
    int code;
    int value = 0x6F;
    int countIteration;
    char* name;


    cout << "Input interval(sec): ";
    cin >> interval;
    interval *= 1000;

    cout << "Input key(F1 - 1; F2 - 2, F3 - 3, etc): ";
    cin >> code;
    value += code;

    cout << "Input number of iterations: ";
    cin >> countIteration;
    cin.sync();

    cout << "Window name: ";
    fgets(name, 256, stdin);
    name[strlen(name)-1] = '\0';


    hwnd = FindWindow(0,  name);
    if (hwnd) {
            cout << "The window was found. Start!\n";
        }
         else {
            cout << "Error!!! The window was not found\n";
            return 0;
        }

    while (countIteration > 0) {
        cout << "Clicking...\n";
        PostMessage(hwnd, WM_KEYDOWN, value, 0);
        Sleep(1);
        PostMessage(hwnd, WM_KEYUP, value, 0);
        Sleep(interval);

        countIteration--;
        }
    cout << "End of program execution.\n";
    return 0;
}
