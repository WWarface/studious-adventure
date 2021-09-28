#include <iostream>
#include <fstream>
#include<string>

using namespace std;

struct Student
{
	char name[255];
	char surname[255];
	int day;
	int month;
	int year;

};

struct Bakalavr
{
	char name[255];
	char surname[255];
	char kurs[255];
	char group[255];
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
		cout << "Type group:";
		cin >> Antony[i].group;
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
		cout << " " << Antony[i].name << " " << Antony[i].surname << ":  " << Antony[i].kurs << " , " << Antony[i].group << " , " << "Math: " << Antony[i].marks[0] << "  " << "English: " << Antony[i].marks[1] << "  " << "Programming: " << Antony[i].marks[2] << "  " << "BodyBuilding: " << Antony[i].marks[3] << endl << endl;
	}

}

void FillFields(struct Student* Antony, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Type Name:";
		cin >> Antony[i].name;
		cout << "Type Surname:";
		cin >> Antony[i].surname;
		cout << "Type day of birth:";
		cin >> Antony[i].day;
		cout << "Type month of birth:";
		cin >> Antony[i].month;
		cout << "Type year of birth:";
		cin >> Antony[i].year;
		cout << endl << endl;
	}
}

void GoToFile(struct Bakalavr* Antony, const int N)
{
	int max = 0;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < 4 - 1; i++)
		{
			for (int j = 0; j < 4 - i - 1; j++)
			{
				if ((Antony[k].marks[j]) < (Antony[k].marks[j + 1]))
				{
					swap(Antony[k].marks[j], Antony[k].marks[j + 1]);
				}
			}
		}
	}

	ofstream f;

	f.open("second.txt");

	int sum = 0;
	int sered;
	for (int i = 0; i < N; i++)
	{
		f << " name: " << Antony[i].name << " Surname: " << Antony[i].surname << " Kurs:  " << Antony[i].kurs << " Group:  " << Antony[i].group << endl;
		for (int j = 0; j < 4; j++)
		{
			f << "  " << Antony[i].marks[j];
			sum = sum + Antony[i].marks[j];
			sered = sum / 4;
			if (j == 3)
			{
				f << endl << " Середнє значення: " << sered << endl;
				sum = 0;
				sered = 0;
			}
		}
		f << endl;
	}

	f.close();

}

void ShowStruct(struct Student* Antony, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << " " << Antony[i].name << " " << Antony[i].surname << " " << Antony[i].day << "." << Antony[i].month << "." << Antony[i].year << endl << endl;
	}
}

void RW(struct Student* Antony, string path, const int N)
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
			out.write((char*)&Antony[i].name, sizeof(Antony[i].name));
			out.write((char*)&Antony[i].surname, sizeof(Antony[i].surname));
			out.write((char*)&Antony[i].day, sizeof(int));
			out.write((char*)&Antony[i].month, sizeof(int));
			out.write((char*)&Antony[i].year, sizeof(int));
		}
		out.close();
	}
}

void RD(struct Student* Maks, struct Student* Antony, string path, const int N)
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
			in.read((char*)&Maks[i].name, sizeof(Maks[i].name));
			in.read((char*)&Maks[i].surname, sizeof(Maks[i].surname));
			in.read((char*)&Maks[i].day, sizeof(int));
			in.read((char*)&Maks[i].month, sizeof(int));
			in.read((char*)&Maks[i].year, sizeof(int));

			if ((Maks[i].day >= 22 && Maks[i].day <= 30) && (Maks[i].month >= 6 && Maks[i].month <= 7))
			{
				cout << " " << Maks[i].name << " " << Maks[i].surname << " " << Maks[i].day << "." << Maks[i].month << "." << Maks[i].year << "CRAB YEAR" << endl;
			}
		}
		in.close();
	}
}
int main()
{
	const int N = 2;
	//Student antony[N];
	//Student Mark[N];
	//string path = "GOGO";
	//FillFields(antony,N);
	//ShowStruct(antony,N);
	//RW(antony, path,N);
	//RD(Mark,antony, path,N);
	//ShowStruct(Mark, N);

	//////////////////////////// 2 partt

	Bakalavr Kola[N];
	FillFields2(Kola, N);
	ShowStruct2(Kola, N);
	GoToFile(Kola, N);

}