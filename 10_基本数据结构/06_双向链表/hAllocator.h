#pragma once


template<typename Ty>
class hStdAlloc
{
	static std::allocator<Ty> _alloc;
public:
	static Ty* alloc(size_t n = 1) { return _alloc.allocate(n); }
	static void dealloc(Ty* p, size_t n = 1) { _alloc.deallocate(p, n); }
	template<typename... Args >
	static void create(Ty* p, Args&&... args) { _alloc.construct(p, std::forward<Args>(args)...); }
	static void destroy(Ty* p) { _alloc.destroy(p); }
};
template<typename Ty>
std::allocator<Ty> hStdAlloc<Ty>::_alloc;
