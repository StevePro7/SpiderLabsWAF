#include "modsecurity/rules_set.h"
#include "modsecurity/modsecurity.h"
#include "modsecurity/transaction.h"

extern "C" RulesSet *msc_create_rules_set( void ) {
	return new RulesSet();
}

extern "C" int msc_rules_cleanup( RulesSet *rules ) {
	delete rules;
	return true;
}

extern "C" int msc_rules_add_file( RulesSet *rules, const char *file,
	const char **error ) {
	int ret = 0;
//	int ret = rules->loadFromUri( file );
//	if( ret < 0 ) {
//		*error = strdup( rules->getParserError().c_str() );
//	}
	return ret;
}

