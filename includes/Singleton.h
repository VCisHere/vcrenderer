#pragma once

#include <memory>

template <typename T, typename U = T>
class Singleton {
public:
    virtual ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

protected:
    Singleton() = default;

    // Get singleton
    static std::shared_ptr<U> Instance()
    {
        if (instance == nullptr)
        {
            instance = std::shared_ptr<U>(new T);
        }
        return instance;
    }

private:
    // Singleton instance
    static std::shared_ptr<U> instance = nullptr;
};
