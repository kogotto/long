#ifndef LONGINT_H
#define LONGINT_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class TLongInt {
public:
    TLongInt()
    {}

    TLongInt(int src) {
        while (src) {
            array.push_back(src % base);
            src /= base;
        }
    }

    friend TLongInt operator+(const TLongInt & lhs, const TLongInt & rhs) {
        TLongInt result(lhs);
        return result += rhs;
    }

    TLongInt & operator+=(const TLongInt & rhs) {
        const size_t lhsSize = array.size();
        const size_t rhsSize = rhs.array.size();
        array.resize(std::max(lhsSize, rhsSize));

        value_t overflow = 0;
        for (size_t i = 0; i < rhsSize; ++i) {
            array[i] += rhs.array[i] + overflow;
            overflow = array[i] / base;
            array[i] %= base;
        }
        for (size_t i = rhsSize; i < lhsSize; ++i) {
            array[i] += overflow;
            overflow = array[i] / base;
            array[i] %= base;
        }
        if (overflow != 0) {
            array.push_back(overflow);
        }

        return *this;
    }

//    TLongInt & negate() {
//        for
//    }

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

inline std::ostream & operator << (std::ostream & stream, const TLongInt & rhs) {
    return stream << rhs.toStdString();
}

#endif // LONGINT_H
