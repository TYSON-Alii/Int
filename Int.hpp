#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <random>
#include <bitset>
template <typename T>
class Int_t {
	friend class Int_t<T>;
	using Byte = unsigned char;
	using Str = std::string;
	using uint = unsigned int;
	template <typename T2> T2 sto(const Str&);
	template <> inline bool sto<bool>(const Str& _str) {
		if (_str == "1" or _str == "true") return true;
		else if (_str == "0" or _str == "false") return false;
		throw std::runtime_error("string couldn't convert to bool");
	}
	template <> inline char sto<char>(const Str& _str) { return _str.front(); };
	template <> inline Byte sto<Byte>(const Str& _str) { return (Byte)_str.front(); };
	template <> inline int sto<int>(const Str& _str) { return std::stoi(_str); };
	template <> inline long double sto<long double>(const Str& _str) { return std::stold(_str); };
	template <> inline unsigned sto<unsigned>(const Str& _str) { return (unsigned)std::stoi(_str); };
	template <> inline long sto<long>(const Str& _str) { return std::stol(_str); };
	template <> inline long long sto<long long>(const Str& _str) { return std::stoll(_str); };
	template <> inline unsigned long long sto<unsigned long long>(const Str& _str) { return std::stoull(_str); };
protected:
	using Self_t = Int_t<T>;
	T _data = 0;
public:
	Int_t() = default;
	Int_t(const Int_t<T>& i) = default;
	Int_t(const T& i) : _data(i) {}
	Int_t(const Str& s) : _data(sto<T>(s)) { }
	Int_t(const Str& s, T _make_if_error) {
		try { _data = sto<T>(s); }
		catch (...) { _data = _make_if_error; }
	}
	static const T Max = std::numeric_limits<T>::max();
	static const T Min = std::numeric_limits<T>::min();
	static const bool Signed = std::numeric_limits<T>::is_signed;
	static const uint Size = sizeof(T);
	inline operator T() const requires(not std::is_same_v<T, bool>()) { return _data; }
	inline operator T& () { return _data; }
	inline operator T* () { return &_data; }
	inline operator const T* () const { return &_data; }
	operator float() const { return (float)_data; }
	operator double() const { return (double)_data; }
	operator bool() const { return _data != 0; }
	bool operator!() const { return _data == 0; }
	operator Str() const { return std::to_string(_data); }
	Str str() const { return std::to_string(_data); }
	Str hex(bool full = true) const {
		std::stringstream ss;
		if (full) ss << std::setfill('0') << std::setw(sizeof(T) * 2);
		ss << std::hex << _data;
		return ss.str();
	}
	static T rand() {
		std::random_device rd;
		std::mt19937_64 eng(rd());
		std::uniform_int_distribution<T> distr;
		return distr(eng);
	}
	static T rand(const T min, const T max) {
		const T r = Self_t::rand();
		const T mi = ::std::min(min, max), ma = ::std::max(min, max);
		return (r % (ma-mi)) + mi;
	}
	Str bits() const { return std::bitset<sizeof(_data)*8>(_data).to_string(); }
	template <uint at> Str bit() const { return std::bitset<8>(((Byte*)this) + at).to_string(); }
	Str bit(uint at) const { return std::bitset<8>(*byte(at)).to_string(); }
	template <uint at> Byte* byte() const { return ((Byte*)this) + at; }
	Byte* byte(uint at) const { return ((Byte*)this) + at; }
	Byte* operator[](uint at) const { return byte(at); }
	friend std::ostream& operator<<(std::ostream& os, const Self_t& i) { return os << i._data; }
	auto operator+() const { return Self_t(std::abs(_data)); }
	auto operator-() const { return Self_t(-_data); }
	auto operator~() const { return Self_t(~_data); }
	auto& operator++() const { _data++; return *this; }
	auto& operator--() const { _data--; return *this; }
	template <typename T2> T operator+(const Int_t<T2>& i) const { return Self_t(_data + i._data); }
	template <typename T2> T operator-(const Int_t<T2>& i) const { return Self_t(_data - i._data); }
	template <typename T2> T operator*(const Int_t<T2>& i) const { return Self_t(_data * i._data); }
	template <typename T2> T operator/(const Int_t<T2>& i) const { return Self_t(_data / i._data); }
	template <typename T2> T operator%(const Int_t<T2>& i) const { return Self_t(_data % i._data); }
	template <typename T2> T operator&(const Int_t<T2>& i) const { return Self_t(_data & i._data); }
	template <typename T2> T operator|(const Int_t<T2>& i) const { return Self_t(_data | i._data); }
	template <typename T2> T operator^(const Int_t<T2>& i) const { return Self_t(_data ^ i._data); }
	template <typename T2> T operator<<(const Int_t<T2>& i) const { return Self_t(_data << i._data); }
	template <typename T2> T operator>>(const Int_t<T2>& i) const { return Self_t(_data >> i._data); }
	template <typename T2> bool operator<(const Int_t<T2>& i) const { return _data < i._data; }
	template <typename T2> bool operator>(const Int_t<T2>& i) const { return _data > i._data; }
	template <typename T2> bool operator<=(const Int_t<T2>& i) const { return _data <= i._data; }
	template <typename T2> bool operator>=(const Int_t<T2>& i) const { return _data >= i._data; }
	template <typename T2> bool operator==(const Int_t<T2>& i) const { return _data == i._data; }
	template <typename T2> bool operator!=(const Int_t<T2>& i) const { return _data != i._data; }
	template <typename T2> T& operator+=(const Int_t<T2>& i) { _data += i._data; return *this; }
	template <typename T2> T& operator-=(const Int_t<T2>& i) { _data -= i._data; return *this; }
	template <typename T2> T& operator*=(const Int_t<T2>& i) { _data *= i._data; return *this; }
	template <typename T2> T& operator/=(const Int_t<T2>& i) { _data /= i._data; return *this; }
	template <typename T2> T& operator%=(const Int_t<T2>& i) { _data %= i._data; return *this; }
	template <typename T2> T& operator&=(const Int_t<T2>& i) { _data &= i._data; return *this; }
	template <typename T2> T& operator|=(const Int_t<T2>& i) { _data |= i._data; return *this; }
	template <typename T2> T& operator^=(const Int_t<T2>& i) { _data ^= i._data; return *this; }
	template <typename T2> T& operator<<=(const Int_t<T2>& i) { _data <<= i._data; return *this; }
	template <typename T2> T& operator>>=(const Int_t<T2>& i) { _data >>= i._data; return *this; }
	T operator+(const auto& i) const { return Self_t(_data + i); }
	T operator-(const auto& i) const { return Self_t(_data - i); }
	T operator*(const auto& i) const { return Self_t(_data * i); }
	T operator/(const auto& i) const { return Self_t(_data / i); }
	T operator%(const auto& i) const { return Self_t(_data % i); }
	T operator&(const auto& i) const { return Self_t(_data & i); }
	T operator|(const auto& i) const { return Self_t(_data | i); }
	T operator^(const auto& i) const { return Self_t(pow(_data,i)); }
	T operator<<(const auto& i) const { return Self_t(_data << i); }
	T operator>>(const auto& i) const { return Self_t(_data >> i); }
	bool operator<(const auto& i) const { return _data < i; }
	bool operator>(const auto& i) const { return _data > i; }
	bool operator<=(const auto& i) const { return _data <= i; }
	bool operator>=(const auto& i) const { return _data >= i; }
	bool operator==(const auto& i) const { return _data == i; }
	bool operator!=(const auto& i) const { return _data != i; }
	T& operator+=(const auto& i) { _data += i; return *this; }
	T& operator-=(const auto& i) { _data -= i; return *this; }
	T& operator*=(const auto& i) { _data *= i; return *this; }
	T& operator/=(const auto& i) { _data /= i; return *this; }
	T& operator%=(const auto& i) { _data %= i; return *this; }
	T& operator&=(const auto& i) { _data &= i; return *this; }
	T& operator|=(const auto& i) { _data |= i; return *this; }
	T& operator^=(const auto& i) { _data ^= pow(_data, i); return *this; }
	T& operator<<=(const auto& i) { _data <<= i; return *this; }
	T& operator>>=(const auto& i) { _data >>= i; return *this; }
};
template <> static char Int_t<char>::rand() { return char((::rand()%256)-Min); }
template <> static char Int_t<char>::rand(const char min, const char max) {
	const char r = Self_t::rand();
	const char mi = std::min(min, max), ma = std::max(min, max);
	return (r % (ma - mi)) + mi;
}
template <> static unsigned char Int_t<unsigned char>::rand() { return unsigned char(::rand() % 256); }
template <> static unsigned char Int_t<unsigned char>::rand(const unsigned char min, const unsigned char max) {
	const unsigned char r = Self_t::rand();
	const unsigned char mi = std::min(min, max), ma = std::max(min, max);
	return (r % (ma - mi)) + mi;
}
template <> static bool Int_t<bool>::rand() { return ::rand() % 2 == 0; }
template <> static bool Int_t<bool>::rand(const bool min, const bool max) = delete;
using Int = Int_t<int>;
using uInt = Int_t<unsigned>;
using Long = Int_t<long long>;
using uLong = Int_t<unsigned long long>;
using Char = Int_t<char>;
using uChar = Int_t<unsigned char>;
auto operator"" _I(unsigned long long i) { return Int((int)i); }
