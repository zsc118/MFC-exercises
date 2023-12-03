#pragma once
class CRationalNumber
{
	long long p;// ·Ö×Ó
	unsigned long long q;//·ÖÄ¸
	friend inline CRationalNumber &simplify(CRationalNumber &x) noexcept;

public:
	constexpr CRationalNumber() noexcept;
	~CRationalNumber() noexcept;
	CRationalNumber(const long long& x)noexcept:p(x),q(1u){}
	CRationalNumber(const long long& x,const unsigned long long& y)noexcept:p(x),q(y){}
	CRationalNumber(const CRationalNumber& r)noexcept:p(r.p),q(r.q){}
	CRationalNumber(const double &x)noexcept;
	CRationalNumber& operator=(const CRationalNumber& r)noexcept;
	CRationalNumber& operator=(int x)noexcept;
	CRationalNumber& operator=(double x)noexcept;
	CRationalNumber& operator=(const char* x)noexcept;
	CRationalNumber& operator+=(const CRationalNumber& r)noexcept;
	CRationalNumber& operator-=(const CRationalNumber& r)noexcept;
	CRationalNumber& operator*=(const CRationalNumber& r)noexcept;
	CRationalNumber& operator/=(const CRationalNumber& r);
};