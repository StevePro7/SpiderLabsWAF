#ifndef HEADERS_MODSECURITY_MODSECURITY_H_
#define HEADERS_MODSECURITY_MODSECURITY_H_

class ModSecurity
{
public:
	int GetAge();
};



#ifdef __cplusplus
extern "C"
{
#endif


	ModSecurity *msc_init( void );
	void msc_cleanup( ModSecurity *msc );

#ifdef __cplusplus
}
#endif

#endif  // HEADERS_MODSECURITY_MODSECURITY_H_