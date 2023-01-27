#include<iostream>
#include<cstdio>
using namespace std;

bool coprime(int p, int q)
{
    int temp;    
    if (p == 1 || q == 1)
    {
        return true;
    }

    while (true)
    {
        temp = p % q;
        if (temp == 0) break;
        p = q;
        q = temp;
    }
    if (q > 1) return false;
    else return true;
}

class frac
{
    public:
        int mol;
        int den;
        frac(int i = 0, int j = 1)
        {
            mol = i;
            den = j;
        }
        double value() { return mol * 1.0000 / den;}
};



template<class elemType>
class PriorityQueue
{
    private:
        int Capacity = 100010;    //队列容量
        int size;                 //队列大小
        elemType* data;             //队列变量

    public:
        PriorityQueue();
        ~PriorityQueue();

        int Size();
        bool isFull();   //判满
        bool isEmpty(); //判空
        void Push(elemType key); //入队
        void Pop();//出队
        void Clear(); //清空
        elemType Top();//队首
};

template<class elemType>
PriorityQueue<elemType>::PriorityQueue()
{
    data = (elemType*) malloc((Capacity + 1)*sizeof(elemType));
    if (!data)
    {
        perror("Allocate dynamic memory");
        return;
    }

    size = 0;
}

template<class elemType>
PriorityQueue<elemType>::~PriorityQueue()
{
    while (!isEmpty())
        Pop();
}

template<class elemType>//判断队列是否为空
bool PriorityQueue<elemType>::isEmpty()
{
    if (size > 0)
        return false;
    return true;
}

template<class elemType>//清空队列
void PriorityQueue<elemType>::Clear()
{
    while (!isEmpty())
        Pop();
}

template<class elemType>//判断队列是否满
bool PriorityQueue<elemType>::isFull()
{
    if (size == Capacity)
        return true;
    return false;
}

template<class elemType>//返回队列大小
int PriorityQueue<elemType>::Size()
{
    return size;
}

template<class elemType>
//入队
void PriorityQueue<elemType>::Push(elemType key)
{
    // 空则直接入队  不能省略
    if (isEmpty())
    {
        data[++size] = key;
        return;
    }

    int i;

    if (isFull())
    {
        perror("Priority queue is full\n");
        return;
    }

    for (i = ++size; data[i / 2].value() < key.value() && i!=1; i /= 2)
        data[i] = data[i / 2];
    data[i] = key;

    //if (key != data[i / 2])          //如果不能插入重复值 用下面的
    //  data[i] = key;
    //else
    //{
    //  size--;
    //  perror("Same value");
    //}

}

template<class elemType>
//出队
void PriorityQueue<elemType>::Pop()
{
    int i, child;
    elemType min, last;

    if (isEmpty())
    {
        perror("Empty queue\n");
        return;
    }

    min = data[1];
    last = data[size--];

    for (i = 1; i * 2 <= size; i = child)
    {
        child = i * 2;
        if (child != size && data[child + 1].value() > data[child].value())
            child++;

        if (last.value() < data[child].value())
            data[i] = data[child];
        else
            break;
    }
    data[i] = last;
}

template<class elemType>
//队首
elemType PriorityQueue<elemType>::Top()
{
    if (isEmpty())
    {
        perror("Priority queue is full\n");
        return data[0];
    }
    return data[1];
}

int main()
{
    int N,K,count = 0;
    PriorityQueue<frac> que;
    cin >> N >> K;
    for(int i = N; i >= 2; i--)
    {
        frac item(i-1,i);
        que.Push(item);
        count += 1;
        if (count == K){
            cout<<i-1<<'/'<<i;
            return 0;
        }
    }
    for(int i=1;i<K;i++){
        frac item=que.Top();
        int den=item.den,mol=item.mol;
        // cout<<mol<<" "<<den<<endl;
        que.Pop();
        for(int j=mol-1;j>=1;j--){
            if (coprime(den,j)){
                que.Push(frac(j,den));
                break;
            }
        }
    }
    frac result=que.Top();
    cout<<result.mol<<'/'<<result.den;
    return 0;
}