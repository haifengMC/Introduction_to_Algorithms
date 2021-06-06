#pragma once

class hAllocator
{
	std::allocator<void> _alloc;
public:
	template<typename Ty>
	Ty* alloc(size_t n = 1) { return (Ty*)_alloc.allocate(n); }
	template<typename Ty>
	void dealloc(Ty* p, size_t n = 1) { _alloc.deallocate(p, n); }
	template<typename Ty, typename... Args >
	void create(Ty* p, Args&&... args) { ::new((void*)p) Ty(std::forward<Args>(args)...); }
	template<typename Ty>
	void destroy(Ty* p) { if (p) p->~Ty(); }
};
