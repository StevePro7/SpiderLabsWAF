#include "main.h"

char main_rule_uri[] = "basic_rules.conf";

int main( int argc, char **argv )
{
	//ModSecurity *modsec = NULL;
	ModSecurity *modsec = msc_init();
	int age = modsec->GetAge();

	bar();
	return 0;
}