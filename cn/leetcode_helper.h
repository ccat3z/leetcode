#pragma once
#include <ostream>
#include <tuple>
#include <functional>
#include <type_traits>
#include <iostream>


namespace leetcode {
    template <typename TMethod>
    struct solution_signature;

    template<typename TSolutionClass, typename TReturn, typename... TArgs>
    struct solution_signature<TReturn (TSolutionClass::*) (TArgs...)> {
        using params_t = std::tuple<TArgs..., TReturn>;
        using class_type = TSolutionClass;
    };

    template <typename S>
    using solution_params_t = typename solution_signature<S>::params_t;

    template <typename T>
    std::ostream &operator<<(std::ostream &o, const std::vector<T> &vec) {
        o << "[";
        for (size_t i = 0; i < vec.size(); i++) {
            o << vec[i];
            if (i != vec.size() - 1) {
                o << ", ";
            }
        }
        o << "]";
        return o;
    }

    template <typename TMethod>
    void invoke_and_log(TMethod solution_method, const typename solution_signature<TMethod>::params_t & params) {
        using solution_signature = leetcode::solution_signature<TMethod>;
        using solution_t = typename solution_signature::class_type;
        using params_t = typename solution_signature::params_t;

        ([&]<typename std::size_t... ArgIdxs>(std::index_sequence<ArgIdxs...>) {
            auto actual = std::invoke(solution_method, solution_t(), std::get<ArgIdxs>(params)...);

            std::cerr << std::get<std::tuple_size_v<params_t> - 1>(params)
                      << " = "
                      << actual;
            std::cerr << " # ";
            ((std::cerr << (ArgIdxs == 0 ? "" : ", ") << std::get<ArgIdxs>(params)), ...);
            std::cerr << std::endl;
        })(std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<decltype(params)>> - 1>());


    }

    template <typename TMethod>
    auto make_tester(TMethod solution_method) {
        return [=](const typename solution_signature<TMethod>::params_t & params){
            invoke_and_log(solution_method, params);
        };
    }
}
