#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Student
{
    char name[50];
    int marks;
    char grade;
};

ostream& tab(ostream& output)
{
    return output << setw(20) << left;
}

void generateReport(const char* filename)
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

int main()
{
    const char* filename = "students.dat";
    generateReport(filename);
    return 0;
}
