#include<cstdio>
#include<cmath>
using namespace std;
const double epsion =1e-5;
//注意到本题答案在int范围内，所以要考虑的问题少了许多，可以不考虑浮点数精度的问题
//我是傻逼，在写错循环变量之后花了好大力气找到了，现在发现有一个测试点没过，可能就是浮点数精度问题
//百度了一下，似乎是比较两个浮点数差值是否在一定范围内，为了方便还是写个函数吧
//发现还是不对，再让我想一下
//他喵的，终于知道问题出在哪里了，39行改成函数的时候把！去掉了，寄！
//而且此题矩阵并不是很大，考虑余子式，逆序数，高斯消元都可以做到，我们在此考虑高斯消元（这好像简单写一点）
//因为矩阵最大的大小为10x10，我们不妨定义一个大小为12x12的二维数组
double matrix1[12][12];
int n;

void swap(double &a,double &b)    
{
    double temp = a;
    a = b;
    b = temp;
}

bool equal(double a, double b)
{
    if(fabs(a-b) < epsion)
        return 1;
    else
        return 0;
}

double determinant_calculation()
{
    double det = 1;
    for(int i = 1; i<= n; i++ )
    {
        if(equal(matrix1[i][i], 0))
        {
            int j;
            for(j = i + 1;j <= n; j++ )
                if(!equal(matrix1[j][i], 0) )
                    break;
            if(j == n+1)
                return 0;
           
            det *= -1;

            for(int k = 1; k <= n; k++ )
                swap(matrix1[i][k], matrix1[j][k]);
        }
        for(int j = i + 1; j <= n; j++ )
        {
            double ratio = -(matrix1[j][i]/matrix1[i][i]);
            for(int k = i; k <= n; k++)
                matrix1[j][k] += ratio * matrix1[i][k];
        }
    }
    for(int i = 1; i <=n; i++)
        det *= matrix1 [i][i];
    return det;
}

int normalization(double result)
{
    double final_result = fabs(result);
    return (result >= 0 ? 1 : -1) * int(final_result + 0.5);
}
int main()
{   

    scanf("%d", &n);
    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n; j++)
            scanf("%lf", &matrix1[i][j]);
    double ans = determinant_calculation();

        printf("%d\n", normalization(ans));
        return 0;
}