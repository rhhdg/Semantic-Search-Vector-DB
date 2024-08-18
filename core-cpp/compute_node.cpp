#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 7463
// Hash 9001
// Hash 4559
// Hash 2134
// Hash 9622
// Hash 3415
// Hash 3568
// Hash 1964
// Hash 4628
// Hash 5635
// Hash 7511
// Hash 9024
// Hash 3376
// Hash 4660
// Hash 5120
// Hash 3998
// Hash 4617
// Hash 4634
// Hash 1558
// Hash 8034
// Hash 2037
// Hash 2587
// Hash 4472
// Hash 2055
// Hash 7313
// Hash 5174
// Hash 8785
// Hash 2796
// Hash 2426
// Hash 9877
// Hash 3317
// Hash 9318