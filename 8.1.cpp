#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SequenceReverser
{
private:
    vector<int> sequence;

    void reverseWithIterators()
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

public:
    void inputSequence()
    {
        int n;
        cout << "Enter the number of integers in the sequence: ";
        cin >> n;

        sequence.resize(n);
        cout << "Enter the sequence of " << n << " integers: ";
        for (int i = 0; i < n; ++i)
        {
            cin >> sequence[i];
        }
    }

    void displaySequence(const string& label, const vector<int>& seq) const
    {
        cout << label << ": ";
        for (const auto& num : seq)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    void processSequences()
    {
        displaySequence("Original Sequence", sequence);

        vector<int> seq1 = sequence;
        reverse(seq1.begin(), seq1.end());
        displaySequence("Reversed Sequence (std::reverse)", seq1);

        vector<int> seq2 = sequence;
        reverseWithIterators();
        displaySequence("Reversed Sequence (manual iterators)", sequence);
    }
};

int main()
{
    SequenceReverser reverser;
    reverser.inputSequence();
    reverser.processSequences();

    return 0;
}
