#ifndef HEADERS_MODSECURITY_TRANSACTION_H_
#define HEADERS_MODSECURITY_TRANSACTION_H_

#include "modsecurity/modsecurity.h"
#include "modsecurity/rules_set.h"

class Transaction
{
public:
	Transaction( ModSecurity *transaction, RulesSet *rules, void *logCbData );
	~Transaction() {}
};


#ifdef __cplusplus
extern "C"
{
#endif

	Transaction *msc_new_transaction( ModSecurity *ms,
		RulesSet *rules, void *logCbData );
	int msc_process_connection( Transaction *transaction,
		const char *client, int cPort, const char *server, int sPort );

#ifdef __cplusplus
}
#endif

#endif  // HEADERS_MODSECURITY_TRANSACTION_H_
