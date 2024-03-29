#include <iostream>

template <typename ElementType>
class Queue
{
public:
    virtual ~Queue() {}
    virtual bool empty() const = 0;
    virtual void push(const ElementType &element) = 0;
    virtual ElementType pop() = 0;
    virtual ElementType front() const = 0;
    virtual void clear() = 0;
};

template <typename ElementType>
class SequentialQueue : public Queue<ElementType>
{
private:
    ElementType *elementData;
    int headPosition, tailPosition, totalCapacity;
    void expand();

public:
    SequentialQueue(int size = 10);
    ~SequentialQueue();
    bool empty() const;
    void push(const ElementType &element);
    ElementType pop();
    ElementType front() const;
    void clear();
    int get_head_position();
    int get_tail_position();
    int get_queue_length();
};

template <typename ElementType>
void SequentialQueue<ElementType>::expand()
{
    ElementType *temp = elementData;
    elementData = new ElementType[2 * totalCapacity];
    for (int i = 1; i < totalCapacity; i++)
        elementData[i] = temp[(headPosition + i) % totalCapacity];
    headPosition = 0;
    tailPosition = totalCapacity - 1;
    totalCapacity *= 2;
    delete[] temp;
}

template <typename ElementType>
SequentialQueue<ElementType>::SequentialQueue(int size)
{
    elementData = new ElementType[size];
    totalCapacity = size;
    headPosition = tailPosition = 0;
}

template <typename ElementType>
SequentialQueue<ElementType>::~SequentialQueue()
{
    delete[] elementData;
}

template <typename ElementType>
bool SequentialQueue<ElementType>::empty() const
{
    return headPosition == tailPosition;
}

template <typename ElementType>
void SequentialQueue<ElementType>::push(const ElementType &element)
{
    if ((tailPosition + 1) % totalCapacity == headPosition)
        expand();
    tailPosition = (tailPosition + 1) % totalCapacity;
    elementData[tailPosition] = element;
}

template <typename ElementType>
ElementType SequentialQueue<ElementType>::pop()
{
    if (headPosition == tailPosition)
        throw "Queue is already empty!";
    headPosition = (headPosition + 1) % totalCapacity;
    return elementData[headPosition];
}

template <typename ElementType>
ElementType SequentialQueue<ElementType>::front() const
{
    if (headPosition == tailPosition)
        throw "Queue is already empty!";
    return elementData[(headPosition + 1) % totalCapacity];
}

template <typename ElementType>
void SequentialQueue<ElementType>::clear()
{
    headPosition = tailPosition = 0;
}

template <typename ElementType>
int SequentialQueue<ElementType>::get_head_position()
{
    return headPosition;
}

template <typename ElementType>
int SequentialQueue<ElementType>::get_tail_position()
{
    return tailPosition;
}

template <typename ElementType>
int SequentialQueue<ElementType>::get_queue_length()
{
    return (tailPosition - headPosition + totalCapacity) % totalCapacity;
}

template <typename T>
void read(T &x)
{
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

int main()
{
    int s, n, t, x;
    read(s), read(n);
    SequentialQueue<int> Q(s);
    while (n--)
    {
        read(t);
        if (t == 0)
        {
            read(x);
            Q.push(x);
            std::cout << Q.get_tail_position() << " " << Q.get_queue_length() << std::endl;
        }
        else if (t == 1)
        {
            if (!Q.empty())
                Q.pop();
            std::cout << Q.get_head_position() << " " << Q.get_queue_length() << std::endl;
        }
    }
    return 0;
}