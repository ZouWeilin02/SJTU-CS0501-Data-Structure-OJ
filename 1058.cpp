#include <iostream>
#include <cstdio>
using namespace std;
//Reference：程序设计思想与方法（C++） PPT-数据封装——结构体 上海交通大学 
//Reference: CSDN: https://blog.csdn.net/henry594xiaoli/article/details/124083263
namespace LIST
{

    struct NODE {
        int data;
        NODE *next;
        // TODO
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        // TODO 让头节点指向头节点就可以了，但是似乎可以用单独的变量记录链表长度
        head = new NODE;
        head -> next = head;
        //len = 0;(这个不知道行不行)
    }
    NODE *move(int i) {
        // TODO
        NODE *p;
        p = head ->next;
        while (i-- > 0 && p != head)
            p = p -> next;
        return p;
    }
    void insert(int i, int x) {
        // TODO 1.申请空间 2.输入数据放入申请到的空间 3. 链入p后
        if (i != 0)
        {
        NODE *tmp;
        tmp = new NODE;
        tmp -> data = x;
        NODE *p = move(i - 1);
        tmp -> next = p -> next;
        p -> next = tmp;
        ++len ;    
        }
        else
        {
        NODE *tmp;
        tmp = new NODE;
        tmp -> data = x;
        NODE *p = head;
        tmp -> next = p -> next;
        p -> next = tmp;
        ++len ;        
        }
        
    }
    void remove(int i) {
        // TODO
        if (i == 0)
        {
            NODE *p = head;
            NODE *tmp = p -> next;
            p -> next = tmp -> next;
            delete tmp;
            --len;
        }
        else
        {
            NODE *p = move(i - 1);
            NODE *tmp = p -> next;
            p -> next = tmp -> next;
            delete tmp;
            --len;
        }
    }
    void remove_insert(int i) {
        //TODO 把前面两步结合起来就行,先删除,然后找到最后一个位置再插入
        int x;
        if (i == 0)
        {
            NODE *p = head;
            NODE *tmp = p -> next;
            x = tmp -> data;
            p -> next = tmp -> next;
            delete tmp;
            NODE *q = head;
            while (q -> next != head)
            {
                q = q ->next;
            }
            NODE *temp;
            temp = new NODE;
            temp -> data = x;
            temp -> next = q -> next;
            q -> next = temp; 

        }
        else
        {
            NODE *p = move(i - 1);
            NODE *tmp = p -> next;
            x = tmp -> data;
            p -> next = tmp -> next;
            delete tmp;
            NODE *q = head;
            while (q -> next != head)
            {
                q = q ->next;
            }
            NODE *temp;
            temp = new NODE;
            temp -> data = x;
            temp -> next = q -> next;
            q -> next = temp; 

        }

    
    }
    void get_length() {
        // TODO
        cout << len << endl;
    }
    void query(int i) {
        // TODO
        if (i < 0 || i >= len )
            cout << -1 << endl;
        else
        {
            cout<< move(i) -> data << endl;
        }

    }
    void get_max() {
        // TODO
        NODE *p = head -> next;
        int max_num = -2e9;
        if (len != 0)
        {
        for (int i = 0; i< len; i++)
        {
            if(p ->data > max_num)
                max_num = p -> data;
            p = p -> next;
        }
        cout << max_num << endl;
        }
        else cout << -1 << endl;     

       
    }
    void clear() {
        // TODO
        NODE *p = head, *q;
        for (int i = 0; i < len; i++)
        {
            q = p -> next;
            delete p;
            p = q;
        }
        delete p;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}