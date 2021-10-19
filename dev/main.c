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

int process( const char *uri )
{
	Transaction *transaction = NULL;
	transaction = msc_new_transaction( modsec, rules, NULL );
	msc_process_connection( transaction, "127.0.0.1", 80, "127.0.0.1", 80 );
	fprintf( stderr, "URI=%s\n", uri );
	msc_process_uri( transaction, uri, "CONNECT", "1.1" );
	msc_process_request_headers( transaction );
	////msc_process_request_body( transaction );
	////ModSecurityIntervention intervention;
	////intervention.status = 200;
	////intervention.url = NULL;
	////intervention.log = NULL;
	////intervention.disruptive = 0;
	////int inter = msc_intervention( transaction, &intervention );
	int inter = 0;
	fprintf( stderr, "intervention=%i\n", inter );
	return inter;
}

void cleanup() {
	msc_cleanup( modsec );
	msc_rules_cleanup( rules );
}

int main( int argc, char **argv )
{
	init();
	int inter = process( "/test" );
	if( inter > 0 )
	{
		printf( "Blocked!\n" );
	}
	cleanup();

	return 0;
}