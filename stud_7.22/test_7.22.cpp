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
    // _preorderTraversal������������������
    // 1. root����ǰ��Ҫ���������ڵ㡣
    // 2. v��һ�����ò��������ڴ洢���������vector��
    void _preorderTraversal(TreeNode* root, vector<int>& v) {
        // �����ǰ�ڵ�Ϊ�գ�ֱ�ӷ��أ������κδ���
        if (root == NULL) {
            return;
        }

        // ���Ƚ���ǰ�ڵ��ֵ��ӵ����vector�С�
        v.push_back(root->val);

        // �ݹ������ǰ�ڵ����������
        _preorderTraversal(root->left, v);

        // �ݹ������ǰ�ڵ����������
        _preorderTraversal(root->right, v);
    }

    // preorderTraversal��������һ��������
    // 1. root���������ĸ��ڵ㡣
    // ��������ֵ��һ������vector�������˶�����ǰ������Ľ����
    vector<int> preorderTraversal(TreeNode* root) {
        // ����һ���յ�vector���洢���������
        vector<int> ret;

        // ���ø�������_preorderTraversal�����еݹ������
        _preorderTraversal(root, ret);

        // ���ش洢��ǰ����������vector��
        return ret;
    }
};

class Solution1{
public:
    // �����������ڷ��ض�������ǰ��������
    vector<int> preorderTraversal(TreeNode * root) {
        // �洢�������������
        vector<int> ret;
        // ģ��ݹ���̵�ջ
        stack<TreeNode*> st;
        // ָ��ǰ�ڵ��ָ��
        TreeNode* cur = root;

        // ���ѭ����ֱ����ǰ�ڵ�Ϊ����ջΪ��
        while (cur || !st.empty()) {
            // ����������
            while (cur) {
                // ����ǰ�ڵ��ֵ��ӵ����������
                ret.push_back(cur->val);
                // ����ǰ�ڵ�ѹ��ջ��
                st.push(cur);
                // �ƶ������ӽڵ�
                cur = cur->left;
            }

            // ��ȡջ���ڵ�
            TreeNode* top = st.top();
            // ��ջ���Ƴ�ջ���ڵ�
            st.pop();
            // �ƶ������ӽڵ㣬��������������
            cur = top->right;
        }

        // ����ǰ������Ľ��
        return ret;
    }
};
class Solution2 {
public:
    // �����������ڷ��ض�����������������
    vector<int> inorderTraversal(TreeNode* root) {
        // �洢�������������
        vector<int> ret;
        // ģ��ݹ���̵�ջ
        stack<TreeNode*> st;
        // ָ��ǰ�ڵ��ָ��
        TreeNode* cur = root;

        // ���ѭ����ֱ����ǰ�ڵ�Ϊ����ջΪ��
        while (cur || !st.empty()) {
            // ����������
            while (cur) {
                // ����ǰ�ڵ�ѹ��ջ��
                st.push(cur);
                // �ƶ������ӽڵ�
                cur = cur->left;
            }

            // ��ȡջ���ڵ�
            TreeNode* top = st.top();
            // ��ջ���Ƴ�ջ���ڵ�
            st.pop();
            // ����ǰ�ڵ��ֵ��ӵ����������
            ret.push_back(top->val);
            // �ƶ������ӽڵ㣬��������������
            cur = top->right;
        }

        // ������������Ľ��
        return ret;
    }
};

class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret; // �洢�������
        stack<TreeNode*> st; // ģ��ݹ��ջ
        TreeNode* cur = root; // ��ǰ�ڵ�
        TreeNode* last = nullptr; // ��һ�η��ʵĽڵ�

        while (cur || !st.empty()) {
            // �����������Ҷ�ڵ�
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            // ��ȡջ���ڵ㣬��������
            TreeNode* top = st.top();

            // ������ӽڵ������δ�����ʹ������ƶ������ӽڵ�
            if (top->right && top->right != last) {
                cur = top->right;
            }
            else {
                // ���ʵ�ǰ�ڵ㣬������ջ���ڵ�
                ret.push_back(top->val);
                st.pop();
                // ���� last Ϊ��ǰ���ʵĽڵ�
                last = top;
            }
        }

        return ret; // ���غ�������Ľ��
    }
};
//���ʶ�����ջģ��
void test_set1()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(7);
    s.insert(2);
    s.insert(1);

    // ����+ȥ��
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

    // ��� set �Ƿ�Ϊ��
    if (mySet.empty()) {
        std::cout << "Set is empty." << std::endl;
    }
    else {
        std::cout << "Set is not empty." << std::endl;
    }

    // ����Ԫ��
    mySet.insert(2);
    mySet.insert(3);

    // ��� set
    mySet.clear();

    // �ٴμ�� set �Ƿ�Ϊ��
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

    // �����ֵ��
    m.insert(make_pair(2, "b"));
    m.insert(make_pair(1, "a"));
    m.insert(make_pair(3, "c"));
    m[4] = "d";  // ��һ�ֲ��뷽ʽ

    // ͨ������������
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " => " << it->second << endl;
    }

    // ͨ����Χʽ for ѭ������
    for (const auto& kvp : m) {
        cout << kvp.first << " => " << kvp.second << endl;
    }

    // �޸�Ԫ��
    m[2] = "new_b";

    // ����Ԫ��
    auto pos = m.find(3);
    if (pos != m.end()) {
        cout << "Found: " << pos->first << " => " << pos->second << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // ɾ��Ԫ��
    m.erase(1);  // ͨ����ɾ��
    m.erase(m.find(4));  // ͨ��������ɾ��

    // ��ӡʣ��Ԫ��
    for (const auto& kvp : m) {
        cout << kvp.first << " => " << kvp.second << endl;
    }
}

// ���� map �Ĳ��Һͼ�������
void test_map3() {
    map<int, string> m;
    m.insert(make_pair(2, "b"));
    m.insert(make_pair(1, "a"));
    m.insert(make_pair(3, "c"));

    // ����Ԫ��
    auto pos = m.find(2);
    if (pos != m.end()) {
        cout << "Found: " << pos->first << " => " << pos->second << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // ���������� map��count ����0��1����Ϊÿ������Ψһ�ģ�
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