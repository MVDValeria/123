#include <iostream>
#include <string>
#include "Train.h"

using namespace std;

// ����������� �� ���������
Train::Train()
{
    this->destination = "None";
    this->train_number = "None";
    this->departure_time = "None";

    cout << "Vizvan constructor po ymolchaniy classa Train" << endl;
}

// ����������� � ����������
Train::Train(string destination, string train_number, string departure_time)
{
    this->destination = destination;
    this->train_number = train_number;
    this->departure_time = departure_time;

    cout << "Vizvan constructor s parametrom classa  Train" << endl;
}

// ����������� �����������
Train::Train(const Train& t)
{
    this->destination = t.destination;
    this->train_number = t.train_number;
    this->departure_time = t.departure_time;

    cout << "Vizvan constructor copirovanya classa Train" << endl;
}

// ����������
Train::~Train()
{
    cout << "Vizvan constructor classa Train" << endl;
}

// ����� ���������� �����
void Train::Extract()
{
    cout << *this;
}

// ����� ��������� �����
void Train::Get()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice; // ���������� ������ ����
    cout << "\nChto hotite polychit?\n" <<
        "1 - Punkt naznachenya\n" <<
        "2 - Nomer poezda\n" <<
        "3 - Vremya otpravlenay\n" <<
        "4 - Vse polya" << endl;
    cout << "Vibor: ";
    cin >> choice; // ����

    // ��������� �������������� ��������
    try
    {
        for (int id = 0; id < choice.size(); id++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch (const char* mssg)
    {
        cout << "Nevernyi vvod" << endl;
    }

    if (choice == "1") cout << "Punkt naznachenya: " << this->destination << endl;
    else if (choice == "2") cout << "Nomer poezda: " << this->train_number << endl;
    else if (choice == "3") cout << "Vremya otpravlenya: " << this->departure_time << endl;
    else if (choice == "4") cout << "Punkt naznachenya: " << this->destination << " | Nomer poezda: " << this->train_number << " | Vremya otpravlenya: " << this->departure_time << endl;
    else
    {
        cout << "Error vibora" << endl;
        exit(0);
    }
}

// ����� ��������� ���������� � ������
void Train::GetInformatio()
{
    cout << "Punkt naznachenya: " << this->destination << " | Nomer poezda: " << this->train_number << " | Vremya otpravlenya: " << this->departure_time << endl;
}

// ����� ��������� ���� ������� (��� ����������)
string Train::GetTime()
{
    return this->departure_time;
}

// ����� ��������� ������ ����������
string Train::GetDestination()
{
    return this->destination;
}

// ����� ��������� ������ ������
string Train::GetTrainNumber()
{
    return this->train_number;
}

// ����� ��������� ��������
void Train::Set()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Train::Change()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nChto hotite izmenit?\n" <<
        "1 - Pynkt naznachenya\n" <<
        "2 - Nomer poezda\n" <<
        "3 - Vremya otpravlenya" << endl;
    cout << "Vubor: ";
    cin >> choice;

    // ��������� �������������� ��������
    try
    {
        for (int id = 0; id < choice.size(); id++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch (const char* mssg)
    {
        cout << "Nevernyi vvod" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Pynkt naznachenya: ";
        getline(cin, this->destination);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Nomer poezda: ";
        getline(cin, this->train_number);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "Vremya otpravlenya: ";
        getline(cin, this->departure_time);
    }

    else
    {
        cout << "Error vibora" << endl;
        exit(0);
    }
}

// ���������� ��������� ������
std::ostream& operator<< (std::ostream& stream, Train& t) // ���������� ��������� �����������
{
    stream << "\nVse polya classa:" << endl;
    stream << t.destination << endl;
    stream << t.train_number << endl;
    stream << t.departure_time << endl;

    return stream;
}

// ���������� ��������� �����
std::istream& operator>> (std::istream& stream, Train& t) // ���������� ��������� �������
{
    string buf;

    cout << "\nVstavka znachenya:" << endl;
    cout << "Punkt naznachenya: ";
    getline(stream, buf);
    t.destination = buf;

    cout << "Nomer poezda: ";
    getline(stream, buf);
    t.train_number = buf;

    cout << "Vremya otpravlenya: ";
    getline(stream, buf);
    t.departure_time = buf;

    return stream;
}
