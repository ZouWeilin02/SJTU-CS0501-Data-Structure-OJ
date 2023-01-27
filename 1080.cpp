#include<iostream>
#include<cstdio>
#include<cctype>

using namespace std;

//分析思路，对于后缀表达式问题，从左到右扫描整个序列，当遇到数字时，依次入栈
//当遇到运算符号时，弹出栈顶两个数字，然后根据运算符进行运算（top元素前一个 option top元素），然后结果入栈，重复操作到字符串结束
//入栈的时候，利用isdigit函数来判断是否是阿拉伯数字,这个题目相对来说比较简单\
//cao，超时了
//cao, 或许是%s的地方手贱多打了空格
const int N = 10010;

char suffix_expression[N];
int stack[N];
int top = 0;

int main()
{
    //cin >> suffix_expression;
    scanf("%s", suffix_expression);
    for (int i = 0; suffix_expression[i] != '@'; i++)
    {
        if (isdigit(suffix_expression[i]))
        {
            int number = 0;
            while (suffix_expression[i] != '.')
                number = number * 10 + suffix_expression[i] - '0',i++;


            stack[++top] = number;
        }
        
        else if (suffix_expression[i] == '+')
            top--, stack[top] = stack[top] + stack[top + 1];
        else if (suffix_expression[i] == '-')
            top--, stack[top] = stack[top] - stack[top + 1];
        else if (suffix_expression[i] == '*')
            top--, stack[top] = stack[top] * stack[top + 1];
        else if (suffix_expression[i] == '/')
            top--, stack[top] = stack[top] / stack[top + 1];
    }   
    //cout << stack[top] << endl;
    printf("%d\n", stack[top]);
    return 0;

}