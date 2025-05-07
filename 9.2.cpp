#include <iostream>
#include <string>

using namespace std;

struct Transaction 
{
    string type;
    double amount;
};

class BankAccount 
{
    double balance;
    Transaction transactionLog[100];
    int transactionCount;

public:
    BankAccount() : balance(0), transactionCount(0) {}

    void deposit(double amount) 
    {
        if (amount > 0) 
        {
            balance += amount;
            logTransaction("Deposit", amount);
            cout << "Deposited: " << amount << endl;
        } 
        else 
        {
            handleError("Invalid deposit amount.");
        }
    }

    void withdraw(double amount) 
    {
        if (amount > 0 && amount <= balance) 
        {
            balance -= amount;
            logTransaction("Withdraw", amount);
            cout << "Withdrew: " << amount << endl;
        }
        else 
        {
            handleError("Invalid withdrawal amount.");
        }
    }

    double getBalance() const 
    {
        return balance;
    }

    void printTransactionLog() const 
    {
        for (int i = 0; i < transactionCount; i++) 
        {
            cout << transactionLog[i].type << ": " << transactionLog[i].amount << endl;
        }
    }

private:
    void logTransaction(const string& type, double amount) 
    {
        if (transactionCount < 100) 
        {
            transactionLog[transactionCount].type = type;
            transactionLog[transactionCount].amount = amount;
            transactionCount++;
        }
    }

    void handleError(const string& message) 
    {
        cout << message << endl;
        logTransaction("Error", 0);
    }
};

int main() 
{
    BankAccount account;
    account.deposit(500);
    account.withdraw(200);
    account.withdraw(400);
    account.printTransactionLog();

    cout << "Current Balance: " << account.getBalance() << endl;

    return 0;
}
