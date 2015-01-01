// 这个文件是 MCF 的一部分。
// 有关具体授权说明，请参阅 MCFLicense.txt。
// Copyleft 2013 - 2015, LH_Mouse. All wrongs reserved.

#ifndef MCF_CORE_LAST_ERROR_HPP_
#define MCF_CORE_LAST_ERROR_HPP_

#include "../../MCFCRT/env/last_error.h"
#include "String.hpp"

namespace MCF {

inline unsigned long GetWin32LastError() noexcept {
	return ::MCF_CRT_GetWin32LastError();
}
inline void SetWin32LastError(unsigned long ulErrorCode) noexcept {
	::MCF_CRT_SetWin32LastError(ulErrorCode);
}

extern WideString GetWin32ErrorDescription(unsigned long ulErrorCode);

}

#endif
