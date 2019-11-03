bool CheckPole(float x[3], float y[3])
{
	HWND ind = GetConsoleWindow();// индентификатор окна
	HDC context = GetDC(ind);    //контекст отображения
	RECT rt;                    //структура с полями left, top, right, bottom
	bool k = false;
	GetClientRect(ind, &rt);
	for (int i = 0; i < 3; i++)
	{
		if (x[i] < rt.right && y[i] < rt.bottom)
			k = true;
		else
			return false;
	}
	return k;
}
