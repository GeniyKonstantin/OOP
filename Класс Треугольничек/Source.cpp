#include "Triangle.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string standart("Text.txt"),file_oshibka("Oshibka.txt"),file_polzovatlskiy;
	Triangle a;
	bool vibor1;
	int  vibor;
	cout << "0=ввести данные из файла по умолчанию\n 1=ввести данные из пользовательского файла\n ";
	cin >> vibor1;
	if (vibor1 == false)
		a.readfile(standart);
	else
	{
		cout << "введите на латиннице имя файла (вместе с форматом, то есть .txt)\n";
		getline(cin, file_polzovatlskiy);
		getline(cin, file_polzovatlskiy);
		try { a.readfile(file_polzovatlskiy); }
		catch (int error) {
			if (error == 0) {
				cout << "Не удается построить треугольник, или он выходит за поле консоли\n Будут введены данные из файла по умолчанию\n";
				a.readfile(standart);
			}
			if (error == 1) {
				cout << "Не удается построить вложенный треугольник\n Будут введены данные из файла по умолчанию\n ";
				a.readfile(standart);
			}
			if (error == 2) {
				cout << "Вложенный треугольник не лежит внутри внешнего\n Будут введены данные из файла по умолчанию\n  ";
				a.readfile(standart);
			}
			if (error == 3)
			{
				cout << "Файл испорчен или вы указали неправильное имя\n Будут введены данные из файла по умолчанию\n";
				a.readfile(standart);
			}
		}
	}
	do {
		cout << "выберете из 4:\n 1 = не закрашенный треугольник, 2 = закрашенный треугольник, 3 = вложенные фигуры, 4 - завершение программы." << endl;
		cin >> vibor;
		system("cls");
		switch (vibor)
		{
		case 1:
			try { a.drawUnpainted(); }
			catch (int error) {
				if (error == 0) {
					cout << "Не удается построить треугольник, или он выходит за поле консоли\n Будут введены данные из файла по умолчанию\n вы можете посмотреть введенные данные в созданном файле Oshibka.txt\n ";
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
					cout << "Не удается построить треугольник, или он выходит за поле консоли\n Будут введены данные из файла по умолчанию\n вы можете посмотреть введенные данные в созданном файле Oshibka.txt\n ";
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
					cout << "Не удается построить треугольник, или он выходит за поле консоли\n Будут введены данные из файла по умолчанию\n вы можете посмотреть введенные данные в созданном файле Oshibka.txt\n ";
					a.newfile(file_oshibka);
					a.readfile(standart);
					a.drawNestedTriangles();
				}
				if (error == 1) {
					cout << "Не удается построить вложенный треугольник\n Будут введены данные из файла по умолчанию\n Вы можете посмотреть введенные данные в созданном файле Oshibka.txt\n ";
					a.newfile(file_oshibka);
					a.readfile(standart);
					a.drawNestedTriangles();
				}
				if (error == 2) {
					cout << "Вложенный треугольник не лежит внутри внешнего\n Будут введены данные из файла по умолчанию\n Вы можете посмотреть введенные данные в созданном файле Oshibka.txt\n ";
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
