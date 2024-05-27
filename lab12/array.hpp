//
//  array.hpp
//  lab12
//
//  Created by Jakub Matysek on 27/05/2024.
//

#ifndef array_hpp
#define array_hpp

#include <chrono>
#include <mutex>
#include <thread>

template <int N>
struct Array {
    int a[N];
    int i = 0;
    long long sum = 0;
    int thread_done = 1;
    int sum_done = 1;
    int thread_count = 1;

    std::mutex mtx_i;
    std::mutex mtx_thread_done;
    std::mutex mtx_sum;

    Array(int thread_count)
        : a { 0 }
        , i(0)
        , sum(0)
        , sum_done(thread_count)
        , thread_done(thread_count)
        , thread_count(thread_count) {
    }

    int f(int x) {
        int y = x % 11;
        return (y * y + 1);
    }

    void generateArray() {
        while (true) {
            std::lock_guard<std::mutex> lock(mtx_i);
            if (i >= N)
                break;
            a[i++] = rand();
        }

        {
            std::lock_guard<std::mutex> lock(mtx_thread_done);
            if (thread_done == 1) {
                std::lock_guard<std::mutex> lock(mtx_i);
                i = 0;
            }
            thread_done--;
        }

        while (thread_done > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        while (true) {
            std::lock_guard<std::mutex> lock(mtx_i);
            if (i >= N)
                break;
            a[i] = f(a[i]);
            i++;
        }
    }

    void computeSum() {
        {
            std::lock_guard<std::mutex> lock(mtx_sum);
            if (sum_done == thread_count) {
                sum = 0;
                std::lock_guard<std::mutex> lock(mtx_i);
                i = 0;
            }
            sum_done--;
        }

        while (true) {
            std::lock_guard<std::mutex> lock(mtx_i);
            if (i >= N)
                break;
            {
                std::lock_guard<std::mutex> lock(mtx_sum);
                sum += a[i++];
            }
        }
    }

    long long getSum() {
        return sum;
    }
};

#endif /* array_hpp */
