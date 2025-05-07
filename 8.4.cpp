#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StudentSorter
{
private:
    vector<pair<string, int>> students;

public:
    void inputStudents()
    {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;

        string name;
        int score;

        cout << "Enter the names and scores:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> name >> score;
            students.emplace_back(name, score);
        }
    }

    void sortStudents()
    {
        sort(students.begin(), students.end(), [](const pair<string, int>& a, const pair<string, int>& b)
        {
            return a.second > b.second;
        });
    }

    void displayStudents() const
    {
        cout << "\nSorted Students by Score:\n";
        for (const auto& student : students)
        {
            cout << student.first << " " << student.second << endl;
        }
    }
};

int main()
{
    StudentSorter sorter;
    sorter.inputStudents();
    sorter.sortStudents();
    sorter.displayStudents();

    return 0;
}
