// Disables new operator override. 
// This should be used before third-party library
// includes, and should be followed up with an 
// include of memenable.h
#ifdef DEBUG
	#ifdef DBG_NEW
		#undef DBG_NEW
		#undef new
	#endif
#endif