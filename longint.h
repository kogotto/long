#ifndef LONGINT_H
#define LONGINT_H

#include <vector>
#include <string>
#include <algorithm>

class TLongInt {
public:
    TLongInt(int src) {
        while (src) {
            array.push_back(src % base);
            src /= base;
        }
    }

    std::string toStdString() const {
        std::string result;
        std::for_each(array.rbegin(),
                      array.rend(),
                      Tostringator(result));
        return result;
    }

private:
    typedef int value_t;
    typedef std::vector<value_t> array_t;
    struct Tostringator {
        Tostringator(std::string & str):
            str(str)
        {}

        void operator() (value_t arg) {
            str.append(std::to_string(arg));
        }

    private:
        std::string & str;
    };

    static const value_t base = 100;
    array_t array;
};

#endif // LONGINT_H
