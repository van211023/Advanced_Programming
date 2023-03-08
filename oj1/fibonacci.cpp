
int fibonacci(int n){
    int a = 0, b = 1;
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else{
        while(n > 1){
            b = a + b;
            a = b - a;
            n--;
        }
    }
    return b;
}