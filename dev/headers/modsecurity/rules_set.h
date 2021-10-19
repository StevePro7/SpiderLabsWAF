#ifndef HEADERS_MODSECURITY_RULES_SET_H_
#define HEADERS_MODSECURITY_RULES_SET_H_

class RulesSet
{
public:
	RulesSet() {}
	~RulesSet() {}
};


#ifdef __cplusplus
extern "C"
{
#endif

	RulesSet *msc_create_rules_set( void );
	int msc_rules_add_file( RulesSet *rules, const char *file, const char **error );
	int msc_rules_cleanup( RulesSet *rules );

#ifdef __cplusplus
}
#endif

#endif  // HEADERS_MODSECURITY_RULES_SET_H_