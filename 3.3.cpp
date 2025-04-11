#include <iostream>
using namespace std;

class AccountManager
{
    int AccNumber;
    string Name;
    float Balance;
    static int Count;

public:
    int returnAccNum() { return AccNumber; }

    // Utility function
    static int returnCount() { return Count; }

    AccountManager() : AccNumber(0), Name(""), Balance(0) {} // Default constructor

    AccountManager(int accn, string n, float b) // Parameterized constructor
    {
        AccNumber = accn;
        Name = n;
        Balance = b;
        Count++;
    }

    void Transfer(AccountManager &A, float b) // Transfer money between accounts
    {
        if (Balance >= b)
        {
            Balance -= b;
            A.Balance += b;
        }
        else
        {
            cout << "\nInsufficient balance for transfer!" << endl;
        }
    }

    void DisplayDetails()
    {
        cout << "\nName: " << Name;
        cout << "\nAccount Number: " << AccNumber;
        cout << "\nBalance: " << Balance;
    }
};

int AccountManager::Count = 0; // Initializing static variable

int main()
{
    AccountManager A[100]; // Fixed-size array for storing accounts
    int totalAccounts = 0;
    int choice = 0;

    do
    {
        cout << "\n\nBank Account Management System";
        cout << "\nChoices:\n1. Add New Account\n2. Transfer Money\n3. Display all accounts\n0. Exit\nEnter your choice: ";
        cin >> choice;

        string Name;
        float Bal = 0;
        int AccNum = 1, MyAccNum = 1, i, chk;

        switch (choice)
        {
        case 1:
            if (totalAccounts < 100)
            {
                cout << "\nAdding New Account:";
                cout << "\nEnter Name: ";
                cin.ignore();
                getline(cin, Name);
                cout << "Enter Balance: ";
                cin >> Bal;
                cout << "Enter Account Number: ";
                cin >> AccNum;

                A[totalAccounts] = AccountManager(AccNum, Name, Bal); // Storing new account in array
                totalAccounts++;
                cout << "Account added successfully!";
            }
            else
            {
                cout << "Account limit reached!";
            }
            break;

        case 2:
            cout << "\nTransferring Money:";
            cout << "\nEnter your Account Number: ";
            cin >> MyAccNum;
            cout << "Enter recipient Account Number: ";
            cin >> AccNum;
            cout << "Enter amount to transfer: ";
            cin >> Bal;

            chk = 0;
            for (i = 0; i < totalAccounts; i++)
            {
                if (A[i].returnAccNum() == MyAccNum) // Finding sender account
                {
                    chk++;
                    for (int j = 0; j < totalAccounts; j++)
                    {
                        if (A[j].returnAccNum() == AccNum) // Finding recipient account
                        {
                            chk++;
                            A[i].Transfer(A[j], Bal);
                            break;
                        }
                    }
                    break;
                }
            }
            if (chk < 2)
            {
                cout << "\nNo such Account found! Try again.";
            }
            else
            {
                cout << endl << Bal << " Rupees transferred successfully!";
            }
            break;

        case 3:
            cout << "\nDisplaying " << AccountManager::returnCount() << " accounts:";
            for (i = 0; i < totalAccounts; i++)
            {
                cout << "\n\nAccount " << i + 1;
                A[i].DisplayDetails();
            }
            break;

        default:
            break;
        }
    } while (choice == 1 || choice == 2 || choice == 3);

    cout << "\n\nExiting System...";
    return 0;
}
