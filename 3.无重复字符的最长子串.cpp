/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //双指针
        // bool have_char;
        // int i,j,len, longest_num, longest_now,t;
        // len=s.length();
        // longest_num=0;
        // longest_now=0;
        // // have_char=false;
        // i=0;
        // for(j=i;j<len;j++)
        // {
        //     //判断目前子串是否存在结尾字符
        //     for(t=i;t<j;t++)
        //     {
        //         if(s[t]==s[j])
        //         {
        //             have_char=true;
        //             longest_num=longest_num>longest_now?longest_num:longest_now;
        //             i=t+1;
        //             longest_now=j-t;
        //             break;
        //         }
        //     }
        //     // longest_now++;
        //     if(!have_char)
        //     {
        //         longest_now++;
        //     }
        //     have_char=false;
        // }
        // longest_num=longest_num>longest_now?longest_num:longest_now;
        //hash_char[k]表示ascii码为k对应的数组下标
        map<int, int> hash_char;
        int i, j, len, longest_num, longest_now, t;
        len = s.length();
        longest_num = 0;
        longest_now = 0;
        i = 0;
        for (j = i; j < len; j++)
        {
            // cout<<j<<":"<<longest_num<<endl;
            //当前字符是否存在
            if (hash_char.find((int)s[j]) != hash_char.end())
            {
                t = hash_char[(int)s[j]];
                if (t >= i)
                {
                    //cout<<t<<endl;
                    longest_num = longest_num > longest_now ? longest_num : longest_now;
                    i = t + 1;
                    longest_now = j - t;
                }
                else
                {
                    longest_now++;
                }
            }
            else
            {
                longest_now++;
            }
            hash_char[(int)s[j]] = j;
        }
        longest_num = longest_num > longest_now ? longest_num : longest_now;
        return longest_num;
    }
};
// @lc code=end
