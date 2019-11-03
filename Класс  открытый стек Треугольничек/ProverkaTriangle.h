bool CheckTriangle(float x[3], float y[3])
{
	bool k;
	float a, b, c;
	a = sqrt((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
	b = sqrt((x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]));
	c = sqrt((x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]));
	if (a + b > c && a + c > b && c + b > a)
		k = true;
	else
		return false;
	return k;
}