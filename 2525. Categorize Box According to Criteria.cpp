

class Solution {
public:
    std::string categorizeBox(int length, int width, int height, int mass) {
        
        bool isBulky = (length >= pow(10,4)) || (width >= pow(10,4)) || (height >= pow(10,4)) || (static_cast<long long>(length) * width * height >= pow(10,9));

        
        bool isHeavy = (mass >= 100);

        
        if (isBulky && isHeavy) {
            return "Both";
        } else if (isBulky && !isHeavy) {
            return "Bulky";
        } else if (!isBulky && isHeavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};
