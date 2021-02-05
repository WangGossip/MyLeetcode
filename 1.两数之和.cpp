/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // hash[k]表示nums中数值为k的下标
        map<int, int> hash_t;
        vector<int> ret;
        int i;
        int len = nums.size();
        for (i = 0; i < len; i++)
        {
            if(hash_t.find(target-nums[i])!=hash_t.end())
            {
                ret.push_back(hash_t[target-nums[i]]);
                ret.push_back(i);
                return ret;
            }
            hash_t[nums[i]]=i;
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};
// @lc code=end
