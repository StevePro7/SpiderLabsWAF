#include "modsecurity/modsecurity.h"

int ModSecurity::GetAge()
{
	return 9;
}

extern "C" ModSecurity *msc_init( void ) {
	return new ModSecurity();
}

extern "C" void foo( void )
{
}