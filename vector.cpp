#include "vector.h"

#include <sstream>
#include <stdexcept>
#include <utility> 

Vector::Vector()
    : data_(nullptr), size_(0)
{
}

Vector::Vector(const std::initializer_list<int> values)
    : data_(nullptr), size_(values.size())
{
    if (size_ > 0)
    {
        data_ = new int[size_];
        size_type index = 0;
        for (int value : values)
        {
            data_[index++] = value;
        }
    }
}

Vector::Vector(const Vector& other)
    : data_(nullptr), size_(other.size_)
{
    if (size_ > 0)
    {
        data_ = new int[size_];
        for (size_type i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }
}

Vector::Vector(Vector&& other) noexcept
    : data_(other.data_), size_(other.size_)
{
    other.data_ = nullptr;
    other.size_ = 0;
}

Vector::~Vector()
{
    delete[] data_;
}

Vector& Vector::operator=(const Vector& other)
{
    if (this != &other)
    {
        int* newData = nullptr;

        if (other.size_ > 0)
        {
            newData = new int[other.size_];
            for (size_type i = 0; i < other.size_; ++i)
            {
                newData[i] = other.data_[i];
            }
        }

        delete[] data_;
        data_ = newData;
        size_ = other.size_;
    }

    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept
{
    if (this != &other)
    {
        delete[] data_;

        data_ = other.data_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.size_ = 0;
    }

    return *this;
}

int& Vector::operator[](const size_type index)
{
    if (index >= size_)
    {
        throw std::out_of_range("Vector: index out of range");
    }

    return data_[index];
}

const int& Vector::operator[](const size_type index) const
{
    if (index >= size_)
    {
        throw std::out_of_range("Vector: index out of range");
    }

    return data_[index];
}

Vector& Vector::operator<<(const size_type count)
{
    if (size_ == 0 || count == 0) return *this;

    if (count >= size_)
    {
        for (size_type i = 0; i < size_; ++i) data_[i] = 0;
        return *this;
    }

    for (size_type i = 0; i < size_ - count; ++i)
    {
        data_[i] = data_[i + count];
    }

    for (size_type i = size_ - count; i < size_; ++i)
    {
        data_[i] = 0;
    }

    return *this;
}

Vector& Vector::operator>>(const size_type count)
{
    if (size_ == 0 || count == 0) return *this;

    if (count >= size_)
    {
        for (size_type i = 0; i < size_; ++i) data_[i] = 0;
        return *this;
    }

    for (size_type i = size_; i-- > count;)
    {
        data_[i] = data_[i - count];
    }

    for (size_type i = 0; i < count; ++i)
    {
        data_[i] = 0;
    }

    return *this;
}

void Vector::Insert(const int value)
{
    Insert(value, size_);
}

void Vector::Insert(const int value, const size_type index)
{
    if (index > size_)
    {
        throw std::out_of_range("Vector: insert index out of range");
    }

    int* newData = new int[size_ + 1];

    for (size_type i = 0; i < index; ++i)
    {
        newData[i] = data_[i];
    }

    newData[index] = value;

    for (size_type i = index; i < size_; ++i)
    {
        newData[i + 1] = data_[i];
    }

    delete[] data_;
    data_ = newData;
    ++size_;
}

void Vector::RemoveAt(const size_type index)
{
    if (index >= size_)
    {
        throw std::out_of_range("Vector: remove index out of range");
    }

    if (size_ == 1)
    {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        return;
    }

    int* newData = new int[size_ - 1];

    for (size_type i = 0; i < index; ++i)
    {
        newData[i] = data_[i];
    }

    for (size_type i = index + 1; i < size_; ++i)
    {
        newData[i - 1] = data_[i];
    }

    delete[] data_;
    data_ = newData;
    --size_;
}

Vector::size_type Vector::Find(const int value) const noexcept
{
    for (size_type i = 0; i < size_; ++i)
    {
        if (data_[i] == value)
        {
            return i;
        }
    }

    return npos;
}

bool Vector::Empty() const noexcept
{
    return size_ == 0;
}

Vector::size_type Vector::Size() const noexcept
{
    return size_;
}

std::string Vector::ToString() const
{
    std::ostringstream out;
    out << '[';

    for (size_type i = 0; i < size_; ++i)
    {
        if (i > 0)
        {
            out << ", ";
        }
        out << data_[i];
    }

    out << ']';

    return out.str();
}
