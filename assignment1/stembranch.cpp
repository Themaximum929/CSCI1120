#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int D, M, Y;

	// User input
	cout << "Enter a date (D M Y): ";
	cin >> D >> M >> Y;

	// Calculate cyclic years
	int py = ((Y - 3) % 10 != 0) ? (Y - 3) % 10 : 10;
	int qy = ((Y - 3) % 12 != 0) ? (Y - 3) % 12 : 12;

	// Output cyclic years
	cout << "Year:  " << "S" << py << "-B" << qy << endl; 

	// Calculate cyclic date
	int t = (M <= 2) ? (Y - 1) : Y;
	int r = (M <= 2) ? (M + 12) : M;
	int C = floor(t / 100);
	int a = t % 100;
	int g = 4 * C + floor(C / 4) + (5.0 * a) + floor(a / 4) + floor(3 * (r + 1) / 5) + D - 3;
	int i = (r % 2 == 1) ? 6 : 0;
	int z = 8 * C + floor(C / 4) + (5.0 * a) + floor(a / 4) + floor(3 * (r + 1) / 5) + D + 1 + i;
	
	int pd = (g % 10 != 0) ? (g % 10) : 10;
	int qd = (z % 12 != 0) ? (z % 12) : 12; 

	// Output cyclic month and date
	cout << "Month: " << M << endl;
	cout << "Day:   " << "S" << pd << "-B" << qd;

	return 0;

}
