#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2)
{
    vector<int> result;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                bool found = false;
                for (int k = 0; k < result.size(); k++)
                {
                    if (result[k] == nums1[i])
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    result.push_back(nums1[i]);
                }
                break;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> array1 = {2, 2,3};
    vector<int> array2 = {1, 2, 2,1,2,4,3,1};

    vector<int> result = intersection(array1, array2);

    cout << "Intersection: ";
    for(int i =0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
