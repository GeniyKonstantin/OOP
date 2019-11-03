bool square(float x1[3], float y1[3], float x2[], float y2[], int n)
{
	float p, a, b, c, O1, O2, O3, S[4];
	a = sqrt((x1[1] - x1[0]) * (x1[1] - x1[0]) + (y1[1] - y1[0]) * (y1[1] - y1[0]));
	b = sqrt((x1[2] - x1[1]) * (x1[2] - x1[1]) + (y1[2] - y1[1]) * (y1[2] - y1[1]));
	c = sqrt((x1[0] - x1[2]) * (x1[0] - x1[2]) + (y1[0] - y1[2]) * (y1[0] - y1[2]));
	p = (a + b + c) / 2;
	S[0] = sqrt(p * (p - a) * (p - b) * (p - c));
	O1 = sqrt((x2[n] - x1[0]) * (x2[n] - x1[0]) + (y2[n] - y1[0]) * (y2[n] - y1[0]));
	O2 = sqrt((x2[n] - x1[1]) * (x2[n] - x1[1]) + (y2[n] - y1[1]) * (y2[n] - y1[1]));
	O3 = sqrt((x2[n] - x1[2]) * (x2[n] - x1[2]) + (y2[n] - y1[2]) * (y2[n] - y1[2]));
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