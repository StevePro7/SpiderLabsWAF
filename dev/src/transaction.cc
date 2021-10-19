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
	return 17;
}