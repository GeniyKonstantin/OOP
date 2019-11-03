#pragma once
#include <windows.h>
#include <windowsx.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Coordinate
{
	vector <float> x, y;
};
struct Color
{
	vector <float> rgb;
	int width;
};


class Figure
{
public:
	virtual void draw(int vibor) = 0;
	virtual void draw() = 0;
};

class PaintedCharacteristic
{
protected:
	Color rgb_brush_t1;
	Color rgb_brush_t2;
public:
	void set_rgb_brush_t1(int r, int g, int b)
	{
		rgb_brush_t1.rgb.resize(3);
		rgb_brush_t1.rgb[0] = r;
		rgb_brush_t1.rgb[1] = g;
		rgb_brush_t1.rgb[2] = b;
	}
	void set_rgb_brush_t2(int r, int g, int b)
	{
		rgb_brush_t2.rgb.resize(3);
		rgb_brush_t2.rgb[0] = r;
		rgb_brush_t2.rgb[1] = g;
		rgb_brush_t2.rgb[2] = b;
	}
	Color get_rgb_brush_t1() const
	{
		return rgb_brush_t1;
	}
	Color get_rgb_brush_t2() const
	{
		return rgb_brush_t2;
	}
};

class Outline :public Figure,public PaintedCharacteristic
{
protected:
	float storona(float x1, float x2, float y1, float y2)
	{
		int storona;
		storona = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		return storona;
	}
	Color rgb_pen_t1;
	Color rgb_pen_t2;
	Coordinate t1;
	Coordinate t2;
	bool ChechOutline(Coordinate t)
	{

		HWND ind = GetConsoleWindow();// индентификатор окна
		HDC context = GetDC(ind);    //контекст отображения
		RECT rt;                    //структура с полями left, top, right, bottom
		bool k = false;
		GetClientRect(ind, &rt);
		for (int i = 0; i < 3; i++)
		{
			if (t.x[i] < rt.right && t.y[i] < rt.bottom)
				k = true;
			else
				return false;
		}
		return k;
	}
	bool CheckTriangle(Coordinate t)
	{
		bool k;
		float a, b, c;
		a = storona(t.x[0], t.x[1], t.y[0], t.y[1]);
		b = storona(t.x[1], t.x[2], t.y[1], t.y[2]);
		c = storona(t.x[2], t.x[0], t.y[2], t.y[0]);
		if (a + b > c && a + c > b && c + b > a)
			k = true;
		else
			return false;
		return k;
	}
public:
	void set_rgb_pen_t1(Color c1)
	{
		rgb_pen_t1.rgb.resize(3);
		rgb_pen_t1 = c1;
	}
	void set_rgb_pen_t2(Color c2)
	{
		rgb_pen_t2.rgb.resize(3);
		rgb_pen_t2 = c2;
	}
	void set_width(int w) { rgb_pen_t1.width = w; }
	int get_width() const { return rgb_pen_t1.width; }
	void set_coord_t1(Coordinate t1)
	{
		t1.x.resize(3);
		t1.y.resize(3);
		this->t1 = t1;
	}
	void set_coord_t2(Coordinate t2)
	{
		t2.x.resize(3);
		t2.y.resize(3);
		this->t2 = t2;
	}
	void read_file(string s)
	{
		t1.x.resize(3);
		t1.y.resize(3);
		t2.x.resize(3);
		t2.y.resize(3);
		rgb_pen_t1.rgb.resize(3);
		rgb_brush_t1.rgb.resize(3);
		ifstream infile(s);
		if (infile.fail())throw 0;              // проверка файла
		for (int i = 0; i < 3; i++)
			infile >> t1.x[i] >> t1.y[i];
		infile >> rgb_pen_t1.width;
		for (int i = 0; i < 3; i++)
			infile >> rgb_pen_t1.rgb[i];
		for (int i = 0; i < 3; i++)
			infile >> rgb_brush_t1.rgb[i];
		for (int i = 0; i < 3; i++) {
			infile >> t2.x[i] >> t2.y[i];;
		}
		infile.close();
	}
	Color get_rgb_pen_t1() const { return rgb_pen_t1; }
	Color get_rgb_pen_t2() const { return rgb_pen_t2; }
	Coordinate get_coord_t1() const { return t1; }
	Coordinate get_coord_t2() const {return t2;}
	void draw(int vibor) override
	{
		if (vibor == 1)
		{
			if (CheckTriangle(t1) == false || ChechOutline(t1) == false) throw 0;
			HWND ind = GetConsoleWindow();// индентификатор окна
			HDC context = GetDC(ind);    //контекст отображения
			RECT rt;                    //структура с полями left, top, right, bottom
			HPEN hPen, hOldPen;       //Получение индетификатора пера
			SetBkColor(context, RGB(0, 0, 0));
			SetTextColor(context, RGB(0, 255, 0));
			hPen = CreatePen(PS_SOLID, rgb_pen_t1.width,RGB(rgb_pen_t1.rgb[0],rgb_pen_t1.rgb[1],rgb_pen_t1.rgb[2]));
			hOldPen = SelectPen(context, hPen);
			do {
				POINT treugolnik[4] = { {t1.x[0],t1.y[0]},{t1.x[1],t1.y[1]},{t1.x[2],t1.y[2]},{t1.x[0],t1.y[0]} };
				Polyline(context, treugolnik, 4);
			} while (_getch() != 27);
			SelectPen(context, hOldPen);
			DeletePen(hPen);
			ReleaseDC(ind, context);
		}
		else
		{
			if (CheckTriangle(t2) == false || ChechOutline(t2) == false) throw 0;
			HWND ind = GetConsoleWindow();// индентификатор окна
			HDC context = GetDC(ind);    //контекст отображения
			RECT rt;                    //структура с полями left, top, right, bottom
			HPEN hPen, hOldPen;       //Получение индетификатора пера
			SetBkColor(context, RGB(0, 0, 0));
			SetTextColor(context, RGB(0, 255, 0));
			hPen = CreatePen(PS_SOLID, rgb_pen_t2.width, RGB(rgb_pen_t2.rgb[0], rgb_pen_t2.rgb[1], rgb_pen_t2.rgb[2]));
			hOldPen = SelectPen(context, hPen);
			do {
				POINT treugolnik[4] = { {t2.x[0],t2.y[0]},{t2.x[1],t2.y[1]},{t2.x[2],t2.y[2]},{t2.x[0],t2.y[0]} };
				Polyline(context, treugolnik, 4);
			} while (_getch() != 27);
			SelectPen(context, hOldPen);
			DeletePen(hPen);
			ReleaseDC(ind, context);
		}
	}
	void draw() override
	{
		if (CheckTriangle(t1) == false || ChechOutline(t1) == false) throw 0;
		HWND ind = GetConsoleWindow();// индентификатор окна
		HDC context = GetDC(ind);    //контекст отображения
		RECT rt;                    //структура с полями left, top, right, bottom
		HPEN hPen, hOldPen;       //Получение индетификатора пера
		SetBkColor(context, RGB(0, 0, 0));
		SetTextColor(context, RGB(0, 255, 0));
		hPen = CreatePen(PS_SOLID, rgb_pen_t1.width, RGB(rgb_pen_t1.rgb[0], rgb_pen_t1.rgb[1], rgb_pen_t1.rgb[2]));
		hOldPen = SelectPen(context, hPen);
		do {
			POINT treugolnik[4] = { {t1.x[0],t1.y[0]},{t1.x[1],t1.y[1]},{t1.x[2],t1.y[2]},{t1.x[0],t1.y[0]} };
			Polyline(context, treugolnik, 4);
		} while (_getch() != 27);
		SelectPen(context, hOldPen);
		DeletePen(hPen);
		ReleaseDC(ind, context);
	}
};

