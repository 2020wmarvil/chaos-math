#pragma once

// https://stackoverflow.com/questions/8368512/does-c11-have-c-style-properties

template <typename T>
class Property {
public:
    virtual ~Property() {}
    virtual T& operator= (const T& f) { return value = f; }
    virtual const T& operator() () const { return value; }
    virtual explicit operator const T& () const { return value; }
    virtual T* operator->() { return &value; }
protected:
    T value;

public:
    Property& operator+=(const Property& right) {
      value += right.value;
      return *this;
    }

    friend Property operator+(Property left, const Property& right) {
      left += right;
      return left;
    }
};

template <typename T>
class ReadOnlyProperty {
public:
    virtual ~ReadOnlyProperty() {}
    virtual operator T const & () const { return value; }
protected:
    T value;
};