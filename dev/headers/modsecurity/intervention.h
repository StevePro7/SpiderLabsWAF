#ifndef HEADERS_MODSECURITY_INTERVENTION_H_
#define HEADERS_MODSECURITY_INTERVENTION_H_

#include <stdlib.h>

typedef struct ModSecurityIntervention_t {
	int status;
	int pause;
	char *url;
	char *log;
	int disruptive;
} ModSecurityIntervention;

namespace intervention
{
	static void reset( ModSecurityIntervention_t *i ) {
		i->status = 200;
		i->pause = 0;
		i->url = NULL;
		i->log = NULL;
		i->disruptive = 0;
	}

	static void clean( ModSecurityIntervention_t *i ) {
		i->url = NULL;
		i->log = NULL;
		reset( i );
	}

	static void freeUrl( ModSecurityIntervention_t *i ) {
		if( i->url ) {
			free( i->url );
			i->url = NULL;
		}
	}

	static void freeLog( ModSecurityIntervention_t *i ) {
		if( i->log ) {
			free( i->log );
			i->log = NULL;
		}
	}

	static void free( ModSecurityIntervention_t *i ) {
		freeUrl( i );
		freeLog( i );
	}
}

#ifdef __cplusplus
extern "C"
{
#endif


#ifdef __cplusplus
}
#endif


#endif  // HEADERS_MODSECURITY_INTERVENTION_H_
