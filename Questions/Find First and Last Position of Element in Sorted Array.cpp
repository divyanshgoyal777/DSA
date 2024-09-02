#include <iostream>
#include <vector>
using namespace std;

int main() {
    int array[] = {5, 7, 7, 8, 8, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 8;
    int left = 0;
    int right = size - 1;
    int first = -1;
    int last = -1;

    vector<int> result;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            first = mid;
            right = mid - 1;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = 0;
    right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            last = mid;
            left = mid + 1;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    result.push_back(first);
    result.push_back(last);

    cout << "First position: " << result[0] << endl;
    cout << "Last position: " << result[1] << endl;

    return 0;
}
