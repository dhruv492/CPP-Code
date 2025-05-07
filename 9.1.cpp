#include <iostream>

using namespace std;

class LoanCalculator
{
private:
    double loanAmount;
    double annualIncome;

    double getValidInput(const string& prompt)
    {
        double value;
        while (true)
        {
            cout << prompt;
            cin >> value;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a numeric value.\n";
            }
            else if (value <= 0)
            {
                cout << "Value must be greater than zero. Try again.\n";
            }
            else
            {
                return value;
            }
        }
    }

public:
    void inputData()
    {
        loanAmount = getValidInput("Enter loan amount: ");
        annualIncome = getValidInput("Enter annual income: ");
    }

    void calculateRatio() const
    {
        double ratio = loanAmount / annualIncome;
        cout << "Loan-to-Income Ratio: " << ratio << endl;
    }
};

int main()
{
    LoanCalculator calculator;
    calculator.inputData();
    calculator.calculateRatio();

    return 0;
}
