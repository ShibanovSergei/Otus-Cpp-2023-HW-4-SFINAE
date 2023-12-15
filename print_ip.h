#include <iostream>
#include <vector>
#include <list>
#include <type_traits>

using namespace std;

// This used for int types.
template<typename T>
typename enable_if_t<is_signed<T>::value || is_signed<T>::value, void>
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
// typename std::enable_if_t<std::is_same<T, std::string>::value, void> - variant similar to the other two
auto print_ip(T str_value) -> decltype(str_value.length())
{
	cout << str_value << endl;
	return 0;
}

// This used for std::vector and std::list.
template<typename T>
typename std::enable_if_t<std::is_same<T, std::vector<typename T::value_type>>::value || std::is_same<T, std::list<typename T::value_type>>::value, void>
print_ip(T cont_value)
{
	size_t n = cont_value.size();

	std::string result = "";
	char buffer[50]{};
	for (auto it = cont_value.cbegin(); it != cont_value.cend(); it++)
	{
		_itoa_s(*it, buffer, 10);
		buffer[49] = '\0';
		result = result.append(buffer).append(".");
	}

	if (result.size() > 0)
	{
		if (result.ends_with('.'))
			result.erase(result.end() - 1);
	}

	cout << result << endl;
}