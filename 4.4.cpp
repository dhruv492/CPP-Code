#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;
    double lastTransaction;

public:
    BankAccount(int accountNumber, double initialBalance)
        : accountNumber(accountNumber), balance(initialBalance), lastTransaction(0.0) {}

    virtual ~BankAccount()
    {
        cout << "BankAccount with account number " << accountNumber << " is being closed.\n";
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        lastTransaction = amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            lastTransaction = -amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance for withdrawal.\n";
        }
    }

    void undoLastTransaction()
    {
        balance -= lastTransaction;
        cout << "Undid last transaction: " << lastTransaction
             << ", New Balance: " << balance << endl;
        lastTransaction = 0;
    }

    virtual void displayDetails() const
    {
        cout << "Account Number: " << accountNumber
             << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accountNumber, double initialBalance, double interestRate)
        : BankAccount(accountNumber, initialBalance), interestRate(interestRate) {}

    void applyInterest()
    {
        double interest = balance * interestRate / 100;
        deposit(interest);
        cout << "Applied Interest: " << interest << ", New Balance: " << balance << endl;
    }

    void displayDetails() const override
    {
        BankAccount::displayDetails();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CurrentAccount : public BankAccount
{
    double overdraftLimit;

public:
    CurrentAccount(int accountNumber, double initialBalance, double overdraftLimit)
        : BankAccount(accountNumber, initialBalance), overdraftLimit(overdraftLimit) {}

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
            lastTransaction = -amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
        else
        {
            cout << "Overdraft limit exceeded.\n";
        }
    }

    void displayDetails() const override
    {
        BankAccount::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main()
{
    SavingsAccount savings(1001, 5000, 3.5);
    CurrentAccount current(2001, 3000, 1000);

    cout << "Savings Account Details:\n";
    savings.displayDetails();
    savings.deposit(1000);
    savings.withdraw(1500);
    savings.applyInterest();
    savings.undoLastTransaction();
    cout << "-----------------------------\n";

    cout << "Current Account Details:\n";
    current.displayDetails();
    current.deposit(2000);
    current.withdraw(4500);
    current.withdraw(6000);
    current.undoLastTransaction();
    cout << "-----------------------------\n";

}
