class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int front = 0, back = nums.size() - 1;
        while (back > front)
        {
            if (nums[back] % 2 != 0)
                back--;
            else if (nums[front] % 2 == 0)
                front++;
            else if (nums[front] % 2 != 0)
            {
                int t = nums[front];
                nums[front] = nums[back];
                nums[back] = t;
                front++;
            }
        }
        return nums;
    }
};