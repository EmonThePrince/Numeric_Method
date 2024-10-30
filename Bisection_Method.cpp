#include <bits/stdc++.h>


using namespace std;

class BisectionMethod {
private:
    function<double(double)> func;
    double a, b, precision;

public:
    BisectionMethod(function<double(double)> function, double precision)
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
        double mid;
        int i = 0;
        while ((b - a) / 2.0 > precision) {
            mid = (a + b) / 2.0;
            if (func(mid) == 0.0) {
                return mid; 
            } else if (func(a) * func(mid) < 0) {
                b = mid; 
            } else {
                a = mid; 
                
            }
            cout<<"x"<<i<<": "<<mid<<endl;
            i++;
        }
        return (a + b) / 2.0;
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

    BisectionMethod bisection(Function, precision);
    bisection.execute();

    return 0;
}
