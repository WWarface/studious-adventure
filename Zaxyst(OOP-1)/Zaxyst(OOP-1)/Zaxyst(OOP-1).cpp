
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Bakalavr
{
    char name[255];
    char surname[255];
    char kurs[255];
    int marks[4];
};

void FillFields2(struct Bakalavr* Antony, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Type Name:";
        cin >> Antony[i].name;
        cout << "Type Surname:";
        cin >> Antony[i].surname;
        cout << "Type kurs:";
        cin >> Antony[i].kurs;
        cout << "Type math:";
        cin >> Antony[i].marks[0];
        cout << "Type english:";
        cin >> Antony[i].marks[1];
        cout << "Type programming:";
        cin >> Antony[i].marks[2];
        cout << "Type BodyBuilding:";
        cin >> Antony[i].marks[3];
        cout << endl << endl;
    }
}

void ShowStruct2(struct Bakalavr* Antony, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << " " << Antony[i].name << " " << Antony[i].surname << ":  " << Antony[i].kurs << " , " << "Math: " << Antony[i].marks[0] << "  " << "English: " << Antony[i].marks[1] << "  " << "Programming: " << Antony[i].marks[2] << "  " << "BodyBuilding: " << Antony[i].marks[3] << endl << endl;
    }

}

void RW(struct Bakalavr* Antony, string path, const int N)
{
    ofstream out;
    out.open(path + ".DAT", ios::binary);
    if (!out.is_open())
    {
        cout << "ERROR Writing FILE" << endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            out.write((char*)&Antony[i], sizeof(Antony[i]));
        }
        out.close();
    }
}

void RD(struct Bakalavr* Maks, struct Bakalavr* Antony, string path, const int N)
{
    ifstream in;
    in.open(path + ".DAT", ios::binary);
    if (!in.is_open())
    {
        cout << "ERROR READING FILE" << endl;
    }
    else
    {
        cout << "READING BLOCK STRUCT DATA........" << endl;
        for (int i = 0; i < N; i++)
        {
            in.read((char*)&Maks[i], sizeof(Antony[i]));
        }
        in.close();
    }
}

void CheckIn(struct Bakalavr* Maks, const int N)
{

    int Vidchislenna = 0;
    int PowerUp = 0;
    ofstream leaving;
    ofstream Uppering;
    leaving.open("leaving.txt");
    Uppering.open("Uppering.txt");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (Maks[i].marks[j] <= 2)
            {
                Vidchislenna++;
            }
            if (Vidchislenna == 2)
            {
                leaving << "Leaving student is: " << Maks[i].name << " " << Maks[i].surname << endl;
                Vidchislenna = 0;
                break;
            }
            if (Maks[i].marks[j] == 5)
            {
                PowerUp++;
            }
            if (PowerUp == 4)
            {
                Uppering << "Genious student is: " << Maks[i].name << " " << Maks[i].surname << endl;
                PowerUp = 0;
            }
        }
    }
    leaving.close();
    Uppering.close();

}


int main()
{
    const int N = 3;
    string path = "GOGO";
    Bakalavr Antony[N];
    Bakalavr Maks[N];


    FillFields2(Antony, N);
    ShowStruct2(Antony, N);
    RW(Antony, path, N);
    RD(Maks, Antony, path, N);
    ShowStruct2(Maks, N);

    CheckIn(Maks, N);
}

