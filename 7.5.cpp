#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

ostream& currency(ostream& os)
{
    return os << "₹";
}

int main()
{
    string names[] = {"John Doe", "Jane Smith", "Samuel Lee"};
    float marks[] = {88.75, 92.50, 78.90};
    float tuition_fee = 35000.50;

    cout << left << setw(20) << "Student Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(45) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < 3; ++i)
    {
        cout << left << setw(20) << names[i] << setw(10) << fixed << setprecision(2) << marks[i]
             << currency << setw(10) << fixed << setprecision(2) << tuition_fee << endl;
    }


    return 0;
}
