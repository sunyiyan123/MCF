// 这个文件是 MCF 的一部分。
// 有关具体授权说明，请参阅 MCFLicense.txt。
// Copyleft 2013 - 2015, LH_Mouse. All wrongs reserved.

#ifndef MCF_UTILITIES_ENDIAN_HPP_
#define MCF_UTILITIES_ENDIAN_HPP_

#include <type_traits>
#include <climits>

namespace MCF {

template<typename ValueT>
inline ValueT LoadLe(const ValueT &vMem) noexcept {
	static_assert(std::is_integral<ValueT>::value, "ValueT must be an integral type.");

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	return vMem;
#else
	using Unsigned = std::make_unsigned_t<ValueT>;

	const auto &abyMem = reinterpret_cast<const unsigned char (&)[sizeof(vMem)]>(vMem);
	Unsigned uTemp = 0;
	for(unsigned i = 0; i < sizeof(vMem); ++i){
		uTemp |= static_cast<Unsigned>(abyMem[i]) << (i * CHAR_BIT);
	}
	return static_cast<ValueT>(uTemp);
#endif
}
template<typename ValueT>
inline ValueT LoadBe(const ValueT &vMem) noexcept {
	static_assert(std::is_integral<ValueT>::value, "ValueT must be an integral type.");

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	return vMem;
#else
	using Unsigned = std::make_unsigned_t<ValueT>;

	const auto &abyMem = reinterpret_cast<const unsigned char (&)[sizeof(vMem)]>(vMem);
	Unsigned uTemp = 0;
	for(unsigned i = 0; i < sizeof(vMem); ++i){
		uTemp |= static_cast<Unsigned>(abyMem[sizeof(vMem) - 1 - i]) << (i * CHAR_BIT);
	}
	return static_cast<ValueT>(uTemp);
#endif
}

template<typename ValueT>
inline void StoreLe(ValueT &vMem, std::common_type_t<ValueT> vVal) noexcept {
	static_assert(std::is_integral<ValueT>::value, "ValueT must be an integral type.");

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	vMem = vVal;
#else
	using Unsigned = std::make_unsigned_t<ValueT>;

	auto &abyMem = reinterpret_cast<unsigned char (&)[sizeof(vMem)]>(vMem);
	for(unsigned i = 0; i < sizeof(vMem); ++i){
		abyMem[i] = static_cast<Unsigned>(vVal) >> (i * CHAR_BIT);
	}
#endif
}
template<typename ValueT>
inline void StoreBe(ValueT &vMem, std::common_type_t<ValueT> vVal) noexcept {
	static_assert(std::is_integral<ValueT>::value, "ValueT must be an integral type.");

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	vMem = vVal;
#else
	using Unsigned = std::make_unsigned_t<ValueT>;

	auto &abyMem = reinterpret_cast<unsigned char (&)[sizeof(vMem)]>(vMem);
	for(unsigned i = 0; i < sizeof(vMem); ++i){
		abyMem[sizeof(vMem) - 1 - i] = static_cast<Unsigned>(vVal) >> (i * CHAR_BIT);
	}
#endif
}

}

#endif
