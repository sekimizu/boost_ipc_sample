// BoostIPCServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

int main()
{
	using namespace boost::interprocess;
	try {
		shared_memory_object shdmem{ open_or_create, "Boost", read_write };
		std::string payload = "Hello, message from IPC server";

		shdmem.truncate(payload.size());
		mapped_region region{ shdmem, read_write };
		
		std::memcpy(region.get_address(), payload.c_str(), payload.size());

		

	}
	catch (interprocess_exception& e) {
		// .. .  clean up 
	}

}