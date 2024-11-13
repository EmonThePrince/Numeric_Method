#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Interpol {
protected:
    vector<double> x, y;

public:
    Interpol(const vector<pair<double,double>>& data) {
        for(int i = 0; i < data.size(); i++) {
            x.push_back(data[i].first);
            y.push_back(data[i].second);
        }
    }

    virtual double interpolate(double val) = 0;
};

class NF : public Interpol {
public:
    NF(const vector<pair<double,double>>& data)
        : Interpol(data) {}

    double interpolate(double val) override {
        int n = x.size();
        vector<vector<double>> diff(n, vector<double>(n));
        double h = x[1] - x[0];

        for (int i = 0; i < n; ++i) {
            diff[i][0] = y[i];
        }

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < n - j; ++i) {
                diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
            }
        }

        double u = (val - x[0]) / h;
        double res = y[0];

        double f = 1;
        for (int i = 1; i < n; ++i) {
            f *= (u - (i - 1));
            res += (f * diff[0][i]) / fact(i);
        }

        return res;
    }

private:
    int fact(int n) {
        int res = 1;
        for (int i = 1; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
};

class NB : public Interpol {
public:
    NB(const vector<pair<double, double>>& data)
        : Interpol(data) {}

    double interpolate(double val) override {
        int n = x.size();
        vector<vector<double>> diff(n, vector<double>(n));
        double h = x[1] - x[0];

        for (int i = 0; i < n; ++i) {
            diff[i][0] = y[i];
        }

        
        for (int j = 1; j < n; ++j) {
            for (int i = n - 1; i >= j; --i) {
                diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
            }
        }

        double u = (val - x[n - 1]) / h;
        double res = y[n - 1];  

        double f = 1;
        for (int i = 1; i < n; ++i) {
            f *= (u + (i - 1));  
            res += (f * diff[n - 1][i]) / fact(i);
        }

        return res;
    }

private:
    int fact(int n) {
        int res = 1;
        for (int i = 1; i <= n; ++i) {
            res *= i;
        }
        return res;
    }
};

int main() {
    vector<pair<double,double>> data;
    int n, target;
    cin >> n >> target;
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        data.push_back({x, y});
    }
    
    NF nf(data);
    NB nb(data);
    
    

    cout << "Newton Forward " << target << " : " << nf.interpolate(target) << endl;
    cout << "Newton Backward " << target << " : " << nb.interpolate(target) << endl;

    return 0;
}
