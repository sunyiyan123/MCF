#include <MCF/StdMCF.hpp>
#include <cmath>

volatile double d = 27;

extern "C" unsigned _MCFCRT_Main(void) noexcept {
	__builtin_printf("%f\n", std::pow(+0.0     , 1.0/3.0));
	__builtin_printf("%f\n", std::pow(-0.0     , 1.0/3.0));
	__builtin_printf("%f\n", std::pow(+INFINITY, 1.0/3.0));
	__builtin_printf("%f\n", std::pow(-INFINITY, 1.0/3.0));
	__builtin_printf("%f\n", std::pow(+d       , 1.0/3.0));
	__builtin_printf("%f\n", std::pow(-d       , 1.0/3.0));
	return 0;
}
