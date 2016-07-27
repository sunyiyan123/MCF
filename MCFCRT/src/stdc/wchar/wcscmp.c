// 这个文件是 MCF 的一部分。
// 有关具体授权说明，请参阅 MCFLicense.txt。
// Copyleft 2013 - 2016, LH_Mouse. All wrongs reserved.

#include "../../env/_crtdef.h"

int wcscmp(const wchar_t *s1, const wchar_t *s2){
	for(;;){

#define UNROLLED(idx_)	\
		{	\
			const long ch1 = (long)(uint16_t)s1[idx_];	\
			const long ch2 = (long)(uint16_t)s2[idx_];	\
			const long delta = ch1 - ch2;	\
			if(delta != 0){	\
				return (delta >> (sizeof(delta) * __CHAR_BIT__ - 1)) | 1;	\
			}	\
			if(ch1 == 0){	\
				return 0;	\
			}	\
		}

		UNROLLED(0)
		UNROLLED(1)
		UNROLLED(2)
		UNROLLED(3)
		UNROLLED(4)
		UNROLLED(5)
		UNROLLED(6)
		UNROLLED(7)

		s1 += 8;
		s2 += 8;
	}
}