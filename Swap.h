#pragma once
#include <utility>
template <typename T> void Swap(T& a, T& b) {
	T c = std::move(a);
	a = std::move(b);
	b = std::move(c);

}
