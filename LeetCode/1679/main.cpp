
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> f;
        int count = 0;

        for (int num : nums)
        {
            int d = k - num;
            if (f[d] > 0)
            {
                count++;
                f[d]--;
            }
            else if (f[num] == 0)
                f[num] = 1;
            else
                f[num]++;
        }
        return count;
    }
};