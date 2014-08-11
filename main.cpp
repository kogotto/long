#include <iostream>

using namespace std;

#include <longint.h>

void foo(const TLongInt & );

int main()
{
    TLongInt l(123456);
    TLongInt r(999999);
    cout << "l = " << l.toStdString() << endl;
    cout << "r = " << r.toStdString() << endl;
    cout << "l + r = " << (l + r).toStdString() << endl;
    cout << "l + 100 = " << (l + 100).toStdString() << endl;
    return 0;
}

