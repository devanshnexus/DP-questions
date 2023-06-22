#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            int fact = 1;
            vector < int > numbers;
            // calculating the factorial for n-1, where n is no of elements in a string.
            for (int i = 1; i < n; i++) {
                fact = fact * i;
                numbers.push_back(i);
            }
            numbers.push_back(n);
            string ans = "";
            // normalizing k with index
            k = k - 1;
            while (true) {
                // adding the initial element of the answer string
                ans = ans + to_string(numbers[k / fact]);
                //deleting the discarded number from the string
                numbers.erase(numbers.begin() + k / fact);
                if (numbers.size() == 0) {
                    break;
                }
                k = k % fact;
                // reducing the scope of next iteration 
                fact = fact / numbers.size();
            }
        return ans;
    }
};

int main() {
    int n = 3, k = 3;
    Solution obj;
    string ans = obj.getPermutation(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;
    return 0;
}