### Int
int with more features.
```cpp
using namespace std;
using uInt = Int_t<unsigned>; // you can use any integer type
int main() {
	srand(time(0));
	cout << Int_t<bool>::rand() << ' ' << Int_t<char>::rand('A', 'Z') << ' ' << Int_t<bool>("true") << '\n';
	Int i("2");
	cout
	<< i << ' ' << (i ^ 5) << '\n'// 2 32
	<< bool(i) << ' ' << !i << '\n' // check is 0
	<< Int::Max << ' ' << Int::Min << '\n'
	<< i.str() << ' ' << i.hex() << ' ' << (string)i << '\n' // to string conversation
	<< Int::rand() << ' ' << Int::rand(-15,20) << '\n'
	<< (int)i.byte(1) << ' ' << i.bits() << ' ' << i.bit(0);
}
```
