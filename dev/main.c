#include "main.h"

ModSecurity *modsec = NULL;
RulesSet *rules = NULL;

void init() {
	if( modsec != NULL ) {
		return;
	}
	modsec = msc_init();
	rules = msc_create_rules_set();
	const char *error = NULL;
	msc_rules_add_file( rules, "modsecdefault.conf", &error );
	msc_rules_add_file( rules, "crs-setup.conf", &error );
	msc_rules_add_file( rules, "rules/REQUEST-942-APPLICATION-ATTACK-SQLI.conf", &error );
	return;
}
void cleanup() {
	msc_cleanup( modsec );
	msc_rules_cleanup( rules );
}

int main( int argc, char **argv )
{
	init();
	cleanup();

	return 0;
}