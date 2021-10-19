#include "modsecurity/transaction.h"
#include "modsecurity/intervention.h"
#include <string.h>

Transaction::Transaction( ModSecurity * ms, RulesSet * rules, void * logCbData )
{
	intervention::reset( &m_it );
}

Transaction::~Transaction() 
{
	intervention::clean( &m_it );
}

bool Transaction::intervention( ModSecurityIntervention *it )
{
	// transaction.cc : 1433
	if( m_it.disruptive )
	{
		if( m_it.url )
		{
			it->url = strdup( m_it.url );
		}
		it->disruptive = m_it.disruptive;
		it->status = m_it.status;
	}

	return it->disruptive;
}

int Transaction::processRequestBody()
{
	return 17;
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
	return transaction->processRequestBody();
}


extern "C" int msc_intervention( Transaction *transaction,
	ModSecurityIntervention *it ) {
	return transaction->intervention( it );
	//return 1;
}