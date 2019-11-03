#include "Triangle.h"
#include "proverkaVlojenosty.h"
#include "ProverkaTriangle.h"
#include "ProverkaPole.h"
//устанавливает ширину пера
void Triangle::set_width(int w) { m_width = w; };
// выводит ширину пера
int Triangle::get_width() const { return m_width; };
// устанавливает цвет кисти
void Triangle::set_rgbbrush(int* rgb) {
	for (int i = 0; i < 3; i++)
		m_rgbbrush[i] = rgb[i];
};
void Triangle::set_rgbbrush(int r, int g, int b) {
	m_rgbbrush[0] = r;
	m_rgbbrush[1] = g;
	m_rgbbrush[2] = b;
};
//возвращает цвет кисти
vector <int> Triangle::get_rgbbrush() const {
	vector <int> rgb(3);
	for (int i = 0; i < 3; i++)
		rgb[i] = m_rgbbrush[i];
	return rgb;
};
//устанавливает  цвет пера
void Triangle::set_rgbpen(int rgb[3]) {
	for (int i = 0; i < 3; i++)
		m_rgbpen[i] = rgb[i];
};
void Triangle::set_rgbpen(int r, int g, int b) {
	m_rgbpen[0] = r;
	m_rgbpen[1] = g;
	m_rgbpen[2] = b;
};
//возвращает цвет пера
vector <int> Triangle::get_rgbpen() const  {
	vector <int> rgb(3);
	for (int i = 0; i < 3; i++)
		rgb[i] = m_rgbpen[i];
	return rgb;
};
//устанавливает координаты, (nomer-номер треугольника)
void Triangle::set_coord(float x[3], float y[3],int nomer) { 
	if (CheckTriangle(x, y) == false || CheckPole(x,y)==false)
		throw 0;
	if (nomer == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			m_x[i] = x[i];
			m_y[i] = y[i];
		}
	}
	else 
		if (CheckTriangle(x, y) == false) throw 1;
		for (int i = 0; i < 3; i++)
		{
			if (square(m_x, m_y, x, y, i) == false) throw 2;
			m_x2[i] = x[i];
			m_y2[i] = y[i];
		}

};
void Triangle::set_firstx(float a, float b, float c) {
	m_x[1] = a;
	m_x[2] = b;
	m_x[3] = c;
};
void Triangle::set_secondx(float a, float b, float c) {
	m_x2[1] = a;
	m_x2[2] = b;
	m_x2[3] = c;
};;
void Triangle::set_firsty(float a, float b, float c) {
	m_y[1] = a;
	m_y[2] = b;
	m_y[3] = c;
};;
void Triangle::set_secondy(float a, float b, float c) {
	m_y2[1] = a;
	m_y2[2] = b;
	m_y2[3] = c;
};;
// возвращает значения координат
vector <float> Triangle::get_x1() const  {
	vector <float > v(3);
	for (int i = 0; i < 3; i++) v[i] = m_x[i];
	return v;
};
vector <float> Triangle::get_x2() const  {
	vector <float > v(3);
	for (int i = 0; i < 3; i++) v[i] = m_x2[i];
	return v;
};
vector <float> Triangle::get_y1() const  {
	vector <float > v(3);
	for (int i = 0; i < 3; i++) v[i] = m_y[i];
	return v;
};
vector <float> Triangle::get_y2() const  {
	vector <float > v(3);
	for (int i = 0; i < 3; i++) v[i] = m_y2[i];
	return v;
};
//рисует закрашенный треугольник
void Triangle::drawPainted()  {
	if (CheckTriangle(m_x, m_y) == false || CheckPole(m_x, m_y) == false) throw 0;
	HWND ind = GetConsoleWindow();// индентификатор окна
	HDC context = GetDC(ind);    //контекст отображения
	RECT rt;                    //структура с полями left, top, right, bottom
	HPEN hPen, hOldPen;       //Получение индетификатора пера
	HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
	SetBkColor(context, RGB(0, 0, 0));
	SetTextColor(context, RGB(0, 255, 0));
	hPen = CreatePen(PS_SOLID, m_width, RGB(m_rgbpen[0], m_rgbpen[1], m_rgbpen[2]));
	hOldPen = SelectPen(context, hPen);
	hBrush = CreateSolidBrush(RGB(m_rgbbrush[0], m_rgbbrush[1], m_rgbbrush[2]));
	hOldBrush = SelectBrush(context, hBrush);
	do {
		POINT treugolnik[4] = { {m_x[0],m_y[0]},{m_x[1],m_y[1]},{m_x[2],m_y[2]},{m_x[0],m_y[0]} };
		Polygon(context, treugolnik, 4);
	} while (_getch() != 27);
	SelectPen(context, hOldPen);
	SelectBrush(context, hOldBrush);
	DeletePen(hPen);
	DeleteBrush(hBrush);
	ReleaseDC(ind, context);
};
// рисует незакрашенный треугольник
void Triangle::drawUnpainted() {
	if (CheckTriangle(m_x, m_y) == false || CheckPole(m_x, m_y) == false) throw 0;
	HWND ind = GetConsoleWindow();// индентификатор окна
	HDC context = GetDC(ind);    //контекст отображения
	RECT rt;                    //структура с полями left, top, right, bottom
	HPEN hPen, hOldPen;       //Получение индетификатора пера
	SetBkColor(context, RGB(0, 0, 0));
	SetTextColor(context, RGB(0, 255, 0));
	hPen = CreatePen(PS_SOLID, m_width, RGB(m_rgbpen[0], m_rgbpen[1], m_rgbpen[2]));
	hOldPen = SelectPen(context, hPen);
	do {
		POINT treugolnik[4] = { {m_x[0],m_y[0]},{m_x[1],m_y[1]},{m_x[2],m_y[2]},{m_x[0],m_y[0]} };
		Polyline(context, treugolnik, 4);
	} while (_getch() != 27);
	SelectPen(context, hOldPen);
	DeletePen(hPen);
	ReleaseDC(ind, context);
	};
