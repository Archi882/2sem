#include "vector.h"

#include <sstream>
#include <stdexcept>

Vector::Vector()
    : data_(nullptr), size_(0), capacity_(0)
{
}

Vector::Vector(std::initializer_list<int> values)
    : data_(nullptr), size_(values.size()), capacity_(values.size())
{
    if (capacity_ > 0)
    {
        data_ = new int[capacity_];

        size_type index = 0;
        for (int value : values)
        {
            data_[index++] = value;
        }
    }
}

Vector::Vector(const Vector& other)
    : data_(nullptr), size_(other.size_), capacity_(other.size_)
{
    if (capacity_ > 0)
    {
        data_ = new int[capacity_];
        for (size_type i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }
}

Vector::Vector(Vector&& other) noexcept
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
{
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
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
        capacity_ = other.size_;
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
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    return *this;
}

int& Vector::operator[](size_type index)
{
    if (index >= size_)
    {
        throw std::out_of_range("Vector: index out of range");
    }

    return data_[index];
}

const int& Vector::operator[](size_type index) const
{
    if (index >= size_)
    {
        throw std::out_of_range("Vector: index out of range");
    }

    return data_[index];
}

Vector& Vector::operator<<(size_type count)
{
    if (size_ == 0 || count == 0)
    {
        return *this;
    }

    if (count >= size_)
    {
        for (size_type i = 0; i < size_; ++i)
        {
            data_[i] = 0;
        }
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

Vector& Vector::operator>>(size_type count)
{
    if (size_ == 0 || count == 0)
    {
        return *this;
    }

    if (count >= size_)
    {
        for (size_type i = 0; i < size_; ++i)
        {
            data_[i] = 0;
        }
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

void Vector::Insert(int value)
{
    Insert(value, size_);
}

void Vector::Insert(int value, size_type index)
{
    if (index > size_)
    {
        throw std::out_of_range("Vector: insert index out of range");
    }

    if (size_ == capacity_)
    {
        Reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }

    for (size_type i = size_; i > index; --i)
    {
        data_[i] = data_[i - 1];
    }

    data_[index] = value;
    ++size_;
}

void Vector::RemoveAt(size_type index)
{
    if (index >= size_)
    {
        throw std::out_of_range("Vector: remove index out of range");
    }

    for (size_type i = index; i + 1 < size_; ++i)
    {
        data_[i] = data_[i + 1];
    }

    --size_;

    if (size_ == 0)
    {
        delete[] data_;
        data_ = nullptr;
        capacity_ = 0;
    }
}

Vector::size_type Vector::Find(int value) const noexcept
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

void Vector::Reserve(size_type newCapacity)
{
    if (newCapacity <= capacity_)
    {
        return;
    }

    int* newData = new int[newCapacity];

    for (size_type i = 0; i < size_; ++i)
    {
        newData[i] = data_[i];
    }

    delete[] data_;
    data_ = newData;
    capacity_ = newCapacity;
}