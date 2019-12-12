#include "Triangle.h"
#include "Stack.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Stack <Outline*> a;
	a.readfile("Text.txt");
	a.readfile("Moy file.txt");
	int vibor;
	do {
		cout << "выберете из 3:\n1-рисовать\n2-удалить верхний элемент\n 3-выйти из программы\n " << endl;
		cin >> vibor;
		system("cls");
		switch (vibor)
		{
		case 1:
			a.draw();
			break;
		case 2:
			a.pop_back();
			break;
		case 3:
			exit(0);

		}
	} while (vibor != 3);
}