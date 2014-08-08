#include <iostream>

using namespace std;

#include <longint.h>

int main()
{
    TLongInt l(123456);
    TLongInt r(999999);
    cout << "l = " << l.toStdString() << endl;
    cout << "r = " << r.toStdString() << endl;
    cout << "l + r = " << (l + r).toStdString() << endl;
    return 0;
}

