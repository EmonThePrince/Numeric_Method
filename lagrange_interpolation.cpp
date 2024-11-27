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

    double interpolate(double xi) {
        double res = 0;
        int n = x.size();
        for (int i = 0; i < n; i++) {
            double term = y[i];
            for (int j = 0; j < n; j++) {
                if (i != j)
                    term *= (xi - x[j]) / (x[i] - x[j]);
            }
            res += term;
        }
        return res;
    }
};

int main() {
    vector<double> x = {2, 2.5, 3.0};
    vector<double> y = {0.69315, 0.91629, 1.09861};
    Lagrange lag(x, y);
    cout << lag.interpolate(2.7) <<endl;
    return 0;
}
