#include <MCF/StdMCF.hpp>
#include <MCF/Thread/Thread.hpp>
#include <MCF/Thread/Mutex.hpp>
#include <MCF/Core/Time.hpp>
#include <MCF/Core/Array.hpp>

using namespace MCF;

Mutex m;
volatile int c = 0;

extern "C" unsigned MCFMain(){
/*
	Array<IntrusivePtr<Thread>, 10> threads;
	for(auto &p : threads){
		p = Thread::Create([]{
			for(int i = 0; i < 10000; ++i){
				const auto l = m.GetLock();
				for(int j = 0; j < 10000; ++j){
					++c;
				}
			}
		}, true);
	}

	const auto t1 = GetHiResMonoClock();
	for(auto &p : threads){
		p->Resume();
	}
	for(auto &p : threads){
		p->Join();
	}
	const auto t2 = GetHiResMonoClock();

	std::printf("c = %d, time = %f\n", c, t2 - t1);
*/
	auto now = GetUtcTime();
	auto t1 = GetHiResMonoClock();
	auto l = m.TryGetLock(now + 1000);
	auto t2 = GetHiResMonoClock();
	std::printf("locked? %d  time = %f\n", l.IsLocking(), t2 - t1);

	now = GetUtcTime();
	t1 = GetHiResMonoClock();
	l = m.TryGetLock(now + 1000);
	t2 = GetHiResMonoClock();
	std::printf("locked? %d  time = %f\n", l.IsLocking(), t2 - t1);

	return 0;
}
