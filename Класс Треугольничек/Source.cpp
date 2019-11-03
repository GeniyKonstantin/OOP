#include "Triangle.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string standart("Text.txt"),file_oshibka("Oshibka.txt"),file_polzovatlskiy;
	Triangle a;
	bool vibor1;
	int  vibor;
	cout << "0=������ ������ �� ����� �� ���������\n 1=������ ������ �� ����������������� �����\n ";
	cin >> vibor1;
	if (vibor1 == false)
		a.readfile(standart);
	else
	{
		cout << "������� �� ��������� ��� ����� (������ � ��������, �� ���� .txt)\n";
		getline(cin, file_polzovatlskiy);
		getline(cin, file_polzovatlskiy);
		try { a.readfile(file_polzovatlskiy); }
		catch (int error) {
			if (error == 0) {
				cout << "�� ������� ��������� �����������, ��� �� ������� �� ���� �������\n ����� ������� ������ �� ����� �� ���������\n";
				a.readfile(standart);
			}
			if (error == 1) {
				cout << "�� ������� ��������� ��������� �����������\n ����� ������� ������ �� ����� �� ���������\n ";
				a.readfile(standart);
			}
			if (error == 2) {
				cout << "��������� ����������� �� ����� ������ ��������\n ����� ������� ������ �� ����� �� ���������\n  ";
				a.readfile(standart);
			}
			if (error == 3)
			{
				cout << "���� �������� ��� �� ������� ������������ ���\n ����� ������� ������ �� ����� �� ���������\n";
				a.readfile(standart);
			}
		}
	}
	do {
		cout << "�������� �� 4:\n 1 = �� ����������� �����������, 2 = ����������� �����������, 3 = ��������� ������, 4 - ���������� ���������." << endl;
		cin >> vibor;
		system("cls");
		switch (vibor)
		{
		case 1:
			try { a.drawUnpainted(); }
			catch (int error) {
				if (error == 0) {
					cout << "�� ������� ��������� �����������, ��� �� ������� �� ���� �������\n ����� ������� ������ �� ����� �� ���������\n �� ������ ���������� ��������� ������ � ��������� ����� Oshibka.txt\n ";
					a.newfile(file_oshibka);
					a.readfile(standart);
					a.drawUnpainted();
				}

			}
			break;
		case 2:
			try { a.drawPainted(); }
			catch (int error) {
				if (error == 0) {
					cout << "�� ������� ��������� �����������, ��� �� ������� �� ���� �������\n ����� ������� ������ �� ����� �� ���������\n �� ������ ���������� ��������� ������ � ��������� ����� Oshibka.txt\n ";
					a.newfile(file_oshibka);
					a.readfile(standart);
					a.drawPainted();
				}
			}
			break;
		case 3:
			try { a.drawNestedTriangles(); }
			catch (int error) {
				if (error == 0) {
					cout << "�� ������� ��������� �����������, ��� �� ������� �� ���� �������\n ����� ������� ������ �� ����� �� ���������\n �� ������ ���������� ��������� ������ � ��������� ����� Oshibka.txt\n ";
					a.newfile(file_oshibka);
					a.readfile(standart);
					a.drawNestedTriangles();
				}
				if (error == 1) {
					cout << "�� ������� ��������� ��������� �����������\n ����� ������� ������ �� ����� �� ���������\n �� ������ ���������� ��������� ������ � ��������� ����� Oshibka.txt\n ";
					a.newfile(file_oshibka);
					a.readfile(standart);
					a.drawNestedTriangles();
				}
				if (error == 2) {
					cout << "��������� ����������� �� ����� ������ ��������\n ����� ������� ������ �� ����� �� ���������\n �� ������ ���������� ��������� ������ � ��������� ����� Oshibka.txt\n ";
					a.newfile(file_oshibka);
					a.readfile(standart);
					a.drawNestedTriangles();
				}
			}
			break;
		case 4:
			exit(0);

		}
	} while (vibor!=4);
	}
