#include<iostream>
using namespace std;

class illegalSize{};
class outOfBound{};

template <class elemType>
class seqQueue
{
    private:
        elemType *array;
        int maxSize;
        int Front,Rear;
        void doubleSpace();
    public:
        seqQueue(int size =10);
        bool isEmpty();
        bool isFull();
        elemType front();
        void enQueue(const elemType &x);
        void deQueue();
        int lenQueue();
        int frontQueue();
        int rearQueue();
        ~seqQueue();
};

template <class elemType>
seqQueue<elemType>::seqQueue(int size) //初始化队列元素的储存空间
{
    array = new elemType[size];  //申请实际的队列储存空间
    if (!array) throw illegalSize();
    maxSize = size;
    Front = Rear = 0;
}

template <class elemType>
bool seqQueue<elemType>::isEmpty() //判断队空
{
    return Front == Rear;
}

template <class elemType>
bool seqQueue<elemType>::isFull()
{
    return (Rear + 1) % maxSize == Front;
}

template <class elemType>
elemType seqQueue<elemType>::front() //读取队首元素的值，队首元素不变
{
    if (isEmpty()) throw outOfBound();
    return array[Front];
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if(isFull()) doubleSpace();
    array[Rear] = x;
    Rear = (Rear + 1) % maxSize;
}

template <class elemType>
void seqQueue<elemType>::deQueue()
{
    if (isEmpty()) throw outOfBound();
    Front = (Front + 1) % maxSize;

}

template <class elemType>
seqQueue<elemType>::~seqQueue() //释放占据的动态数组
{
    delete []array;
}

template <class elemType>
int seqQueue<elemType>::lenQueue()
{
    return (Rear - Front + maxSize) % maxSize;
}

template <class elemType>
int seqQueue<elemType>::frontQueue()
{
    return Front;
}

template <class elemType>
int seqQueue<elemType>::rearQueue()
{
    return Rear;
}

template <class elemType>
void seqQueue<elemType>::doubleSpace() //拓展队列元素的储存空间
{
    elemType *newArray;
    int i,j;
    newArray = new elemType[2 * maxSize];
    if (!newArray) throw illegalSize();

    for (int i = 0, j = Front; j != Rear; i++, j = (j + 1) % maxSize)
    {
        newArray[i] = array[j];

    }
    delete []array;
    Front = 0;
    Rear = j;
    maxSize = 2 * maxSize;
    
}


int main()
{

    int s,n,t,x;
    cin >> s >> n;
    seqQueue<int> que(s);


    while (n--)
    {
        cin >> t;
        if (t == 0)
        {
            cin >> x;
            que.enQueue(x);
            cout << que.rearQueue() << " " << que.lenQueue() << endl;
        }
        else if (t == 1)
        {
            if (que.isEmpty())
                que.deQueue();
            cout << que.frontQueue() << " " << que.lenQueue() << endl;
        }
       
    }
    return 0;
}