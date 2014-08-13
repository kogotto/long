#include <iostream>

using namespace std;

#include <longint.h>

void foo(const TLongInt & );

#define print(s) { cout << #s << " = " << (s) << endl; }

int main()
{
    TLongInt l(123456);
    TLongInt r(999999);
    TLongInt n(-999999);
    print(l);
    print(r);
    print(l + r);
    print(l + 100);
    print(n);
    print(n + r);
    print(n + l);
    print(l - r);
    print(l - n);
    print(l - 6);
    print(-l);
    return 0;
}

