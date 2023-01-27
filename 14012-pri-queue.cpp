#include<iostream>
using namespace std;
//此题可以用优先队列解决，就先手搓一个优先队列

class PQ{
    private:
        int sizepq;
        int capacity;
        int *pq;
    public:
        PQ(int n){//构造函数
            pq = new int[n+1];
            sizepq = 0;
            capacity = n;

        }
        ~PQ(){
            delete []pq;

        }
        void insert((int val)){
            if (sizepq >= capacity)
            {
                int* temp = new int[capacity << 1];
                for (int i = 1; i <= capacity; i++)
                {
                    temp[i] = pq[i];
                }
                delete []pq;
                pq = temp;
                capacity<<=1; 
            }
            sizepq++;
            pq[sizepq] = val;
            swim(sizepq);
        }
        int pop(){
            int temp = pq[1];
            swap(pq[1],pq[sizepq--]);
            sink(1);
            return temp;
        }
        int size()
        {
            return sizepq;
        }
        bool empty()
        {
            return sizepq == 0;
        }
    private:
        bool cmp(int a, int b) 
        {return a > b;}
        void swim(int n)
        {
            while (n > 1 && cmp(pq[n],pq[n>>1]))
            {
                swap(pq[n], pq[n>>1]);
                n>>=1;
            }
        }
        void sink(int n){
            while(2 * n <= sizepq)
            {
                int k = 2 * n;
                if (k < sizepq && cmp (pq[k+1],pq[k])) k++;
                if (cmp(pq[k],pq[n]))
                {
                    swap(pq[n],pq[k]);
                    n = k;
                }
                else break;
            }
        }
}


