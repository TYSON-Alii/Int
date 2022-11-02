### Int
int with more features.
```cpp
using namespace std;
using uInt = Int_t<unsigned>; // you can use any integer type
int main() {
	Int i = 2;
	cout
		<< i << ' '// 2 
		<< bool(i) << ' ' << !i << ' ' // check is 0
		<< Int::Max << ' ' << Int::Min << ' '
		<< i.str() << ' ' << i.hex() << ' ' << (string)i << ' ' // to string conversation
		<< Int::rand() << ' ' << Int::rand(-15,20) << ' '
		<< i.byte(1) << ' ' << i.bits() << ' ' << i.bit(2);
}
```
