#include<iostream>
using namespace std;
void f(){
    cout<<1<<endl;
    f();
}
int main()
{
    f();
    return 0;
}