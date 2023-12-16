#include <vector>
#include <list>

#include "print_ip.h"
#include "main.h"

/**************************************************************************
* Implemented the function of printing a conditional IP address.
Its convention is that the number of elements does not have to be equal to 4 or 8, 
and also each element does not have to be a number from the range 0..255. 
From the idea of an IP address, all that remains is actually the output of elements through `.` (the dot character).
Implemented for various input parameters using the SFINAE mechanism. Completed for 3 options:
1. The address can be represented as an arbitrary integer type. 
       Output unsigned byte-by-byte, starting with the most significant byte, with the `.` character (dot character) as a delimiter. 
	   All bytes of the number are output.
2. The address can be represented as a string. 
       Displayed as is, regardless of content.
3. The address can be represented in the form of containers `std::list`, `std::vector`. 
       The full contents of the container are displayed element by element and separated by `.` (dot symbol). 
	   The elements are displayed as is.
**************************************************************************/


int main()
{
	print_ip(int8_t{ -1 }); // 255
	print_ip(int16_t{ 0 }); // 0.0
	print_ip(int32_t{ 2130706433 }); // 127.0.0.1
	print_ip(int64_t{ 8875824491850138409 });// 123.45.67.89.101.112.131.41	
	print_ip(std::string{ "Hello, World!"}); // Hello, World!
	print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
	print_ip(std::list<short>{400, 300, 200, 100}); // 400.300.200.100
	//print_ip(std::make_tuple(123, 456, 789, 0)); // 123.456.789.0

	return 0;
}