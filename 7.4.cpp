#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class StudentReport
{
private:
    struct Student
    {
        char name[50];
        int marks;
        char grade;
    };

    const char* filename;

    ostream& tab(ostream& output)
    {
        return output << setw(20) << left;
    }

public:
    StudentReport(const char* file) : filename(file) {}

    void generateReport()
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            cout << "Error: Unable to open file." << endl;
            return;
        }

        Student student;
        cout << tab << "Name" << tab << "Marks" << tab << "Grade" << endl;
        cout << string(60, '-') << endl;

        while (file.read(reinterpret_cast<char*>(&student), sizeof(Student)))
        {
            cout << tab << student.name << tab << student.marks << tab << student.grade << endl;
        }

        file.close();
    }
};

int main()
{
    StudentReport report("students.dat");
    report.generateReport();
    return 0;
}
