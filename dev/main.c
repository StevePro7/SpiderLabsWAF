#include "main.h"

char main_rule_uri[] = "basic_rules.conf";

int main( int argc, char **argv )
{
	ModSecurity *modsec = NULL;
	RulesSet *rules = NULL;

	modsec = msc_init();
	rules = msc_create_rules_set();
	
	int age = modsec->GetAge();
	bar();

	msc_cleanup( modsec );
	msc_rules_cleanup( rules );

	return 0;
}