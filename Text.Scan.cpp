#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // ������� ����� �����
    file.open("Text.txt"); // �������� �����

    if (!file.is_open()) // ���� ���� �� ��������
    {
        cout << "Error otkritia faila!" << endl;
        exit(0);
    }

    else
    {
        string countWord; // ���������� ������ � ���� ���-�� ����
        cout << "Vvedite kol-vo slov v predloshenii: ";
        cin >> countWord;

        try
        {
            // �������� �� ��, ��� ����� ������� ���������
            for (int id = 0; id < countWord.size(); id++)
            {
                if (!isdigit(countWord[id])) throw "Errors";
            }
        }
        catch (const char* mssg)
        {
            cout << "Neverniy vvod!" << endl;
        }

        string line; // ������, � ������� ����� ����������� �������� �� �����

        while (!file.eof()) // ���� �� ����� �����
        {
            string bufLine;
            getline(file, bufLine); // ��������� ������
            line += bufLine + '\n';
        }

        int wordInSuggestion = 0; // ��� �������� ���� � �����������
        string Suggestion; // �������� �����������
        string word; // ������ �����

        for (int id = 0; id < line.size(); id++)
        {
            // ���� ����� �����������
            if (line[id] == '!' || line[id] == '?' || line[id] == '.' || line[id] == '\0')
            {
                if (!word.empty()) wordInSuggestion++;

                // ����� �����������
                if (wordInSuggestion == stoi(countWord))
                {
                    cout << Suggestion << endl;
                }

                wordInSuggestion = 0;
                Suggestion = "";
                word = "";
            }

            else
            {
                if ((line[id] == ' ' || line[id] == ',' || line[id] == ':' || line[id] == ';' || line[id] == '"' || line[id] == '\'' || line[id] == '\n') && !word.empty())
                {
                    // ����������� ���-�� ����
                    wordInSuggestion++;
                    word = "";
                }
                else
                {
                    // �������� ������
                    if (line[id] != ' ' && line[id] != ',' && line[id] != ':' && line[id] != ';' && line[id] != '"' && line[id] != '\'' && line[id] != '\n') word += line[id];
                }

                if (line[id] == '\n') Suggestion += ' ';
                else Suggestion += line[id]; // �������� �����������
            }
        }
    }

    file.close(); // ��������� ����
}
