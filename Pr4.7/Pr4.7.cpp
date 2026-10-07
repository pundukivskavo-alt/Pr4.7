#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, x, dx, eps;
    double a = 0, R = 0, S = 0;
    int n = 0;
    const double PI = 3.14159265358979323846;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
        << setw(12) << "acos(x)" << " |"
        << setw(12) << "S" << " |"
        << setw(8) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = x;
        S = a;

        do {
            n++;
            R = (2.0 * n - 1.0) * (2.0 * n - 1.0) * x * x / ((2.0 * n) * (2.0 * n + 1.0));
            a *= R;
            S += a;
        } while (abs(a) >= eps);

        double S_final = PI / 2.0 - S;
        double F_exact = acos(x);

        cout << "|" << setw(8) << setprecision(2) << x << " |"
            << setw(12) << setprecision(5) << F_exact << " |"
            << setw(12) << setprecision(5) << S_final << " |"
            << setw(8) << n << " |"
            << endl;

        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}
