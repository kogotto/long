#include <iostream>

using namespace std;

#include <longint.h>

int main()
{
    TLongInt l(123456);
    cout << "l = " << l.toStdString() << endl;
    return 0;
}

