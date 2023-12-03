//#include "stdafx.h"
#include "RationalNumber.h"
#include <algorithm>

// �򻯷���
static inline CRationalNumber& simplify(CRationalNumber &x) noexcept
{
    // �������Լ��
    long long m = std::__gcd<long long>(x.p > 0 ? x.p : -x.p, x.q);
    // �������
    x.p /= m;
    x.q /= m;
    return x;
}

// ���캯��
constexpr CRationalNumber::CRationalNumber() noexcept
{
}

// ��������
CRationalNumber::~CRationalNumber() noexcept
{
}

// ���캯��
// �˺���ֻ������doubleΪ8Byte�Ļ���
// 1    :����λ
// 2-12 :ָ��
// 13-64:����
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