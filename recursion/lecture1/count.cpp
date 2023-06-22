#include<iostream>
using namespace std;
int c=0;
void f(){
    if (c==3)
    {
        return;
    }
    cout<<c<<endl;
    c++;
    f();
}
int main()
{
    f();
    return 0;
}