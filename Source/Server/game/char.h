// 1. Search
bool	SashIsSameGrade(long lGrade);

// 2. Change with

#ifdef __SASH_SYSTEM_EXTENDED__
		bool	SashIsSameGrade(long lGrade, long lAbs);
#else
		bool	SashIsSameGrade(long lGrade);
#endif