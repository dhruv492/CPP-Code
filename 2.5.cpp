#include <iostream>
using namespace std;

class Loan
{
    char loanID[10];
    char applicantName[50];
    double loanAmount;
    double annualInterestRate;
    int loanTenureMonths;

public:
    Loan(const char* id, const char* name, double amount, double rate, int tenure)
    {
        int i = 0;
        while (id[i] != '\0' && i < 9) {
            loanID[i] = id[i];
            i++;
        }
        loanID[i] = '\0';

        i = 0;
        while (name[i] != '\0' && i < 49) {
            applicantName[i] = name[i];
            i++;
        }
        applicantName[i] = '\0';

        loanAmount = amount;
        annualInterestRate = rate;
        loanTenureMonths = tenure;
    }

    Loan() {
        char defaultID[] = "DefaultID";
        int i = 0;
        while (defaultID[i] != '\0' && i < 9) {
            loanID[i] = defaultID[i];
            i++;
        }
        loanID[i] = '\0';

        char defaultName[] = "DefaultName";
        i = 0;
        while (defaultName[i] != '\0' && i < 49) {
            applicantName[i] = defaultName[i];
            i++;
        }
        applicantName[i] = '\0';

        loanAmount = 0.0;
        annualInterestRate = 0.0;
        loanTenureMonths = 0;
    }

    double power(double base, int exp) const {
        double result = 1.0;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    double calculateEMI() const {
        if (loanTenureMonths == 0) return 0.0;

        double monthlyRate = annualInterestRate / (12 * 100);
        double emi = (loanAmount * monthlyRate * power(1 + monthlyRate, loanTenureMonths)) /
                     (power(1 + monthlyRate, loanTenureMonths) - 1);
        return emi;
    }

    void displayLoanDetails() const {
        std::cout << "Loan ID: " << loanID << std::endl;
        std::cout << "Applicant Name: " << applicantName << std::endl;
        std::cout << "Loan Amount: " << loanAmount << std::endl;
        std::cout << "Annual Interest Rate: " << annualInterestRate << "%" << std::endl;
        std::cout << "Loan Tenure (Months): " << loanTenureMonths << std::endl;
        std::cout << "Monthly EMI: " << calculateEMI() << std::endl;
    }
};

int main() {
    Loan loan1("L001", "John Doe", 500000, 7.5, 60);
    Loan loan2;

    std::cout << "Loan 1 Details:" << std::endl;
    loan1.displayLoanDetails();
    std::cout << std::endl;

    std::cout << "Default Loan Details:" << std::endl;
    loan2.displayLoanDetails();

    return 0;
}
