//MonotonousStack.cpp
#include "MonotonousStack.h"
int MonotonousStack::size(){
 //如果选择使⽤s，那么可以直接返回s.size()，其余接⼝类似。
    return s.size();
 //TODO
}
void MonotonousStack::pop(){
    s.pop();
 //TODO
}
int MonotonousStack::top(){
    return s.top();
 //TODO
}
int MonotonousStack::push(int element){
    // stack<int> tmp;
    // int t;
    while(!s.empty()&&s.top()>element){
        // t = s.top();
        s.pop();
        // tmp.push(t); 
    }
    s.push(element);
    // while(!tmp.empty()){
    //     t = tmp.top();
    //     tmp.pop();
    //     s.push(t);
    // }
    return 0;
 //TODO
}
int MonotonousStack::function(const int* arr,int n){
 //TODO
    int* indx = new int[n];
    for(int i = 0; i < n; i++)
        indx[i] = i;
    // cout << " begin" << endl;
    int t;
    for(int i = n - 1 ; i >= 0; i--){
        t = i + 1;
        while(t < n && arr[i] <= arr[t]){
            if(indx[t] == t){//后面没有比arr[t]小的
                t = n;
                break;
            }
            else{
                t = indx[t];
            }
            // t = indx[t];
        }
        if(t >= n)
            indx[i] = i;
        else
            indx[i] = t;
    }
    //debug:
    // for(int i = 0; i < n; i++){
    //     cout << indx[i] << " ";
    // }
    // cout << endl;


    int ans = 0;
    for(int i = 0; i < n; i++){
        if(indx[i] != i)
            ans += arr[i] - arr[indx[i]];
        else
            ans += arr[i];
    }
    return ans;
}
int main(){
//     // MonotonousStack* ms=new MonotonousStack;
//     // ms->push(8);
//     // ms->push(4);
//     // ms->push(6);
//     // ms->push(2);
//     // ms->push(3);

//     // // cout<<ms->size()<<endl;

//     // cout<<ms->top()<<endl;
//     // ms->pop();
//     // cout<<ms->top()<<endl;
//     // ms->pop();
//     // cout<<ms->size()<<endl;
//     // delete ms;

    // MonotonousStack* ms=new MonotonousStack;
    // ms->push(10);
    // ms->push(1);
    // cout<<ms->top()<<endl;
    // ms->push(1);
    // cout<<ms->size()<<endl;
    // ms->push(6);
    // cout<<ms->top()<<endl;
    // ms->pop();
    // cout<<ms->top()<<endl;
    // cout<<ms->size()<<endl;
    // ms->push(-2);
    // cout << ms->top()<<endl;
    // cout<<ms->size()<<endl;
    // delete ms;

    MonotonousStack* ms=new MonotonousStack;
    int arr[]={8,4,6,2,1, 5};
    cout<<ms->function(arr,6)<<endl;
    int a[]={4, 3, 2 ,-1, 1};
    cout<<ms->function(a,5)<<endl;
    delete ms;
   
//     cout << "end" << endl;
//     return 0;
}
