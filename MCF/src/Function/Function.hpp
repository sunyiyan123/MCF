// 这个文件是 MCF 的一部分。
// 有关具体授权说明，请参阅 MCFLicense.txt。
// Copyleft 2013 - 2017, LH_Mouse. All wrongs reserved.

#ifndef MCF_FUNCTION_FUNCTION_HPP_
#define MCF_FUNCTION_FUNCTION_HPP_

#include "../SmartPointers/IntrusivePtr.hpp"
#include "Invoke.hpp"
#include "TupleManipulation.hpp"
#include <type_traits>
#include <utility>
#include <tuple>

namespace MCF {

template<typename PrototypeT>
class Function {
	static_assert((sizeof(PrototypeT *), false), "Class template Function instantiated with non-function template type parameter.");
};

template<typename RetT, typename ...ParamsT>
class Function<RetT (ParamsT ...)> : public IntrusiveBase<Function<RetT (ParamsT ...)>> {
protected:
	using X_ReturnType      = RetT;
	using X_ForwardedParams = std::tuple<ParamsT &&...>;

protected:
	constexpr Function() noexcept {
	}

public:
	virtual ~Function();

protected:
	virtual RetT X_Forward(X_ForwardedParams &&tupParams) const = 0;

public:
	X_ReturnType operator()(ParamsT ...vParams) const {
		return X_Forward(std::forward_as_tuple(std::forward<ParamsT>(vParams)...));
	}
};

template<typename RetT, typename ...ParamsT>
Function<RetT (ParamsT ...)>::~Function(){
}

namespace Impl_Function {
	template<typename PrototypeT, typename FunctionT>
	class ConcreteFunction : public Function<PrototypeT> {
	private:
		std::decay_t<FunctionT> x_vFunction;

	public:
		explicit ConcreteFunction(FunctionT &vFunction)
			: x_vFunction(std::forward<FunctionT>(vFunction))
		{
		}
		~ConcreteFunction();

	protected:
		typename Function<PrototypeT>::X_ReturnType X_Forward(typename Function<PrototypeT>::X_ForwardedParams &&tupParams) const override {
			return Squeeze(x_vFunction, std::move(tupParams));
		}
	};

	template<typename PrototypeT, typename FunctionT>
	ConcreteFunction<PrototypeT, FunctionT>::~ConcreteFunction(){
	}
}

template<typename PrototypeT, typename FunctionT>
IntrusivePtr<Impl_Function::ConcreteFunction<PrototypeT, FunctionT>> MakeFunction(FunctionT &&vFunction){
	return MakeIntrusive<Impl_Function::ConcreteFunction<PrototypeT, FunctionT>>(vFunction);
}

}

#endif
