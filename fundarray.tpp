
#include "containers.hpp"



template<typename T>
fundarray<T>::fundarray(size_type sz) : _sz(sz)
{
    _arr = new T[_sz];
}

template<typename T>
fundarray<T>::fundarray(size_type sz, value_type el): _sz(sz)
{
    _arr = new value_type[_sz];
    for(size_type i=0; i<_sz; i++)
        _arr[i] = el;
}

template<typename T>
fundarray<T>::fundarray(const fundarray& rhs): _sz(rhs._sz)
{
    _arr = new value_type[_sz];
    for(size_type i=0; i<_sz; i++)
        _arr[i] = rhs[i];
}

template<typename T>
fundarray<T>::fundarray(fundarray&& rhs) noexcept: _sz(rhs._sz)
{
    _arr = new value_type[_sz];
    for(size_type i=0; i<_sz; i++)
        _arr[i] = std::move(rhs[i]);
}

template<typename T>
fundarray<T>::fundarray(std::initializer_list<value_type> init)
{
    _arr = new value_type[init.size()];
    for(auto& list_el: init)
        _arr[_sz++] = list_el;
}

template<typename T>
fundarray<T>::~fundarray()
{
    delete[] _arr;
}


template<typename T>
fundarray<T>& fundarray<T>::operator=(const fundarray& rhs)
{
    for(size_type i=0; i<rhs._sz; i++)
        _arr[i] = rhs[i];
    _sz = rhs._sz;
    return *this;
}

template<typename T>
fundarray<T>& fundarray<T>::operator=(fundarray&& rhs)
{
    for(size_type i=0; i<rhs._sz; i++)
        _arr[i] = std::move(rhs[i]);
    _sz = rhs._sz;
    return *this;
}

template<typename T>
fundarray<T>& fundarray<T>::operator=(std::initializer_list<value_type> rhs)
{
    _sz = 0;
    for (auto &el: rhs)
        _arr[_sz++] = el;
    return *this;
}


template<typename T>
typename fundarray<T>::pointer fundarray<T>::begin() noexcept
{
    return _arr;
}

template<typename T>
typename fundarray<T>::const_pointer fundarray<T>::cbegin() const noexcept
{
    return _arr;
}

template<typename T>
typename fundarray<T>::pointer fundarray<T>::end() noexcept
{
    return _arr + _sz;
}

template<typename T>
typename fundarray<T>::const_pointer fundarray<T>::cend() const noexcept
{
    return _arr + _sz;
}


template<typename T>
typename fundarray<T>::value_type fundarray<T>::operator[](size_type idx) const
{
    return *(_arr+idx);
}

//template <typename T>
//std::ostream& operator<<( std::ostream& os, const fundarray<T>& a)



