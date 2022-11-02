#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <random>
#include <bitset>
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
	static const T Max = std::numeric_limits<T>::max();
	static const T Min = std::numeric_limits<T>::min();
	static const T Signed = std::numeric_limits<T>::is_signed;
	operator T() const { return _Int; }
	operator T& () { return _Int; }
	operator T* () { return &_Int; }
	operator const T* () const { return &_Int; }
	operator float() const { return (float)_Int; }
	operator double() const { return (double)_Int; }
	operator bool() const { return _Int != 0; }
	bool operator!() const { return _Int == 0; }
	operator std::string() const { return std::to_string(_Int); }
	std::string str() const { return std::to_string(_Int); }
	std::string hex(bool full = true) const {
		std::stringstream ss;
		if (full) ss << std::setfill('0') << std::setw(sizeof(T) * 2);
		ss << std::hex << _Int;
		return ss.str();
	}
	static T rand() {
		std::random_device rd;
		std::mt19937_64 eng(rd());
		std::uniform_int_distribution<T> distr;
		return distr(eng);
	}
	static T rand(const T min, const T max) {
		const T r = _int::rand();
		const T mi = ::min(min, max), ma = ::max(min, max);
		return (r % (ma-mi)) + mi;
	}
	std::string bits() const { return std::bitset<sizeof(_Int)*8>(_Int).to_string(); }
	template <unsigned int at> std::string bit() const { return std::bitset<8>(((Byte*)this) + at).to_string(); }
	std::string bit(unsigned int at) const { return std::bitset<8>(*byte(at)).to_string(); }
	template <unsigned int at> Byte* byte() const { return ((Byte*)this) + at; }
	Byte* byte(unsigned int at) const { return ((Byte*)this) + at; }
	Byte* operator[](unsigned int at) const { return byte(at); }
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
	template <typename Y> bool operator<(const Int_t<Y>& i) const { return _Int < i._Int; }
	template <typename Y> bool operator>(const Int_t<Y>& i) const { return _Int > i._Int; }
	template <typename Y> bool operator<=(const Int_t<Y>& i) const { return _Int <= i._Int; }
	template <typename Y> bool operator>=(const Int_t<Y>& i) const { return _Int >= i._Int; }
	template <typename Y> bool operator==(const Int_t<Y>& i) const { return _Int == i._Int; }
	template <typename Y> bool operator!=(const Int_t<Y>& i) const { return _Int != i._Int; }
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
	bool operator<(const auto& i) const { return _Int < i; }
	bool operator>(const auto& i) const { return _Int > i; }
	bool operator<=(const auto& i) const { return _Int <= i; }
	bool operator>=(const auto& i) const { return _Int >= i; }
	bool operator==(const auto& i) const { return _Int == i; }
	bool operator!=(const auto& i) const { return _Int != i; }
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
using Int = Int_t<int>;
