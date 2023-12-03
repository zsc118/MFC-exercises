//#include "stdafx.h"
#include "RationalNumber.h"
#include <algorithm>

// 简化分数
static inline CRationalNumber& simplify(CRationalNumber &x) noexcept
{
    // 计算最大公约数
    long long m = std::__gcd<long long>(x.p > 0 ? x.p : -x.p, x.q);
    // 化简分数
    x.p /= m;
    x.q /= m;
    return x;
}

// 构造函数
constexpr CRationalNumber::CRationalNumber() noexcept
{
}

// 析构函数
CRationalNumber::~CRationalNumber() noexcept
{
}

// 构造函数
// 此函数只适用于double为8Byte的机器
// 1    :符号位
// 2-12 :指数
// 13-64:数字
CRationalNumber::CRationalNumber(const double &x) noexcept
{
    const long long& t(*(long long *)(void *)&x);
    p = t & 0x8000000000000000 ? -((t & 0x000fffffffffffffffff) | 0x00100000000000000) : (t & 0x000fffffffffffffffff) | 0x00100000000000000;
    int E((int(t >> 52) & 0x7ff) - 1075); // 1075=1023+52
    if (E < -63 || E > 10)
        q = 0;
    else if (E & 0x80000000)
        q = 1ull << -E;
    else
    {
        p <<= E;
        q = 1ull;
    }
}