#include"Triangle.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Nested nest;
	Painted paint;
	Outline out;
	int vibor;
	do {
		cout << "�������� �� 4:\n 1 = �� ����������� �����������, 2 = ����������� �����������, 3 = ��������� ������, 4 - ���������� ���������." << endl;
		cin >> vibor;
		system("cls");
		switch (vibor)
		{
		case 1:
			out.read_file("Text.txt");
			out.draw();
			break;
		case 2:
			paint.read_file("Text.txt");
			paint.draw();
			break;
		case 3:
			nest.read_file("Text.txt");
			nest.draw();
			break;
		case 4:
			exit(0);

		}
	} while (vibor != 4);
}