class Painted : public Outline
{
public:
	void draw(int vibor) override
	{
		if (vibor==1)
		{
			if (CheckTriangle(t1) == false || CheckTriangle(t1) == false) throw 0;
			HWND ind = GetConsoleWindow();// индентификатор окна
			HDC context = GetDC(ind);    //контекст отображения
			RECT rt;                    //структура с полями left, top, right, bottom
			HPEN hPen, hOldPen;       //Получение индетификатора пера
			HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
			SetBkColor(context, RGB(0, 0, 0));
			SetTextColor(context, RGB(0, 255, 0));
			hPen = CreatePen(PS_SOLID, rgb_pen_t1.width, RGB(rgb_pen_t1.rgb[0], rgb_pen_t1.rgb[1], rgb_pen_t1.rgb[2]));
			hOldPen = SelectPen(context, hPen);
			hBrush = CreateSolidBrush(RGB(rgb_brush_t1.rgb[0], rgb_brush_t1.rgb[1], rgb_brush_t1.rgb[2]));
			hOldBrush = SelectBrush(context, hBrush);
			do {
				POINT treugolnik[4] = { {t1.x[0],t1.y[0]},{t1.x[1],t1.y[1]},{t1.x[2],t1.y[2]},{t1.x[0],t1.y[0]} };
				Polygon(context, treugolnik, 4);
			} while (_getch() != 27);
			SelectPen(context, hOldPen);
			SelectBrush(context, hOldBrush);
			DeletePen(hPen);
			DeleteBrush(hBrush);
			ReleaseDC(ind, context);
		}
		else
		{
			if (CheckTriangle(t2) == false || CheckTriangle(t2) == false) throw 0;
			HWND ind = GetConsoleWindow();// индентификатор окна
			HDC context = GetDC(ind);    //контекст отображения
			RECT rt;                    //структура с полями left, top, right, bottom
			HPEN hPen, hOldPen;       //Получение индетификатора пера
			HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
			SetBkColor(context, RGB(0, 0, 0));
			SetTextColor(context, RGB(0, 255, 0));
			hPen = CreatePen(PS_SOLID, rgb_pen_t2.width, RGB(rgb_pen_t2.rgb[0], rgb_pen_t2.rgb[1], rgb_pen_t2.rgb[2]));
			hOldPen = SelectPen(context, hPen);
			hBrush = CreateSolidBrush(RGB(rgb_brush_t2.rgb[0], rgb_brush_t2.rgb[1], rgb_brush_t2.rgb[2]));
			hOldBrush = SelectBrush(context, hBrush);
			do {
				POINT treugolnik[4] = { {t2.x[0],t2.y[0]},{t2.x[1],t2.y[1]},{t2.x[2],t2.y[2]},{t2.x[0],t2.y[0]} };
				Polygon(context, treugolnik, 4);
			} while (_getch() != 27);
			SelectPen(context, hOldPen);
			SelectBrush(context, hOldBrush);
			DeletePen(hPen);
			DeleteBrush(hBrush);
			ReleaseDC(ind, context);
		}
	}
	void draw() override
	{
		if (CheckTriangle(t1) == false || CheckTriangle(t1) == false) throw 0;
		HWND ind = GetConsoleWindow();// индентификатор окна
		HDC context = GetDC(ind);    //контекст отображения
		RECT rt;                    //структура с полями left, top, right, bottom
		HPEN hPen, hOldPen;       //Получение индетификатора пера
		HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
		SetBkColor(context, RGB(0, 0, 0));
		SetTextColor(context, RGB(0, 255, 0));
		hPen = CreatePen(PS_SOLID, rgb_pen_t1.width, RGB(rgb_pen_t1.rgb[0], rgb_pen_t1.rgb[1], rgb_pen_t1.rgb[2]));
		hOldPen = SelectPen(context, hPen);
		hBrush = CreateSolidBrush(RGB(rgb_brush_t1.rgb[0], rgb_brush_t1.rgb[1], rgb_brush_t1.rgb[2]));
		hOldBrush = SelectBrush(context, hBrush);
		do {
			POINT treugolnik[4] = { {t1.x[0],t1.y[0]},{t1.x[1],t1.y[1]},{t1.x[2],t1.y[2]},{t1.x[0],t1.y[0]} };
			Polygon(context, treugolnik, 4);
		} while (_getch() != 27);
		SelectPen(context, hOldPen);
		SelectBrush(context, hOldBrush);
		DeletePen(hPen);
		DeleteBrush(hBrush);
		ReleaseDC(ind, context);
	}
};

