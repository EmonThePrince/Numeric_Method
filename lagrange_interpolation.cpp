#include <bits/stdc++.h>

using namespace std;

class Lagrange {
private:
    vector<double> x, y;

public:
    Lagrange(vector<double>& xx, vector<double>& yy) {
        x = xx;
        y = yy;
    }

    double runX(double xi) {
        double res = 0;
        int n = x.size();
        for (int i = 0; i < n; i++) {
            double c = y[i];
            for (int j = 0; j < n; j++) {
                if (i != j)
                    c *= (xi - x[j]) / (x[i] - x[j]);
            }
            res += c;
        }
        return res;
    }
    double runY(double yi) {
        double res = 0;
        int n = y.size();
        for (int i = 0; i < n; i++) {
            double c = x[i];
            for (int j = 0; j < n; j++) {
                if (i != j){
                    c *= (yi - y[j]) / (y[i] - y[j]);
                    
                } 
            }
            res += c;
        }
        return res;
    }
};

int main() {
    vector<double> x = {2, 2.5, 3.0};
    vector<double> y = {0.69315, 0.91629, 1.09861};
    vector<double> x1 = {1, 3, 4};
    vector<double> y1 = {4, 12, 19};
    Lagrange lag(x, y);
    Lagrange lag1(x1,y1);
    cout << lag.runX(2.7) <<endl;
    cout << lag1.runY(7) <<endl;
    return 0;
}
