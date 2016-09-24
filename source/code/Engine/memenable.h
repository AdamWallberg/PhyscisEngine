// Overrides new operator so that we can get a more
// detailed description of memory leaks.
#ifdef DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
		#define new DBG_NEW
	#endif
#endif