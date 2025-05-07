#include <iostream>
using namespace std;

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

int main()
{
    double loanAmount = getValidInput("Enter loan amount: ");
    double annualIncome = getValidInput("Enter annual income: ");

    double ratio = loanAmount / annualIncome;
    cout << "Loan-to-Income Ratio: " << ratio << endl;

    return 0;
}
