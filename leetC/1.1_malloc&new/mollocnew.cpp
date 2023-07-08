#include <iostream>
#include <malloc.h>

using namespace std;

int main(int a, char* ins[])
{   
    cout << a <<endl;
    int i;
    cout<<"success try!"<<endl;
    for(i=0;i<a;i++)
    {
        cout << i << " -> "<< *ins[i] <<endl;
    }
#if 1
    int bb = (int) *ins[1] - (int)'0';
#endif

#if 0
    int bb = *ins[1];
#endif
    cout<< bb <<endl;
    if(bb==1)
        cout<<"success try!"<<endl;
    else
        cout<<"fail try!"<<endl;
    // char* p;
    // p=(char *)malloc(100);
    // if(p)
    // {
    //     cout<<"memory allocated at: %d"<< endl << &p <<endl;
    // }
    // else
    // {
    //     cout<<"not enough memory"<< endl;
    // }
    // free(p);
    // return 0;
}