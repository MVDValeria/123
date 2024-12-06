#include <iostream>
#include "Storage.h"
#include "Train.h"
#include "TextScan.h"
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Store store; // ������, ��� ����� ��������� ������

    // ���� ����
    while (1)
    {
        string choice; // ���������� ������ ������������

        cout << "\n~~~Menu~~~" << endl;
        cout << "1 - Poisk po nomery poezda\n"
            << "2 - Izvlech pola obecta\n"
            << "3 - Pokychit opredelennye pola\n"
            << "4 - Vstavit znachenie\n"
            << "5 - Izmenit znachenie\n"
            << "6 - Ydalit znachenie\n"
            << "7 - Vivesi chitatu iz teksta" << endl;
        cout << "Vibor: ";
        cin >> choice; // ���� ������
        cout << "\n" << endl;

        // ��������� ����� (�������������� ��������)
        try
        {
            // ��������� ��� �������
            for (int id = 0; id < choice.size(); id++)
            {
                // ���� �����, ������ ������
                if (isalpha(choice[id])) throw "Error";
            }

            // ���� ����� �� ����� � ���������, ������ ������
            if (choice > "7" || choice < "1") throw "Error";
        }
        catch (const char* mssg) // ��������� ������
        {
            cout << "Error vvoda" << endl;
            exit(0);
        }

        // �������� ������ ������������
        if (choice == "1") store.FindTrain();
        else if (choice == "2") store.ExtractField();
        else if (choice == "3") store.GetFiel();
        else if (choice == "4") store.Set();
        else if (choice == "5") store.Change();
        else if (choice == "6") store.Delete();
        else if (choice == "7") TextScaner();
        else { cout << "Error vvoda" << endl; exit(0); }
    }
}

