#pragma once

#include <cstring>

namespace otus {

template <class T>
class IArray {
public:
    ~IArray() = default;
    virtual size_t size() const noexcept = 0;
    virtual void add(T) = 0;
    virtual void add(T, size_t) = 0;
    virtual T& get(size_t) const = 0;
    virtual T remove(size_t) = 0;
};

template <class T>
class BaseArray : public IArray<T> {
public:
    ~BaseArray() { delete[] data_; }

    size_t size() const noexcept override { return size_; }

    void add(T item) {
        resize();
        data_[size_] = item;
        ++size_;
    }

    void add(T item, std::size_t index) override {
        resize();
        for (std::size_t i = size_; i > index; --i) {
            data_[i] = data_[i - 1];
        }
        data_[index] = item;
        ++size_;
    }

    T& get(size_t index) const noexcept override { return data_[index]; }

    T remove(std::size_t index) override {
        auto remove_item = data_[index];
        for (std::size_t i = index; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
        return remove_item;
    }

private:
    void resize() {
        if (size_ < capacity_) {
            return;
        }

        auto new_size = GetNewSize();
        auto new_data = new T[new_size];
        std::memcpy(new_data, data_, size_ * sizeof(T));
        delete[] data_;
        data_ = new_data;
        capacity_ = new_size;
    }

protected:
    virtual size_t GetNewSize() const = 0;

protected:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;
};

template <class T>
class SingleArray : public BaseArray<T> {
protected:
    size_t GetNewSize() const override { return this->size_ + 1; }
};

template <class T>
class VectorArray : public BaseArray<T> {
public:
    VectorArray(int vector = 10) : vector_{vector} {}

protected:
    size_t GetNewSize() const override { return this->size_ + vector_; }

private:
    int vector_ = 0;
};

template <class T>
class FactorArray : public BaseArray<T> {
public:
    FactorArray(int factor = 2) : factor_{factor} {}

protected:
    size_t GetNewSize() const override {
        if (this->size_ == 0)
            return 1;
        return this->size_ * factor_;
    }

private:
    int factor_ = 1;
};

template <class T>
class MatrixArray : public IArray<T> {
public:
    MatrixArray(size_t vector = 10) {
        vector_ = vector;
        data_ = new FactorArray<IArray<T>*>();
    }

    ~MatrixArray() { delete data_; }

    size_t size() const noexcept override { return size_; }

    void add(T item) {
        resize();
        data_->get(size_ / vector_)->add(item);
        ++size_;
    }

    void add(T item, std::size_t index) override {
        resize();
        for (std::size_t i = index; i < size_; ++i) {
            swap(data_->get(i / vector_)->get(i % vector_), item);
        }
        data_->get(size_ / vector_)->add(item);
        ++size_;
    }

    T& get(size_t index) const override {
        return data_->get(index / vector_)->get(index % vector_);
    }

    T remove(std::size_t index) override {
        auto remove_item = data_->get(index / vector_)->get(index % vector_);
        for (std::size_t i = index; i < size_ - 1; ++i) {
            data_->get(i / vector_)->get(i % vector_) =
                data_->get((i + 1) / vector_)->get((i + 1) % vector_);
        }
        --size_;
        return remove_item;
    }

private:
    void swap(T& a, T& b) {
        auto tmp = a;
        a = b;
        b = tmp;
    }

    void resize() {
        if (size_ == data_->size() * vector_) {
            data_->add(new FactorArray<T>(vector_));
        }
    }

private:
    size_t size_ = 0;
    size_t vector_ = 0;
    IArray<IArray<T>*>* data_ = nullptr;
};

}  // namespace otus