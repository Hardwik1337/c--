
#pragma once

#include <iostream>//Андрій Прядко

template <typename T>//Андрій Прядко
class Set {//Андрій Прядко
private://Андрій Прядко
    T* elements;//Андрій Прядко
    int capacity;//Андрій Прядко
    int size;//Андрій Прядко

public://Андрій Прядко
    Set();//Андрій Прядко
    Set(const Set<T>& other);//Андрій Прядко
    ~Set();//Андрій Прядко
    Set<T>& operator=(const Set<T>& other);//Андрій Прядко

    void add(const T& element); //Андрій Прядко
    void remove(const T& element);//Андрій Прядко
    void clear();//Андрій Прядко

    bool contains(const T& element) const;//Тоніццо Сімоне
    int getSize() const;//Андрій Прядко

    Set<T> connectSet(const Set<T>& other) const;//Сирота Денис
    Set<T> intersection(const Set<T>& other) const;//Сирота Денис
    Set<T> difference(const Set<T>& other) const;//Сирота Денис

    template <typename U>//Дударчук Марія
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);
};

template <typename T>//Андрій Прядко
Set<T>::Set() : elements(nullptr), capacity(0), size(0) {}

template <typename T>
Set<T>::Set(const Set<T>& other) : elements(nullptr), capacity(0), size(0) {
    *this = other;//Дударчук Марія
}

template <typename T>//Дударчук Марія
Set<T>::~Set() {
    delete[] elements;
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other) {//Дударчук Марія
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        size = other.size;
        elements = new T[capacity];
        std::copy(other.elements, other.elements + size, elements);
    }
    return *this;
}

template <typename T>
void Set<T>::add(const T& element) {//Дударчук Марія
    if (!contains(element)) {
        if (size >= capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newElements = new T[newCapacity];
            std::copy(elements, elements + size, newElements);
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
        elements[size++] = element;
    }
}

template <typename T>
void Set<T>::remove(const T& element) {//Дударчук Марія
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        std::copy(elements + index + 1, elements + size, elements + index);
        size--;
    }
}

template <typename T>
void Set<T>::clear() {//Дударчук Марія
    delete[] elements;
    elements = nullptr;
    capacity = size = 0;
}

template <typename T>
bool Set<T>::contains(const T& element) const {//Тоніццо Сімоне
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
int Set<T>::getSize() const {//Сирота Денис
    return size;
}

template <typename T>
Set<T> Set<T>::connectSet(const Set<T>& other) const {//Сирота Денис
    Set<T> result = *this;
    for (int i = 0; i < other.size; ++i) {
        result.add(other.elements[i]);
    }
    return result;
}

template <typename T>
Set<T> Set<T>::intersection(const Set<T>& other) const {//Сирота Денис
    Set<T> result;
    for (int i = 0; i < size; ++i) {
        if (other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    return result;
}

template <typename T>
Set<T> Set<T>::difference(const Set<T>& other) const {//Сирота Денис
    Set<T> result = *this;
    for (int i = 0; i < other.size; ++i) {
        result.remove(other.elements[i]);
    }
    return result;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Set<U>& set) {//Дударчук Марія
    os << "{";
    for (int i = 0; i < set.size; ++i) {
        os << set.elements[i];
        if (i < set.size - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}





