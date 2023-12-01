#pragma once
#include <algorithm>

template <class T>
class Vector
{
public:
    Vector() = default;

    explicit Vector(size_t number_of_elements) : size_{number_of_elements}, capacity_{number_of_elements}, arr_{new T[size_]()} {}

    Vector(size_t number_of_elements, T element) : size_{number_of_elements}, capacity_{number_of_elements}, arr_{new T[size_]}
    {
        std::fill(begin(), end(), element);
    }

    Vector(const Vector<T>& other)
    {
        Vector<T> copy_of_source(other.capacity_);
        copy_of_source.Resize(other.size_);
        std::copy(other.begin(), other.end(), copy_of_source.begin());
        swap(copy_of_source);
    }

    Vector(Vector<T>&& other)
    {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(arr_, other.arr_);
    }

    Vector& operator=(const Vector& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        Vector<T> tmp(rhs);
        swap(tmp);
        return *this;
    }

    void swap(Vector& other) noexcept
    {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(arr_, other.arr_);
    }




private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* arr_ = nullptr;
};
