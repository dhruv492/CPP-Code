#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseWithIterators(vector<int>& sequence)
{
    auto start = sequence.begin();
    auto end = sequence.end() - 1;

    while (start < end)
    {
        swap(*start, *end);
        ++start;
        --end;
    }
}

int main()
{
    int n;
    cout << "Enter the number of integers in the sequence: ";
    cin >> n;

    vector<int> sequence(n);

    cout << "Enter the sequence of " << n << " integers: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> sequence[i];
    }

    cout << "Original Sequence: ";
    for (const auto& num : sequence)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> seq1 = sequence;
    reverse(seq1.begin(), seq1.end());
    cout << "Reversed Sequence (std::reverse): ";
    for (const auto& num : seq1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> seq2 = sequence;
    reverseWithIterators(seq2);
    cout << "Reversed Sequence (manual iterators): ";
    for (const auto& num : seq2)
    {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}
