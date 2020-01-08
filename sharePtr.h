#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__
#include <stdexcept>

template<typename T, int IS_ARRAY = 0>
class SharedPtr
{
public:
    explicit SharedPtr(T* = NULL);
    SharedPtr(const SharedPtr &);
    ~SharedPtr();
    
    template<class U>
    SharedPtr(const SharedPtr<U>& ptr);


    T* operator->() const;
    T& operator*()  const;


	SharedPtr& operator= (const SharedPtr& ptr);
	SharedPtr& operator= (T * ptr);
	
	
	void reset();
	
	
	bool operator!=(const SharedPtr&) const;
	bool operator==(const SharedPtr&) const;


	operator bool() const;
	
	
    T* get() const;	
	size_t getCounter() const;
private:
	T * m_ptr;
	size_t * refCount;
};


template<typename T, int IS_ARRAY>
SharedPtr<T, IS_ARRAY>::SharedPtr(T* ptr)try :m_ptr(ptr), refCount(new size_t(1))
{}
catch(std::bad_alloc& e)
{
	delete ptr;		
	throw;
}

template<typename T, int IS_ARRAY>
SharedPtr<T, IS_ARRAY>::SharedPtr(const SharedPtr & sp):m_ptr(sp.m_ptr), refCount(sp.refCount)
{
	++(*refCount);
}

template<typename T, int IS_ARRAY>
SharedPtr<T, IS_ARRAY>::~SharedPtr()
{
	reset();
}

template<typename T, int IS_ARRAY>
template<class U>
SharedPtr<T, IS_ARRAY>::SharedPtr(const SharedPtr<U>& ptr):m_ptr(ptr.m_ptr), refCount(ptr.refCount)
{
	++(*refCount);
}

template<typename T, int IS_ARRAY>
T* SharedPtr<T, IS_ARRAY>::operator->() const
{
	if (!m_ptr)
		throw std::invalid_argument("its a NULL pointer");
	return m_ptr;
}

template<typename T, int IS_ARRAY>
T& SharedPtr<T, IS_ARRAY>::operator*()  const
{
	if (!m_ptr)
		throw std::invalid_argument("its a NULL pointer");
	return *m_ptr;
}

template<typename T, int IS_ARRAY>
SharedPtr<T, IS_ARRAY>& SharedPtr<T, IS_ARRAY>::operator=(const SharedPtr<T, IS_ARRAY>& ptr)
{
	reset();
		
	m_ptr = ptr.m_ptr;
	refCount = ptr.refCount;
	++(*refCount);
	
	return *this;
}

template<typename T, int IS_ARRAY>
SharedPtr<T, IS_ARRAY>& SharedPtr<T, IS_ARRAY>::operator=(T * ptr)
{
	reset();
	
	m_ptr = ptr.m_ptr;
	refCount = new size_t(1);
	
	return *this;
}

template<typename T, int IS_ARRAY>
void SharedPtr<T, IS_ARRAY>::reset()
{
	--(*refCount);
	if(*refCount == 0)
	{
		if(IS_ARRAY)
			delete[] m_ptr;
		else
			delete m_ptr;
		delete refCount;
	}
}
	
template<typename T, int IS_ARRAY>
inline bool SharedPtr<T, IS_ARRAY>::operator!=(const SharedPtr& sp) const
{
	return m_ptr != sp.m_ptr;
}
	
template<typename T, int IS_ARRAY>
inline bool SharedPtr<T, IS_ARRAY>::operator==(const SharedPtr& sp) const
{
	return m_ptr != sp.m_ptr;
}

template<typename T, int IS_ARRAY>
inline SharedPtr<T, IS_ARRAY>::operator bool() const
{
	return m_ptr;
}

template<typename T, int IS_ARRAY>
inline T* SharedPtr<T, IS_ARRAY>::get() const
{
	return m_ptr;
}	
	
template<typename T, int IS_ARRAY>
inline size_t SharedPtr<T, IS_ARRAY>::getCounter() const
{
	return *refCount;
}
	
#endif //__SHAREDPTR_H__
