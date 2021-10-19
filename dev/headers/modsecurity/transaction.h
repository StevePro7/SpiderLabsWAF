#ifndef HEADERS_MODSECURITY_TRANSACTION_H_
#define HEADERS_MODSECURITY_TRANSACTION_H_

#include "modsecurity/modsecurity.h"
#include "modsecurity/rules_set.h"
#include "modsecurity/intervention.h"


class Transaction
{
public:
	Transaction( ModSecurity *transaction, RulesSet *rules, void *logCbData );
	~Transaction();

	bool intervention( ModSecurityIntervention *it );

	ModSecurityIntervention m_it;
};


#ifdef __cplusplus
extern "C"
{
#endif

	Transaction *msc_new_transaction( ModSecurity *ms,
		RulesSet *rules, void *logCbData );
	int msc_process_connection( Transaction *transaction,
		const char *client, int cPort, const char *server, int sPort );
	int msc_process_uri( Transaction *transaction, const char *uri,
		const char *protocol, const char *http_version );
	int msc_process_request_headers( Transaction *transaction );
	int msc_process_request_body( Transaction *transaction );

	int msc_intervention( Transaction *transaction, ModSecurityIntervention *it );

#ifdef __cplusplus
}
#endif

#endif  // HEADERS_MODSECURITY_TRANSACTION_H_
