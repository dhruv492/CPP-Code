#include <iostream>
#include <string>
using namespace std;

class SuperDigitCalculator 
{
    int superDigit(int num)
    {
        if (num < 10)
            return num;
        return superDigit(sumOfDigits(num));
    }

    int sumOfDigits(int num) 
    {
        int sum = 0;
        while (num > 0) 
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    public:
        int calculateSuperDigit(const string& n, int k) 
        {
            if (k <= 0)
                return -1;
            int initialSum = 0;
            for (char digit : n)
            {
                if (!isdigit(digit)) 
                    return -1;
                initialSum += digit - '0';
            }
            int multipliedSum = initialSum * k;
            return superDigit(multipliedSum);
        }
};

int main()
{
    string n;
    int k;
    cin >> n >> k;
    SuperDigitCalculator calculator;
    int result = calculator.calculateSuperDigit(n, k);
    if (result != -1) cout << result << endl;
    return 0;
}
