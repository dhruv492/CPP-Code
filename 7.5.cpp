#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class StudentFeeReport
{
private:
    struct Student
    {
        string name;
        float marks;
    };

    Student students[3] = {
        {"John Doe", 88.75},
        {"Jane Smith", 92.50},
        {"Samuel Lee", 78.90}
    };

    float tuition_fee;

    ostream& currency(ostream& os) const
    {
        return os << "₹";
    }

public:
    StudentFeeReport(float fee) : tuition_fee(fee) {}

    void generateReport() const
    {
        cout << left << setw(20) << "Student Name"
             << setw(10) << "Marks"
             << setw(15) << "Tuition Fee" << endl;

        cout << setfill('-') << setw(45) << "" << endl;
        cout << setfill(' ');

        for (const auto& student : students)
        {
            cout << left << setw(20) << student.name << setw(10) << fixed << setprecision(2) << student.marks
                 << currency << setw(10) << fixed << setprecision(2) << tuition_fee << endl;
        }
    }
};

int main()
{
    StudentFeeReport report(35000.50);
    report.generateReport();
    return 0;
}
