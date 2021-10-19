#ifndef HEADERS_MODSECURITY_INTERVENTION_H_
#define HEADERS_MODSECURITY_INTERVENTION_H_

typedef struct ModSecurityIntervention_t {
	int status;
	int pause;
	char *url;
	char *log;
	int disruptive;
} ModSecurityIntervention;


#ifdef __cplusplus
extern "C"
{
#endif


#ifdef __cplusplus
}
#endif


#endif  // HEADERS_MODSECURITY_INTERVENTION_H_