class  Nested : public Outline
{
private:
	bool square(Coordinate t, int n)
	{
		float p, a, b, c, O1, O2, O3, S[4];
		a = storona(t1.x[0], t1.x[1], t1.y[0], t1.y[1]);
		b = storona(t1.x[1], t1.x[2], t1.y[1], t1.y[2]);
		c = storona(t1.x[2], t1.x[0], t1.y[2], t1.y[0]);
		p = (a + b + c) / 2;
		S[0] = sqrt(p * (p - a) * (p - b) * (p - c));
		O1 = storona(t1.x[0], t.x[n], t1.y[0], t.y[n]);
		O2 = storona(t1.x[1], t.x[n], t1.y[1], t.y[n]);
		O3 = storona(t1.x[2], t.x[n], t1.y[2], t.y[n]);
		p = (O1 + O2 + a) / 2;
		S[1] = sqrt(p * (p - O1) * (p - O2) * (p - a));
		p = (O2 + O3 + b) / 2;
		S[2] = sqrt(p * (p - O2) * (p - O3) * (p - b));
		p = (O3 + O1 + c) / 2;
		S[3] = sqrt(p * (p - O3) * (p - O1) * (p - c));
		//cout << S[0] << endl << S[1] << endl << S[2] << endl << S[3] << endl;
		if (S[0] <= S[1] + S[2] + S[3] + 0.5 && S[0] >= S[1] + S[2] + S[3] - 0.5 && S[1] != 0 && S[2] != 0 && S[3] != 0)
			return true;
		else
			return false;
	}
public:
	void draw() override
	{
		if (CheckTriangle(t1) == false || CheckTriangle(t1) == false) throw 0;
		if (CheckTriangle(t2) == false) throw 1;
		HWND ind = GetConsoleWindow();// индентификатор окна
		HDC context = GetDC(ind);    //контекст отображения
		RECT rt;                    //структура с полями left, top, right, bottom
		HPEN hPen, hOldPen;       //Получение индетификатора пера
		HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
		SetBkColor(context, RGB(0, 0, 0));
		SetTextColor(context, RGB(0, 255, 0));
		hPen = CreatePen(PS_SOLID, rgb_pen_t1.width, RGB(rgb_pen_t1.rgb[0], rgb_pen_t1.rgb[1], rgb_pen_t1.rgb[2]));
		hOldPen = SelectPen(context, hPen);
		hBrush = CreateSolidBrush(RGB(rgb_brush_t1.rgb[0], rgb_brush_t1.rgb[1], rgb_brush_t1.rgb[2]));
		hOldBrush = SelectBrush(context, hBrush);
		do
		{
			POINT pt;
			MoveToEx(context, t1.x[0], t1.y[0], &pt);
			LineTo(context, t1.x[1], t1.y[1]);
			LineTo(context, t1.x[2], t1.y[2]);
			LineTo(context, t1.x[0], t1.y[0]);
			MoveToEx(context, t2.x[0], t2.y[0], &pt);
			LineTo(context, t2.x[1], t2.y[1]);
			LineTo(context, t2.x[2], t2.y[2]);
			LineTo(context, t2.x[0], t2.y[0]);
			FloodFill(context, t2.x[2] + 5, t2.y[2] + 5, RGB(rgb_pen_t1.rgb[0], rgb_pen_t1.rgb[1], rgb_pen_t1.rgb[2]));
		} while (_getch() != 27);
		SelectPen(context, hOldPen);
		SelectBrush(context, hOldBrush);
		DeletePen(hPen);
		DeleteBrush(hBrush);
		ReleaseDC(ind, context);
	}
	/*void draw(int vibor) override
	{
		if (CheckTriangle(t1) == false || CheckTriangle(t1) == false) throw 0;
		for (int i = 0; i < 3; i++) if (square(t2, i) == false) throw 2;
		if (CheckTriangle(t2) == false) throw 1;
		HWND ind = GetConsoleWindow();// индентификатор окна
		HDC context = GetDC(ind);    //контекст отображения
		RECT rt;                    //структура с полями left, top, right, bottom
		HPEN hPen, hOldPen;       //Получение индетификатора пера
		HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
		SetBkColor(context, RGB(0, 0, 0));
		SetTextColor(context, RGB(0, 255, 0));
		hPen = CreatePen(PS_SOLID, rgb_pen_t1.width, RGB(rgb_pen_t1.rgb[0], rgb_pen_t1.rgb[1], rgb_pen_t1.rgb[2]));
		hOldPen = SelectPen(context, hPen);
		hBrush = CreateSolidBrush(RGB(rgb_brush_t1.rgb[0], rgb_brush_t1.rgb[1], rgb_brush_t1.rgb[2]));
		hOldBrush = SelectBrush(context, hBrush);
		do
		{
			POINT pt;
			MoveToEx(context, t1.x[0], t1.y[0], &pt);
			LineTo(context, t1.x[1], t1.y[1]);
			LineTo(context, t1.x[2], t1.y[2]);
			LineTo(context, t1.x[0], t1.y[0]);
			MoveToEx(context, t2.x[0], t2.y[0], &pt);
			LineTo(context, t2.x[1], t2.y[1]);
			LineTo(context, t2.x[2], t2.y[2]);
			LineTo(context, t2.x[0], t2.y[0]);
			FloodFill(context, t2.x[2] + 5, t2.y[2] + 5, RGB(rgb_pen_t1.rgb[0], rgb_pen_t1.rgb[1], rgb_pen_t1.rgb[2]));
		} while (_getch() != 27);
		SelectPen(context, hOldPen);
		SelectBrush(context, hOldBrush);
		DeletePen(hPen);
		DeleteBrush(hBrush);
		ReleaseDC(ind, context);
	}*/
};