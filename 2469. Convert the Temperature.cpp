class Solution {
public:
    vector<double> convertTemperature(double c) {
        double f=(c*9.000000/5.000000)+32;
        double k= c+273.150000;

        vector<double> v(0,2);

        v.push_back(k);
        v.push_back(f);

        return v;

        
    }
};
