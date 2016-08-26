#include <MCF/StdMCF.hpp>
#include <MCF/Core/String.hpp>
#include <MCF/Core/Clocks.hpp>

extern "C" unsigned _MCFCRT_Main(void) noexcept {
	constexpr char z[] = "abcdefg\x00αβγδεζη\x00一二三四五六七𤭢𤭢𤭢𤭢𤭢𤭢𤭢";
	MCF::Utf8String t;
	for(unsigned i = 0; i < 1000; ++i){
		t.Append(z, sizeof(z));
	}
	MCF::Utf8String ss = t;
	MCF::Utf32String s1;
	MCF::Utf16String s2;
	MCF::Cesu8String s3;
	MCF::ModifiedUtf8String s4;
	const auto t1 = MCF::GetHiResMonoClock();
	for(unsigned i = 0; i < 10000; ++i){
		s1 = ss;
		s2 = s1;
		s3 = s2;
		s4 = s3;
		ss = s4;
	}
	const auto t2 = MCF::GetHiResMonoClock();
	std::printf("t2 - t1 = %f, d = %d\n", t2 - t1, ss.Compare(t));
	return 0;
}
