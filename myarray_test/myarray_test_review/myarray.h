#ifndef MYARRAY_H
#define MYARRAY_H
#include <stdexcept>

namespace std
{
template<typename T, size_t N>
class MyArray
{
private:
    T *arr = nullptr;

public:
    MyArray()
    {
        arr = new T [N];
        return;
    }
    MyArray(const MyArray &b)
    {
        arr = new T [N];
        std::copy(b.begin(), b.end(), begin());
        return;
    }
    MyArray(std::initializer_list<T> list)
    {
        arr = new T [N];
        std::copy(list.begin(), list.end(), begin());
        return;
    }
    ~MyArray()
    {
        delete [] arr;
        return;
    }

    size_t size() const noexcept
    {
        return N;
    }
    size_t max_size() const noexcept
    {
        return N;
    }
    bool empty() const noexcept
    {
        return !N;
    }

    T &operator [](const size_t index) noexcept
    {
        return arr[index];
    }
    const T &operator [](const size_t index) const noexcept
    {
        return arr[index];
    }

    T &at(const size_t index)
    {
        if (index >= N)
            throw std::out_of_range("out of range");
        return arr[index];
    }
    const T &at(const size_t index) const
    {
        if (index >= N)
            throw std::out_of_range("out of range");
        return arr[index];
    }

    T *data() noexcept
    {
        return arr;
    }
    const T *data() const noexcept
    {
        return arr;
    }

    T *begin() noexcept
    {
        return data();
    }
    const T *begin() const noexcept
    {
        return data();
    }

    T *end() noexcept
    {
        return data() + N;
    }
    const T *end() const noexcept
    {
        return data() + N;
    }

    T &front() noexcept
    {
        return *begin();
    }
    const T &front() const noexcept
    {
        return *begin();
    }

    T &back() noexcept
    {
        return N ? *(end() - 1) : *end();
    }
    const T &back() const noexcept
    {
        return N ? *(end() - 1) : *end();
    }

    void fill(const T &item) noexcept
    {
        std::fill_n(begin(), N, item);
    }

    void swap(MyArray &b) noexcept
    {
        std::swap_ranges(begin(), end(), b.begin());
    }

    bool operator ==(const MyArray &b) const noexcept
    {
        return std::equal(begin(), end(), b.begin());
    }

    bool operator !=(const MyArray &b) const noexcept
    {
        return !(*this == b);
    }

    bool operator <(const MyArray &b) const noexcept
    {
        return std::lexicographical_compare(begin(), end(), b.begin(), b.end());
    }

    bool operator >(const MyArray &b) const noexcept
    {
        return b < (*this);
    }

    bool operator <=(const MyArray &b) const noexcept
    {
        return !((*this) > b);
    }

    bool operator >=(const MyArray &b) const noexcept
    {
        return !((*this) < b);
    }

    MyArray &operator =(const MyArray &b)
    {
        std::copy(b.begin(), b.end(), begin());
        return *this;
    }
    MyArray &operator =(std::initializer_list<T> list)
    {
        std::copy(list.begin(), list.end(), begin());
        return *this;
    }

    friend std::ostream &operator <<(std::ostream &os, const MyArray &a)
    {
        size_t i;
        for (i = 0; i < N - 1; i++)
            os << a.arr[i] << " ";
        os << a.arr[i];
        return os;
    }
};
} //namespace std

#endif // MYARRAY_H