// рисует вложенные треугольники
void Triangle::drawNestedTriangles() {
	if (CheckTriangle(m_x, m_y) == false || CheckPole(m_x, m_y) == false) throw 0;
	for (int i = 0; i < 3; i++) if (square(m_x, m_y, m_x2, m_y2, i) == false) throw 2;
	if (CheckTriangle(m_x2, m_y2) == false) throw 1;
	HWND ind = GetConsoleWindow();// индентификатор окна
	HDC context = GetDC(ind);    //контекст отображения
	RECT rt;                    //структура с полями left, top, right, bottom
	HPEN hPen, hOldPen;       //Получение индетификатора пера
	HBRUSH hBrush, hOldBrush;//Получение индетификатора кисти
	SetBkColor(context, RGB(0, 0, 0));
	SetTextColor(context, RGB(0, 255, 0));
	hPen = CreatePen(PS_SOLID, m_width, RGB(m_rgbpen[0], m_rgbpen[1], m_rgbpen[2]));
	hOldPen = SelectPen(context, hPen);
	hBrush = CreateSolidBrush(RGB(m_rgbbrush[0], m_rgbbrush[1], m_rgbbrush[2]));
	hOldBrush = SelectBrush(context, hBrush);
	do
	{
		POINT pt;
		MoveToEx(context, m_x[0], m_y[0], &pt);
		LineTo(context, m_x[1], m_y[1]);
		LineTo(context, m_x[2], m_y[2]);
		LineTo(context, m_x[0], m_y[0]);
		MoveToEx(context, m_x2[0], m_y2[0], &pt);
		LineTo(context, m_x2[1],m_y2[1]);
		LineTo(context, m_x2[2], m_y2[2]);
		LineTo(context, m_x2[0], m_y2[0]);
		FloodFill(context, m_x2[2] + 5, m_y2[2] + 5, RGB(m_rgbpen[0], m_rgbpen[1], m_rgbpen[2]));

	} while (_getch() != 27);
	SelectPen(context, hOldPen);
	SelectBrush(context, hOldBrush);
	DeletePen(hPen);
	DeleteBrush(hBrush);
	ReleaseDC(ind, context);
};
// создает новый файл с именем (s) и сохраняет в него аргументы
void Triangle::newfile(string s) const  {
	ofstream outfile(s);
	for (int i = 0; i < 3; i++)
		outfile << m_x[i] << ' ' << m_y[i] << ' ';
	outfile << endl << m_width << endl;
	for (int i = 0; i < 3; i++) outfile << m_rgbpen[i] << ' ';
	outfile << endl;
	for (int i = 0; i < 3; i++) outfile << m_rgbbrush[i] << ' ';
	outfile << endl;
	for (int i = 0; i < 3; i++) outfile << m_x2[i] << ' ' << m_y2[i] << ' ';
	outfile << endl;
	outfile.close();
};
// читает из файла с именем (s) и вводит данные из него в аргументы
void Triangle::readfile(string s) {
	ifstream infile(s);
	if (infile.fail())throw 3;              // проверка файла
	for (int i = 0; i < 3; i++)
		infile >> m_x[i] >> m_y[i];
	if (CheckTriangle(m_x, m_y) == false || CheckPole(m_x, m_y) == false)
		throw 0;
	infile >> m_width;
	for (int i = 0; i < 3; i++)
		infile >> m_rgbpen[i];
	for (int i = 0; i < 3; i++)
		infile >> m_rgbbrush[i];
	for (int i = 0; i < 3; i++) {
		infile >> m_x2[i] >> m_y2[i];;
		if (square(m_x, m_y, m_x2, m_y2, i) == false) throw 2;
	}
	infile.close();
	if (CheckTriangle(m_x2, m_y2) == false) throw 1;

};
// поднимает треугольники на up
void Triangle::up(float up) {
	for (int i = 0; i < 3; i++) { m_y[i] += up; m_y2[i] += up; }
};
// опускает треугольники на down
void Triangle::down(float down) {
	for (int i = 0; i < 3; i++) { m_y[i] -= down; m_y2[i] -= down; }
};
// переместить треугольники вправо на right
void Triangle::right(float right) {
	for (int i = 0; i < 3; i++) { m_x[i] += right; m_x2[i] += right; }
};
// перемещает треугольники влево на left
void Triangle::left(float left) {
	for (int i = 0; i < 3; i++) { m_x[i] -= left; m_x2[i] -= left; }
};