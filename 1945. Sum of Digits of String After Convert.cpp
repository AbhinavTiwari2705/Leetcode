class Solution {
public:

    string strToInt(string str) {
        string sum = "";
        for (char c : str) {
            int num = c - 'a' + 1;
            sum += to_string(num);
        }
        return sum;
    }

    int sumDigits(string n) {
        int temp = 0;
        for (char x : n) {
            temp += x - '0'; 
        }
        return temp;
    }

 
    int getLucky(string s, int k) {
        string n = strToInt(s);

        for (int i = 0; i < k; i++) {
            int sum = sumDigits(n);
            n = to_string(sum);
        }

        return stoi(n);
    }
};
