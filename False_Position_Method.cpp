#include <bits/stdc++.h>


using namespace std;

class FalsePositionMethod {
private:
    function<double(double)> func;
    double a, b, precision;

public:
    FalsePositionMethod(function<double(double)> function, double precision)
        : func(function), precision(precision), a(0), b(0) {
        srand(static_cast<unsigned int>(time(0))); 
    }

    void generateInterval() {
        do {
            a = static_cast<double>(rand() % 1000) - 500; // Random value between -500 and 500
            b = static_cast<double>(rand() % 1000) - 500; // Random value between -500 and 500
            a = min(a,b);
            b = max(a,b);
        } while (func(a) * func(b) >= 0); 
    }

    double findRoot() {
        double c; 
        int i = 0;
        while (true) {
            c = (a * func(b) - b * func(a)) / (func(b) - func(a));

            if (abs(func(c)) <= precision) {
                return c;
            }

            if (func(c) * func(a) < 0) {
                b = c; 
            } else {
                a = c; 
            }

            if (abs(b - a) <= precision) {
                return (a + b) / 2.0; 
            }
             cout<<"x"<<i<<": "<<c<<endl;
             i++;
        }
    }

    void execute() {
        generateInterval();
        double root = findRoot();
        cout << "The value of root is: " << root << endl;
    }
};

double Function(double x) {
    return x * x * x - x * x + 2;
}
int main() {
    double precision;
    cout << "Enter the precision point: ";
    cin >> precision;

    FalsePositionMethod falsePosition(Function, precision);
    falsePosition.execute();

    return 0;
}
