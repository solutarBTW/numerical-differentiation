#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.14159265358979323846;

double mySin(double x)
{
    while (x > 2 * pi)
    {
        x -= 2 * pi;
    }
    while (x < -2 * pi)
    {
        x += 2 * pi;
    }

    double term = x;
    double sum = term;
    for (int n = 1; n < 10; ++n)
    {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
    }
    return sum;
}

double myCos(double x)
{
    while (x > 2 * pi)
    {
        x -= 2 * pi;
    }
    while (x < -2 * pi)
    {
        x += 2 * pi;
    }

    double term = 1;
    double sum = term;
    for (int n = 1; n < 10; ++n)
    {
        term *= -x * x / ((2 * n - 1) * (2 * n));
        sum += term;
    }
    return sum;
}

double myTan(double x)
{
    return mySin(x) / myCos(x);
}
void displaypoly(float coef[11], int degree)
{
    for(int i=0; i<=degree; i++)
    {
        if(i == 0)
        {
            cout<<coef[i]<<" + ";
        }

        else
        {
            cout<<coef[i]<<"*X^"<<i<<" + " ;
        }

    }
}
float polynomial(float coef[11], float degree, float x)
{
    float y=0.0;
    for (int i = 0; i<=degree; i++)
    {
        y += coef[i]*pow(x,i);
    }
    return y;
}
int main()
{
    double x, a, b, c, d;
    int choice;

    std::cout << "Choose the function to approximate derivative:\n";
    std::cout << "1. Sine\n2. Cosine\n3. Tangent\n4. polynomial \n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Enter x value for sine function: ";
        std::cin >> x;
        std::cout << "Approximate derivative of sine at x = " << x << ": " << myCos(x) << '\n';
        break;
    case 2:
        std::cout << "Enter x value for cosine function: ";
        std::cin >> x;
        std::cout << "Approximate derivative of cosine at x = " << x << ": " << -mySin(x) << '\n';
        break;
    case 3:
        std::cout << "Enter x value for tangent function: ";
        std::cin >> x;
        std::cout << "Approximate derivative of tangent at x = " << x << ": " << 1 + myTan(x) * myTan(x) << '\n';
        break;
    case 4:
        int degree ;
        cout<< "Degree of polynomial: ";
        cin>> degree;

        float coef[11];
        cout<<" input polynomial Constants: "<<endl;
        for (int i = 0; i<=degree; i++)
        {
            cout<<" coefficient "<<i<<":";
            cin>>coef[i];
        }

        displaypoly(coef, degree);
        float x;
        cout<<"\n input value for x for differntiation: ";
        cin>>x;
        float y =  polynomial(coef, degree, x);
        float h = 0.1;
        float x1 = x + h;
        float y1 =  polynomial(coef, degree, x1);
        float slope = (y1 - y) / h;
        cout<<"first drivarive = "<<slope <<endl;


        break;

        std::cout << "Invalid choice\n";
    }


    return 0;
}
