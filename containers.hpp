//
//  containers.hpp
//  mcfin
//
//  Created by Lewis Brown on 06/02/2020.
//  Copyright © 2020 Lewis Brown. All rights reserved.
//

#ifndef containers_hpp
#define containers_hpp

#include <stdio.h>
#include <iostream>
#include <utility>
#include<complex>

namespace ctr
    {

    template<typename T>
    class fundarray
    {
    public:
        
        typedef size_t size_type;
        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T* iterator;
        typedef const T* const_iterator;
        
        // Constructors
        fundarray(size_type sz=0);
        fundarray(size_type sz, value_type el);
        fundarray(const fundarray& rhs);
        fundarray(fundarray&& rhs) noexcept;
        fundarray(std::initializer_list<value_type> init);
        virtual ~fundarray();
        
        // Assingment Operators
        fundarray& operator=(const fundarray<value_type>& rhs);
        fundarray& operator=(fundarray<value_type>&& rhs);
        fundarray& operator=(std::initializer_list<value_type> init);
        
        // Iterators
        pointer begin() noexcept;
        const_pointer cbegin()  const noexcept;
        pointer end() noexcept;
        const_pointer cend() const noexcept;
        
        // Elemental Access
        value_type operator[](size_type idx) const;
        
        // Ostream
        friend std::ostream& operator<<( std::ostream& os, const fundarray<T>& a)
        {
            os<<"[";
            if(a._sz<6)
            {
                for(typename fundarray<T>::size_type i=0; i<a._sz-1; i++)
                    os<<a[i]<<", ";
            }
            else
            {
                for(const_iterator it = a.cbegin(); it!=a.cbegin()+3; ++it)
                    os<<*it<<",";
                os<<"...,";
                for(const_iterator it = a.cend()-3; it!=a.cend()-2; ++it)
                os<<*it<<",";
            }
            os<<*(a.cend()-1)<<"]";
            return os;
        }
        
    protected:
        
        size_type _sz = 0;
        pointer _arr = nullptr;
        
    };
    #include "fundarray.tpp"
        

    template<typename T>
    class euvect : protected fundarray<T>
    {
        
    public:
        
        typedef size_t size_type;
        typedef T value_type;
        
        euvect(size_type sz);
        euvect(size_type sz, value_type el);
        euvect(const euvect& rhs);
        euvect(euvect&& rhs) noexcept;
        euvect(std::initializer_list<value_type> init);
        virtual ~euvect();
        
    };
    template<typename T>
    class euvect<std::complex<T>>
    {
        
    };

    }
#endif /* containers_hpp */
