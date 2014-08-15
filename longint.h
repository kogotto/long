#ifndef LONGINT_H
#define LONGINT_H

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

template<class T>
class TLong {
public:
    typedef T value_t;

    TLong(int src = 0) {
        if (src == 0) {
            array.push_back(0);
            return;
        }

        while (src) {
            array.push_back(src % base);
            src /= base;
        }
    }

    friend TLong operator+(const TLong & lhs, const TLong & rhs) {
        TLong result(lhs);
        return result += rhs;
    }

    TLong & operator+=(const TLong & rhs) {
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

    TLong & negate() {
        std::transform(
                    array.begin(),
                    array.end(),
                    array.begin(),
                    std::negate<value_t>());
        return *this;
    }

    friend TLong operator-(const TLong & arg) {
        TLong result(arg);
        return result.negate();
    }

    friend TLong operator-(const TLong & lhs, const TLong & rhs) {
        TLong result(lhs);
        return result -= rhs;
    }

    TLong & operator-=(const TLong & rhs) {
        return *this += (-rhs);
    }

    bool isPositive() const;
    bool isNegative() const {
        typename array_t::const_iterator it = std::find_if(
                    array.cbegin(),
                    array.cend(),
                    [](value_t arg){return arg < 0;});

        return it != array.cend();
    }
    bool isNull() const;

    std::string toStdString() const {
        std::string result(sign());
        std::for_each(array.rbegin(),
                      array.rend(),
                      [&result](value_t arg) {
            result.append(std::to_string(std::abs(arg)));
        });
        return result;
    }

private:
    typedef std::vector<value_t> array_t;

    std::string sign() const {
        return isNegative() ?
                    std::string(1, '-') :
                    std::string();
    }

    static const value_t base = 100;
    array_t array;
};

typedef TLong<int> TLongInt;

template<class value_t>
inline std::ostream & operator << (std::ostream & stream,
                                   const TLong<value_t> & rhs) {
    return stream << rhs.toStdString();
}

#endif // LONGINT_H
