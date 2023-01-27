#include<iostream>
#include<cstring>
using namespace std;

char pre_tra[30];
char mid_tra[30];
char tree[1010];

void restore_tree(char *pre_tra, char *mid_tra, int length, int root_node)//通过递归一步步找根节点然后还原
{
    if (length <= 0)
        return;
    char tree_root = pre_tra[0];//通过前序遍历获得根节点
    tree[root_node] = tree_root;
    int i = 0;
    while(mid_tra[i] != tree_root)
        i++;
    restore_tree(pre_tra + 1, mid_tra, i, root_node * 2);
    restore_tree(pre_tra + i + 1, mid_tra + i + 1, length - i - 1, root_node * 2 + 1);
    //将根节点的左子树和右子树分开


}

int main()
{
    cin >> pre_tra >> mid_tra;
    for(int i = 1; i<= 1010; i++)
        {
            tree[i] = ' ';

        }
    restore_tree(pre_tra, mid_tra, strlen(pre_tra), 1);
    int n = 1000;
    while (tree[n] == ' ')
        n--;//确定有几个节点
    for (int j = 1; j <= n; j++)
    {
        if (tree[j] == ' ' )
            cout << "NULL ";
        else
            cout << tree[j] << ' ';

    }
    cout << endl;
    return 0;
}