// MCF Build
// Copyleft 2014, LH_Mouse. All wrongs reserved.

#ifndef MCFBUILD_MCFBUILD_HPP_
#define MCFBUILD_MCFBUILD_HPP_

#include <cstddef>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "../MCF/StdMCF.hpp"
#include "../MCF/Core/String.hpp"
#include "../MCF/Core/Exception.hpp"

#include "Model.hpp"

#include "ConsoleOutput.hpp"
#include "Localization.hpp"

#define FORMAT_THROW(code, msg)	MCF_THROW(code, ::MCFBuild::FormatString(msg))

#endif
