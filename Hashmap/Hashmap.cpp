#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // Declare an unordered_map
    unordered_map<string, int> myMap;

    // 1. Inserting elements into the unordered_map
    myMap["apple"] = 5; // Direct insertion
    myMap["banana"] = 10;
    myMap.insert({"orange", 7}); // Using insert()

    // 2. Accessing elements
    cout << "Price of apple: " << myMap["apple"] << endl;
    cout << "Price of banana: " << myMap["banana"] << endl;

    // 3. Searching for a key
    if (myMap.find("grape") != myMap.end())
    {
        cout << "Price of grape: " << myMap["grape"] << endl;
    }
    else
    {
        cout << "Grape not found!" << endl;
    }

    // 4. Updating an existing element
    myMap["apple"] = 6;
    cout << "Updated price of apple: " << myMap["apple"] << endl;

    // 5. Erasing an element
    myMap.erase("banana");
    cout << "Banana removed from the map" << endl;

    // 6. Checking the size of the unordered_map
    cout << "Current size of the map: " << myMap.size() << endl;

    // 7. Checking if the map is empty
    if (myMap.empty())
    {
        cout << "The map is empty." << endl;
    }
    else
    {
        cout << "The map is not empty." << endl;
    }

    // 8. Iterating through the unordered_map
    cout << "Current contents of the map:" << endl;
    for (const auto &pair : myMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 9. Using at() to access elements safely
    try
    {
        cout << "Price of orange: " << myMap.at("orange") << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Element not found!" << endl;
    }

    // 10. Clearing the unordered_map
    myMap.clear();
    cout << "Map cleared. Current size: " << myMap.size() << endl;

    return 0;
}
