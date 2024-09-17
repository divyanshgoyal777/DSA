#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    // 1. Unordered map with int as key and string as value
    unordered_map<int, string> idToName;
    idToName[1] = "Alice";
    idToName[2] = "Bob";
    idToName[3] = "Charlie";

    cout << "ID to Name mapping:" << endl;
    for (const auto &pair : idToName)
    {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }

    // 2. Unordered map with string as key and vector<int> as value
    unordered_map<string, vector<int>> studentGrades;
    studentGrades["Alice"] = {90, 85, 88};
    studentGrades["Bob"] = {75, 80, 72};
    studentGrades["Charlie"] = {95, 93, 97};

    cout << "\nStudent Grades:" << endl;
    for (const auto &pair : studentGrades)
    {
        cout << pair.first << "'s Grades: ";
        for (int grade : pair.second)
        {
            cout << grade << " ";
        }
        cout << endl;
    }

    // 3. Unordered map with char as key and bool as value
    unordered_map<char, bool> charMap;
    charMap['a'] = true;
    charMap['b'] = false;
    charMap['c'] = true;

    cout << "\nCharacter Map (True/False):" << endl;
    for (const auto &pair : charMap)
    {
        cout << pair.first << ": " << (pair.second ? "True" : "False") << endl;
    }

    return 0;
}
