#include "Triangle.h"
#include "Stack.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Stack <int> a;
	Triangle c;
	int b;
	ifstream f;
	f.open("Moy file.txt");
	while (!f.eof())
	{
		f >> b;
		a.push_back(b);
	}
	f.close();
	cout << "номер элемента со значением 240 : " << a.search(240) << endl;
	ofstream fin;
	fin.open("Noviy.txt");
	for (int i = 0; i < a.get_size(); i++)
	{
		fin << a[i]<<"\t";
	}
	fin.close();
	a.print();
	c.readfile("Noviy.txt");
	c.drawNestedTriangles();
	return 0;
}