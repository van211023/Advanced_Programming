//MonotonousStack.h
#include <iostream>
#include <stack>
using namespace std;
class MonotonousStack
{
private:
 stack<int> s;
public:
 int size(); //返回栈内元素数量
void pop(); //弹出栈顶元素
int top(); //返回栈顶元素，不出栈
//返回0push成功，-1失败
int push(int element); //弹出栈内所有⼤于element的元素后，element⼊栈，返回值可⾃⾏定义使⽤，样例不做检查
int function(const int* arr,int n); //⻅Part-2
};