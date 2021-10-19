#include "modsecurity/transaction.h"

Transaction::Transaction( ModSecurity * ms, RulesSet * rules, void * logCbData )
{
}


extern "C" Transaction *msc_new_transaction( ModSecurity *ms,
	RulesSet *rules, void *logCbData ) {
	return new Transaction( ms, rules, logCbData );
}

extern "C" int msc_process_connection( Transaction *transaction,
	const char *client, int cPort, const char *server, int sPort ) {
	//return transaction->processConnection( client, cPort, server, sPort );
	return 10;
}

extern "C" int msc_process_uri( Transaction *transaction, const char *uri,
	const char *protocol, const char *http_version ) {
	//return transaction->processURI( uri, protocol, http_version );
	return 20;
}

extern "C" int msc_process_request_headers( Transaction *transaction ) {
	//return transaction->processRequestHeaders();
	return 30;
}

extern "C" int msc_process_request_body( Transaction *transaction ) {
	//return transaction->processRequestBody();
	return 40;
}


extern "C" int msc_intervention( Transaction *transaction,
	ModSecurityIntervention *it ) {
	//return transaction->intervention( it );
	return 1;
}