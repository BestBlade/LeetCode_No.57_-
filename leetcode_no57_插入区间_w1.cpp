/* ------------------------------------------------------------------|
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 

示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 

注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：32 ms, 在所有 C++ 提交中击败了50.05%的用户
*	内存消耗：17.8 MB, 在所有 C++ 提交中击败了5.01%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int left = newInterval[0];
    int right = newInterval[1];
    bool placed = false;

    vector<vector<int> > res;
    for (auto interval : intervals) {

        if (interval[0] > right) {
            if (!placed) {
                res.push_back({ left,right });
                placed = true;
            }
            res.emplace_back(interval);
        }

        else if (interval[1] < left) {
            res.emplace_back(interval);
        }

        else {
            left = min(left, interval[0]);
            right = max(right, interval[1]);
        }
    }

    if (!placed) {
        res.push_back({ left,right });
    }

    return res;
}