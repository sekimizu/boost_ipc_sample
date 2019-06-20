// BoostIPCClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>


int main()
{
    std::cout << "IPC Client start!\n"; 
	using namespace boost::interprocess;
	try {
		shared_memory_object shdmem{ open_or_create, "Boost", read_write };
		
		mapped_region region{ shdmem, read_write };

		std::string payload(static_cast<const char *>(region.get_address()), region.get_size());
		
		std::cout << payload << '\n';

		shared_memory_object::remove("Boost");
		std::cout << "Shared object deletetd" << std::endl;
	}
	catch (interprocess_exception& e) {
		// .. .  clean up 
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
