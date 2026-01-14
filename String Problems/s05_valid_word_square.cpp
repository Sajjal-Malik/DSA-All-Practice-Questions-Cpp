#include <bits/stdc++.h>
using namespace std;

/**
 * Checks if a given list of strings forms a valid word square.
 * A sequence of strings forms a valid word square if the kth row
 * and kth column read the exact same string for all 0 <= k < max(rows, cols).
 */
bool isValidWordSquare(const vector<string> &words)
{
    int rowCount = words.size();

    for (int row = 0; row < rowCount; ++row)
    {
        int colCount = words[row].size();

        for (int col = 0; col < colCount; ++col)
        {
            // Check boundaries to prevent out-of-bounds access:
            // 1. If 'col' is an index larger than the number of available rows.
            // 2. If 'row' is an index larger than the length of the string at words[col].
            if (col >= rowCount || row >= words[col].size())
            {
                return false;
            }

            // Verify symmetry: character at (row, col) must match (col, row).
            if (words[row][col] != words[col][row])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // Test Case 1: Valid Word Square
    vector<string> validSquare = {
        "abcd",
        "bnrt",
        "crmy",
        "dtye"};

    // Test Case 2: Invalid Word Square
    vector<string> invalidSquare = {
        "ball",
        "area",
        "read", // 'read' vs 'lead' logic failure
        "lady"};

    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test Case 1 is valid: " << isValidWordSquare(validSquare) << endl;
    cout << "Test Case 2 is valid: " << isValidWordSquare(invalidSquare) << endl;

    return 0;
}
