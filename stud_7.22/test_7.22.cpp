#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};
class Solution0{
public:
    // _preorderTraversal函数接收两个参数：
    // 1. root：当前需要遍历的树节点。
    // 2. v：一个引用参数，用于存储遍历结果的vector。
    void _preorderTraversal(TreeNode* root, vector<int>& v) {
        // 如果当前节点为空，直接返回，不做任何处理。
        if (root == NULL) {
            return;
        }

        // 首先将当前节点的值添加到结果vector中。
        v.push_back(root->val);

        // 递归遍历当前节点的左子树。
        _preorderTraversal(root->left, v);

        // 递归遍历当前节点的右子树。
        _preorderTraversal(root->right, v);
    }

    // preorderTraversal函数接收一个参数：
    // 1. root：二叉树的根节点。
    // 函数返回值是一个整数vector，包含了二叉树前序遍历的结果。
    vector<int> preorderTraversal(TreeNode* root) {
        // 创建一个空的vector来存储遍历结果。
        vector<int> ret;

        // 调用辅助函数_preorderTraversal来进行递归遍历。
        _preorderTraversal(root, ret);

        // 返回存储了前序遍历结果的vector。
        return ret;
    }
};

class Solution1{
public:
    // 主函数，用于返回二叉树的前序遍历结果
    vector<int> preorderTraversal(TreeNode * root) {
        // 存储遍历结果的向量
        vector<int> ret;
        // 模拟递归过程的栈
        stack<TreeNode*> st;
        // 指向当前节点的指针
        TreeNode* cur = root;

        // 外层循环，直到当前节点为空且栈为空
        while (cur || !st.empty()) {
            // 遍历左子树
            while (cur) {
                // 将当前节点的值添加到结果向量中
                ret.push_back(cur->val);
                // 将当前节点压入栈中
                st.push(cur);
                // 移动到左子节点
                cur = cur->left;
            }

            // 获取栈顶节点
            TreeNode* top = st.top();
            // 从栈中移除栈顶节点
            st.pop();
            // 移动到右子节点，继续遍历右子树
            cur = top->right;
        }

        // 返回前序遍历的结果
        return ret;
    }
};
class Solution2 {
public:
    // 主函数，用于返回二叉树的中序遍历结果
    vector<int> inorderTraversal(TreeNode* root) {
        // 存储遍历结果的向量
        vector<int> ret;
        // 模拟递归过程的栈
        stack<TreeNode*> st;
        // 指向当前节点的指针
        TreeNode* cur = root;

        // 外层循环，直到当前节点为空且栈为空
        while (cur || !st.empty()) {
            // 遍历左子树
            while (cur) {
                // 将当前节点压入栈中
                st.push(cur);
                // 移动到左子节点
                cur = cur->left;
            }

            // 获取栈顶节点
            TreeNode* top = st.top();
            // 从栈中移除栈顶节点
            st.pop();
            // 将当前节点的值添加到结果向量中
            ret.push_back(top->val);
            // 移动到右子节点，继续遍历右子树
            cur = top->right;
        }

        // 返回中序遍历的结果
        return ret;
    }
};

class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret; // 存储遍历结果
        stack<TreeNode*> st; // 模拟递归的栈
        TreeNode* cur = root; // 当前节点
        TreeNode* last = nullptr; // 上一次访问的节点

        while (cur || !st.empty()) {
            // 遍历到最左侧叶节点
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            // 获取栈顶节点，但不弹出
            TreeNode* top = st.top();

            // 如果右子节点存在且未被访问过，则移动到右子节点
            if (top->right && top->right != last) {
                cur = top->right;
            }
            else {
                // 访问当前节点，并弹出栈顶节点
                ret.push_back(top->val);
                st.pop();
                // 更新 last 为当前访问的节点
                last = top;
            }
        }

        return ret; // 返回后序遍历的结果
    }
};
//本质都是用栈模拟
void test_set1()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(7);
    s.insert(2);
    s.insert(1);

    // 排序+去重
    //set<int>::iterator it = s.begin();
    auto it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    //	auto pos = s.find(3);                    // O(logN)
    auto pos = find(s.begin(), s.end(), 3);  //  O(N)
    if (pos != s.end())
    {
        s.erase(pos);
    }
    cout << s.erase(1) << endl;
    cout << s.erase(3) << endl;
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

}
void testSetOtherOperations() {
    std::set<int> mySet;

    // 检查 set 是否为空
    if (mySet.empty()) {
        std::cout << "Set is empty." << std::endl;
    }
    else {
        std::cout << "Set is not empty." << std::endl;
    }

    // 插入元素
    mySet.insert(2);
    mySet.insert(3);

    // 清空 set
    mySet.clear();

    // 再次检查 set 是否为空
    if (mySet.empty()) {
        std::cout << "Set is empty after clear." << std::endl;
    }
    else {
        std::cout << "Set is not empty after clear." << std::endl;
    }
}
void test_map1()
{
    map<int, string> m;
    m.insert(make_pair(1, "a"));
    m.insert(make_pair(20, "fu"));
    m.insert(make_pair(17, "de bruyne"));
    m.insert(make_pair(7, "c"));
    m.insert(make_pair(9, "ha"));
    m.insert(make_pair(10, "m"));
    map<int, string>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first <<":"<< it->second << " ";
        ++it;
    }
    cout << endl;
}

void test_map2() {
    map<int, string> m;

    // 插入键值对
    m.insert(make_pair(2, "b"));
    m.insert(make_pair(1, "a"));
    m.insert(make_pair(3, "c"));
    m[4] = "d";  // 另一种插入方式

    // 通过迭代器访问
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " => " << it->second << endl;
    }

    // 通过范围式 for 循环访问
    for (const auto& kvp : m) {
        cout << kvp.first << " => " << kvp.second << endl;
    }

    // 修改元素
    m[2] = "new_b";

    // 查找元素
    auto pos = m.find(3);
    if (pos != m.end()) {
        cout << "Found: " << pos->first << " => " << pos->second << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // 删除元素
    m.erase(1);  // 通过键删除
    m.erase(m.find(4));  // 通过迭代器删除

    // 打印剩余元素
    for (const auto& kvp : m) {
        cout << kvp.first << " => " << kvp.second << endl;
    }
}

// 测试 map 的查找和计数功能
void test_map3() {
    map<int, string> m;
    m.insert(make_pair(2, "b"));
    m.insert(make_pair(1, "a"));
    m.insert(make_pair(3, "c"));

    // 查找元素
    auto pos = m.find(2);
    if (pos != m.end()) {
        cout << "Found: " << pos->first << " => " << pos->second << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // 计数（对于 map，count 总是0或1，因为每个键是唯一的）
    cout << "Count for 2: " << m.count(2) << endl;
    cout << "Count for 5: " << m.count(5) << endl;
}

int main()
{
    test_set1();
    testSetOtherOperations();
    test_map1();
    test_map2();
    test_map3();

	return 0;
}