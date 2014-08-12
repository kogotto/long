#include <iostream>

using namespace std;

#include <longint.h>

void foo(const TLongInt & );

int main()
{
    TLongInt l(123456);
    TLongInt r(999999);
    cout << "l = " << l << endl;
    cout << "r = " << r << endl;
    cout << "l + r = " << l + r << endl;
    cout << "l + 100 = " << l + 100 << endl;
    return 0;
}

