#include <iostream>
#include <cmath>

using namespace std;

double function(double x)
{
    return pow(x, 3) + 10 * pow(x, 2) - 50;
}


double approx(double a, double b, double q, double eps)
{
    double xprevprev, xprev, xcurr;
    xprevprev = a;
    xprev = b;
    xcurr = b - function(b) * (b-a) / (function(b) - function(a));
    while (fabs(xcurr - xprev) >= eps)
    {
        xprevprev = xprev;
        xprev = xcurr;
        xcurr = xcurr - function(xprev) * (xprev - xprevprev) / (function(xprev) - function(xprevprev));
    }
    return xcurr;
}

int main()
{ 
    cout << "Enter a, b, h, eps:" << endl;
    double a, b, h, eps;
    cin >> a >> b >> h >> eps;
    cout << "Function : x^3 + 10x^2 - 50 " << endl
        << "List of roots : " << endl;
    for (double x = a; x <= b; x += h)
    {
        double root;
        if (function(x) * function(x + h) < 0)
        {
            root = approx(x, x + h, h, eps);
            cout << "Root : " << root << "  ::: F(" << root << ") = " << function(root) << endl;
        }
    }
    return 0;
}