#include<windows.h>
#include <iostream>
#include <cstdlib>
#include "Dohoa.h"
#include "mylib.h"
#include "Xu_li_nhap_so.h"
using namespace std;

int main() {
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //full window screen
    system("cls");
    string Menu[4] = { "The doc gia", "Thong tin cac danh sach", "Tra sach", "Thoat" };
    int pointer = 0;
    bool bMainMenu = true;

    while (bMainMenu)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "Main Menu\n\n";

        for (int i = 0; i < 4; ++i)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << Menu[i] << endl;
            }
        }

        while (bMainMenu)
        {
            if (GetAsyncKeyState(VK_UP)&1)
            {
                pointer = pointer - 1;
                if (pointer == -1)
                {
                    pointer = 2;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_DOWN)&1)
            {
                pointer += 1;
                if (pointer == 4)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN)&1)
            {
                switch (pointer)
                {
                case 0:
                {
                    //admin_login();
                    system("cls");
                    cout << "admin selected\n";
                    bMainMenu = false;
                    break;
                }
                case 1:
                {
                    //customer_sign();
                    system("cls");
                    cout << "customer selected\n";
                    bMainMenu = false;
                    break;
                }
                case 2:
                {
                    //thank_you();
                    system("cls");
                    cout << "thank you selected\n";
                    bMainMenu = false;
                    break;
                }
                case 3:
                {
                    //thank_you();
                    system("cls");
                    cout << "exit selected\n";
                    std::terminate();
                    bMainMenu = false;
                    break;
                }
                default:
                {
                    cout << "Invalid Input! ";
                    std::terminate();
                }
                }
            }
        }
    }
    return 0;
}
