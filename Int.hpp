#include <iostream>
#include <string>
template <typename T>
class Int_t {
	friend class Int_t<T>;
protected:
	using Byte = unsigned char;
	using _int = Int_t<T>;
	T _Int = 0;
public:
	Int_t() = default;
	Int_t(const Int_t<T>& i) = default;
	Int_t(const T& i) : _Int(i) {}
	//template <typename Y> operator Y() { return Y(_Int); }
	operator T() const { return _Int; }
	operator T&() { return _Int; }
	operator T*() { return &_Int; }
	operator const T* () const { return &_Int; }
	operator bool() const { return _Int != 0; }
	operator std::string() const { return std::to_string(_Int); }
	template <unsigned int at> Byte* byte() { return ((Byte*)this) + at; }
	friend std::ostream& operator<<(std::ostream& os, const _int& i) { return os << i._Int; }
	T operator+() const { return _int(+_Int); }
	T operator-() const { return _int(-_Int); }
	T operator~() const { return _int(~_Int); }
	T& operator++() const { _Int++; return *this; }
	T& operator--() const { _Int--; return *this; }
	template <typename Y> T operator+(const Int_t<Y>& i) const { return _int(_Int + i._Int); }
	template <typename Y> T operator-(const Int_t<Y>& i) const { return _int(_Int - i._Int); }
	template <typename Y> T operator*(const Int_t<Y>& i) const { return _int(_Int * i._Int); }
	template <typename Y> T operator/(const Int_t<Y>& i) const { return _int(_Int / i._Int); }
	template <typename Y> T operator%(const Int_t<Y>& i) const { return _int(_Int % i._Int); }
	template <typename Y> T operator&(const Int_t<Y>& i) const { return _int(_Int & i._Int); }
	template <typename Y> T operator|(const Int_t<Y>& i) const { return _int(_Int | i._Int); }
	template <typename Y> T operator^(const Int_t<Y>& i) const { return _int(_Int ^ i._Int); }
	template <typename Y> T operator<<(const Int_t<Y>& i) const { return _int(_Int << i._Int); }
	template <typename Y> T operator>>(const Int_t<Y>& i) const { return _int(_Int >> i._Int); }
	template <typename Y> T& operator+=(const Int_t<Y>& i) { _Int += i._Int; return *this; }
	template <typename Y> T& operator-=(const Int_t<Y>& i) { _Int -= i._Int; return *this; }
	template <typename Y> T& operator*=(const Int_t<Y>& i) { _Int *= i._Int; return *this; }
	template <typename Y> T& operator/=(const Int_t<Y>& i) { _Int /= i._Int; return *this; }
	template <typename Y> T& operator%=(const Int_t<Y>& i) { _Int %= i._Int; return *this; }
	template <typename Y> T& operator&=(const Int_t<Y>& i) { _Int &= i._Int; return *this; }
	template <typename Y> T& operator|=(const Int_t<Y>& i) { _Int |= i._Int; return *this; }
	template <typename Y> T& operator^=(const Int_t<Y>& i) { _Int ^= i._Int; return *this; }
	template <typename Y> T& operator<<=(const Int_t<Y>& i) { _Int <<= i._Int; return *this; }
	template <typename Y> T& operator>>=(const Int_t<Y>& i) { _Int >>= i._Int; return *this; }
	T operator+(const auto& i) const { return _int(_Int + i); }
	T operator-(const auto& i) const { return _int(_Int - i); }
	T operator*(const auto& i) const { return _int(_Int * i); }
	T operator/(const auto& i) const { return _int(_Int / i); }
	T operator%(const auto& i) const { return _int(_Int % i); }
	T operator&(const auto& i) const { return _int(_Int & i); }
	T operator|(const auto& i) const { return _int(_Int | i); }
	T operator^(const auto& i) const { return _int(_Int ^ i); }
	T operator<<(const auto& i) const { return _int(_Int << i); }
	T operator>>(const auto& i) const { return _int(_Int >> i); }
	T& operator+=(const auto& i) { _Int += i; return *this; }
	T& operator-=(const auto& i) { _Int -= i; return *this; }
	T& operator*=(const auto& i) { _Int *= i; return *this; }
	T& operator/=(const auto& i) { _Int /= i; return *this; }
	T& operator%=(const auto& i) { _Int %= i; return *this; }
	T& operator&=(const auto& i) { _Int &= i; return *this; }
	T& operator|=(const auto& i) { _Int |= i; return *this; }
	T& operator^=(const auto& i) { _Int ^= i; return *this; }
	T& operator<<=(const auto& i) { _Int <<= i; return *this; }
	T& operator>>=(const auto& i) { _Int >>= i; return *this; }
};
