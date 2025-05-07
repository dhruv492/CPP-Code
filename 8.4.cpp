#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, score;
    string name;
    vector<pair<string, int>> students;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> name >> score;
        students.push_back({name, score});
    }

    sort(students.begin(), students.end(), [](pair<string, int> a, pair<string, int> b)
    {
        return a.second > b.second;
    });

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}
