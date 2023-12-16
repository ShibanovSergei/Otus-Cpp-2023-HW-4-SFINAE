#include <iostream>
#include <vector>
#include <list>
#include <type_traits>

using namespace std;

// This used for int types.
template<typename T>
enable_if_t<is_signed<T>::value || is_signed<T>::value, void>
print_ip(T int_value)
{
	string result = "";
	uint8_t n = sizeof(int_value);
	vector<uint8_t> parts;
	for (uint8_t i = 0; i < n; i++)
	{
		uint8_t v = int_value & 0xFF;
		int_value >>= 8;
		parts.push_back(v);
	}

	for (size_t i = parts.size(); i > 1; i--)
	{
		cout << (short)parts[i - 1] << '.';
	}

	cout << (short)parts[0] << endl;
}

// This used for std::string.
template<typename T>
// typename enable_if_t<is_same<T, string>::value, void> - variant similar to the other two
auto print_ip(T str_value) -> decltype(str_value.length())
{
	cout << str_value << endl;
	return 0;
}

// This used for std::vector and std::list.
template<typename T>
enable_if_t<is_same<T, vector<typename T::value_type>>::value || is_same<T, std::list<typename T::value_type>>::value, void>
print_ip(T cont_value)
{
	std::string dot = "";
	for (auto &v : cont_value)
	{
		cout << dot << v;
		dot = ".";
	}
	cout << endl;
}