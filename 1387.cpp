#include<iostream>
#include<cstdio>
using namespace std;
//参考课本哈夫曼树
//估计就是爆int了
template <class elemType>
struct HuffmanNode
{
    elemType data;
    long long weight;
    int parent;
    int left,right;
};

template <class elemType>
int minIndex(HuffmanNode<elemType> Bt[],int k, int m)
{
    long long i,min,minWeight = 1e18;
    for(i  = m - 1; i > k; i-- )
    {
        if((Bt[i].parent == 0) && (Bt[i].weight < minWeight))
        {
            min = i;
            minWeight = Bt[min].weight;

        }
    }
    return min;
}

template<class elemType>
long long BestBinaryTree(elemType val[], elemType wei[], long long n)
{
    HuffmanNode<elemType> *BBTree;
    int first_min,second_min;
    int m = n * 2;
    int i,j;

    BBTree = new HuffmanNode<elemType>[m];
    for(j = 0;j < n; j++)
    {
        i = m - 1 - j;
        BBTree[i].data = val[j];
        BBTree[i].weight = wei[j];
        BBTree[i].parent = 0;
        BBTree[i].left = 0;
        BBTree[i].right = 0;


    }
    i = n-1;

    while (i!=0)
    {
        first_min = minIndex(BBTree, i, m);
        BBTree[first_min].parent = i;
        second_min = minIndex(BBTree, i, m);
        BBTree[second_min].parent = i;

        BBTree[i].weight = BBTree[first_min].weight + BBTree[second_min].weight;
        BBTree[i].parent = 0;
        BBTree[i].left = first_min;BBTree[i].right = second_min;

        i--; 
    }
    long long result = 0;
    for (int i = 1; i < n; i++)
        {result += BBTree[i].weight;}
    delete []BBTree;
    return result;
    // return BBTree;W
}



int main()
{
    
    long long N;
    cin >> N;
    long long *node_weight = new long long[N];
    
    for(int i = 0;i < N; i++)
        cin >> node_weight[i];
    if (N == 1)
    {
        int res = node_weight[0];
        cout << res << endl;
        return 0;
    }    

    cout<< BestBinaryTree(node_weight,node_weight,N);
    delete[] node_weight;
    return 0;

}

