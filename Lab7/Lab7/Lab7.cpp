#include <complex>
#include <iostream>

using namespace std;

double summa(const double& first_operand, const double& second_operand)
{ return first_operand + second_operand; }

complex<double> summa(const complex<double>& first_operand, const complex<double>& second_operand)
{ return first_operand + second_operand; }

int main()
{
    double a, b; cin >> a >> b; // Enter two real numbers: a b
    cout << summa(a, b) << endl;

    complex<double> c, d; cin >> c >> d; // Enter two complex numbers in the format: (a, b) (a, b)
    cout << summa(c, d) << endl;

    return 0;
}