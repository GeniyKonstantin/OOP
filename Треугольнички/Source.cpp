#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
HWND ind = GetConsoleWindow();// индентификатор окна
HDC context = GetDC(ind);    //контекст отображения
RECT rt;                    //структура с полями left, top, right, bottom
//#include "proverkaPole.h"
#include  "ProverkaTriangle.h"
#include "ProverkaVlojenosti.h"
#include "proverkaPole.h"
FILE *f1, *f2, *f3, *f4, *f5;

//чтение координат треугольника из файла
void input(FILE *f, float x[3], float y[3]) {
	char sym;
	if (f != NULL) {
		for (int i = 0; i < 3; i++) {
			fscanf_s(f, "%c", &sym);
			fscanf_s(f, "%f", &x[i]);
			fscanf_s(f, "%c", &sym);
			fscanf_s(f, "%f", &y[i]);
			fscanf_s(f, "%c", &sym);
			fscanf_s(f, "%c", &sym);

		}
	}
	else {
		cout << "Ошибка, не удается открыть файл" << endl;
	}
}
//чтение цветов и ширины пера из файла
void rgb_color(FILE *f, int Rgb[3], int Rgb1[3], int width[1]) {
	char sym;
	if (f != NULL) {
		for (int i = 0; i < 3; i++) {
			fscanf_s(f, "%d", &Rgb[i]);
			fscanf_s(f, "%c", &sym);
			//cout << Rgb[i]<<' ';
		}
		for (int i = 0; i < 3; i++) {
			fscanf_s(f, "%d", &Rgb1[i]);
			fscanf_s(f, "%c", &sym);
			//cout << Rgb1[i] << ' ';
		}
		fscanf_s(f, "%d", &width[0]);
	}
	else {
		cout << "Ошибка, не удалось открыть файл" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string s1;
	SetBkColor(context, RGB(0, 0, 0));
	SetTextColor(context, RGB(0, 255, 0));
	cout << "Graphics in Console Window." << endl;
	GetClientRect(ind, &rt);
	float x1[3], y1[3], a, b, c, p, x2[3], y2[3], n;
	int rgb[3], rgb1[3];
	int vibor, i;
	int width[1];
	do {
		HPEN hPen, hOldPen;       //Получение индетификатора пера
		HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
		cout << "выберете из 4: 1 = не закрашенный треугольник, 2 = закрашенный треугольник, 3 = вложенные фигуры, 4 - завершение программы." << endl;
		cin >> vibor;
		system("cls");//чистит консоль
		switch (vibor)
		{
		case 1:
		{
			fopen_s(&f1, "Koord.txt", "r");
			fopen_s(&f4, "RGB.txt", "r");
			input(f1, x1, y1);
			rgb_color(f4, rgb, rgb1, width);
			hPen = CreatePen(PS_SOLID, width[0], RGB(rgb[0], rgb[1], rgb[2]));
			hOldPen = SelectPen(context, hPen);
			if (CheckPole(x1, y1) == false || CheckTriangle(x1, y1) == false)
			{
				cout << "Невозможно построить треугольник или он выходит    за границы окна, введите данные корректно\n";
			}
			else {
				system("cls");
				do {
					s1 = "Не закрашенный треугольник, чтобы вернуться к предыдущему выбору нажмите esc";
					LPCSTR lpcstr = s1.c_str();
					TextOutA(context, 10, 10, lpcstr, strlen(lpcstr));
					POINT treugolnik[4] = { { x1[0],y1[0] }, { x1[1],y1[1] }, { x1[2],y1[2] }, { x1[0],y1[0] } };
					Polyline(context, treugolnik, 4);
				} while (_getch() != 27);
			}
			
			fclose(f1);
			fclose(f4);
			SelectPen(context, hOldPen);
			DeletePen(hPen);
			break;
		}
		case 2:
		{
			fopen_s(&f1, "Koord.txt", "r");
			fopen_s(&f4, "RGB.txt", "r");
			input(f1, x1, y1);
			rgb_color(f4, rgb, rgb1, width);
			hPen = CreatePen(PS_SOLID, width[0], RGB(rgb[0], rgb[1], rgb[2]));
			hOldPen = SelectPen(context, hPen);
			hBrush = CreateSolidBrush(RGB(rgb1[0], rgb1[1], rgb1[2]));
			hOldBrush = SelectBrush(context, hBrush);
			if (CheckPole(x1, y1) == false || CheckTriangle(x1, y1) == false)
			{
				cout << "Невозможно построить треугольник или он выходит за границы окна, введите данные корректно\n";
			}
			else {
				system("cls");
				do {
					s1 = "Закрашенный треугольник, чтобы вернуться к предыдущему выбору нажмите esc";
					LPCSTR lpcstr = s1.c_str();
					TextOutA(context, 10, 10, lpcstr, strlen(lpcstr));
					POINT treugolnik[4] = { {x1[0],y1[0]},{x1[1],y1[1]},{x1[2],y1[2]},{x1[0],y1[0]} };
					Polygon(context, treugolnik, 4);

				} while (_getch() != 27);
			}
			
			fclose(f1);
			fclose(f4);
			SelectPen(context, hOldPen);
			SelectBrush(context, hOldBrush);
			DeletePen(hPen);
			DeleteBrush(hBrush);
			break;
		}
		case 3:
		{
			fopen_s(&f2, "Text.txt", "r");
			fopen_s(&f3, "Text1.txt", "r");
			fopen_s(&f5, "RGB1.txt", "r");
			input(f2, x1, y1);
			input(f3, x2, y2);
			rgb_color(f5, rgb, rgb1, width);
			hPen = CreatePen(PS_SOLID, width[0], RGB(rgb[0], rgb[1], rgb[2]));
			hOldPen = SelectPen(context, hPen);
			hBrush = CreateSolidBrush(RGB(rgb1[0], rgb1[1], rgb1[2]));
			hOldBrush = SelectBrush(context, hBrush);
			if (CheckPole(x1, y1) == false || CheckTriangle(x1, y1) == false || CheckPole(x2, y2) == false || CheckTriangle(x2, y2) == false)
			{
				cout << "Невозможно построить треугольник или он выходит за границы окна\n";
			}
			else {
				if (square(x1, y1, x2, y2, 0) == false) {
					cout << "Точка (x2[0], y2[0]) не лежит внутри треугольника" << endl;
				}
				else if (square(x1, y1, x2, y2, 1) == false && x2[0] != x2[1] && y2[0] != y2[1]) {
					cout << "Точка (x2[1], y2[1]) не лежит внутри треугольника" << endl;
				}
				else if (square(x1, y1, x2, y2, 2) == false) {
					cout << "Точка (x2[2], y2[2]) не лежит внутри треугольника или невозможно построить треугольник" << endl;
				}
				else {
					s1 = "вложенные треугольники:";
					system("cls");
					do
					{
						POINT pt;
						MoveToEx(context, x1[0], y1[0], &pt);
						LineTo(context, x1[1], y1[1]);
						LineTo(context, x1[2], y1[2]);
						LineTo(context, x1[0], y1[0]);
						MoveToEx(context, x2[0], y2[0], &pt);
						LineTo(context, x2[1], y2[1]);
						LineTo(context, x2[2], y2[2]);
						LineTo(context, x2[0], y2[0]);
						FloodFill(context, x2[2] + 5, y2[2] + 5, RGB(rgb[0], rgb[1], rgb[2]));

					} while (_getch() != 27);
				}
			}
			fclose(f2);
			fclose(f3);
			fclose(f5);
			SelectPen(context, hOldPen);
			SelectBrush(context, hOldBrush);
			DeletePen(hPen);
			DeleteBrush(hBrush);
			break;
		}
		case 4:
		{
			ReleaseDC(ind,context);
			exit(0);// завершение программы 
		}
	}
} while (vibor != 1 || vibor != 2 || vibor != 3);
system("pause");
}
