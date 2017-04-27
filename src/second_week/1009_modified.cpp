#include<stdio.h>
#include<algorithm> //include属于头文件部分，跟using namespace XXX分开，使用回车换行。还有预定义之类的也一样，用回车将不同功能的代码区分开，这样自己调的时候也方便。

using namespace std;    //using namespace XXX跟下面的处理部分分开

struct node     //node->Node，定义结构体首字母大写，多个单词是每个单词首字母都大写，类似于OneTwoNodeSample
{
    int J, F;       //合理使用空格！！！一般每个非字母符号都要在右边添加空格，方便看些，赋值比较大小的符号左右都添加空格。
    double jun;     //不能使用拼音！所有变量名如果想表示一些意义，使用对应的英文单词，jun->average,或者缩写avg之类的
}shu[10000];        //shu->num, array, nums等

bool cmp(node a, node b)
{
    return a.jun>b.jun;
}
//大括号的使用要统一，是另起一行还是在同一行


int main()
{
    int M, N;
    while(scanf("%d %d", &M, &N) != EOF)        //空格（space）
    {
        if(M==-1 && N==-1)       //也可以写成：if(M == -1 && N == -1)不过这样的空格太多了，我一般分成两部分，左右的两个表达式空格省略
            break;              //异常部分处理，可以加一个换行跟下面的正常处理区分开

        for(int i = ; i < N; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);  //这一步是处理输入，可以再scanf后面加一个回车换行，跟下面的具体数值处理部分区分开来

            double d = (double)a/b;
            shu[i].J = a;
            shu[i].F = b;
            shu[i].jun = d;
        }

        sort(shu, shu+N, cmp);      //sort是一个单独的步骤，在上下可以用回车换行区分开

        int sum = 0;
        double ans = 0.0;
        for(int i = 0; i < N; i++)
        {
            if(sum+shu[i].F <= M)
            {
                ans += shu[i].J;
                sum += shu[i].F;
            }
            else
            {
                ans += (double(M-sum)/shu[i].F)*shu[i].J;
                break;
            }
        }

        printf("%.3lf\n", ans);     //printf是单独的处理输出，可以用回车换行跟前面的步骤区分开。
    }

    return 0;
}
//合理使用回车和空格，将代码分成各个不同的逻辑组成部分，便于阅读和调试。

