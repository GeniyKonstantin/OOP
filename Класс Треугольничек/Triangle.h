#pragma once
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Triangle
{
private:
	float m_x[3], m_y[3],m_x2[3],m_y2[3];
	int m_rgbpen[3],m_rgbbrush[3],m_width;
public:
	// прототипы функций
	void set_width(int w);
	int get_width() const;
	vector <int> get_rgbbrush() const;
	void set_rgbbrush(int* rgb) ;
	void set_rgbbrush(int r, int g, int b);
	void set_rgbpen(int rgb[3]);
	void set_rgbpen(int r, int g, int b);
	vector <int> get_rgbpen() const;
	void set_coord(float x[3],float y[3],int nomer);
	void set_firstx(float a, float b, float c);
	void set_secondx(float a, float b, float c);
	void set_firsty(float a, float b, float c);
	void set_secondy(float a, float b, float c);
	void drawPainted();
	void drawUnpainted();
	void drawNestedTriangles();
	void newfile(string s) const;
	void readfile(string s);
	void up(float up);
	void down(float down);
	void right(float right);
	void left(float left);
	vector <float> get_x1() const;
	vector <float> get_x2() const;
	vector <float> get_y1() const;
	vector <float> get_y2() const;
};