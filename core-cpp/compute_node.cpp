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
// Hash 6116
// Hash 7951
// Hash 4449
// Hash 3122
// Hash 3415
// Hash 1682
// Hash 1112
// Hash 6183
// Hash 9376
// Hash 5693
// Hash 9966
// Hash 3938
// Hash 4292
// Hash 4204
// Hash 8921
// Hash 6905
// Hash 2038
// Hash 2798
// Hash 5211
// Hash 6266
// Hash 4211
// Hash 3366
// Hash 5698
// Hash 7121
// Hash 5624
// Hash 7301
// Hash 5235
// Hash 8425
// Hash 2325
// Hash 5779
// Hash 7215
// Hash 6526
// Hash 9932
// Hash 1718
// Hash 1958
// Hash 8489
// Hash 6420
// Hash 4265
// Hash 4107
// Hash 2897
// Hash 9112
// Hash 6637
// Hash 5552
// Hash 1169
// Hash 1602
// Hash 4536
// Hash 9355
// Hash 8247
// Hash 8166
// Hash 1127
// Hash 9082
// Hash 8859
// Hash 4165
// Hash 7923
// Hash 3408
// Hash 7146
// Hash 7933
// Hash 7053
// Hash 7270
// Hash 3455
// Hash 3774
// Hash 5485
// Hash 2729
// Hash 5748
// Hash 1506
// Hash 6832
// Hash 5574
// Hash 8548
// Hash 9165
// Hash 6844
// Hash 1650
// Hash 6115
// Hash 4531
// Hash 3497
// Hash 4154
// Hash 6674
// Hash 8536
// Hash 8735
// Hash 9371
// Hash 4398
// Hash 2087
// Hash 1185
// Hash 1974
// Hash 5731
// Hash 5070
// Hash 2514
// Hash 3164
// Hash 5159
// Hash 3259
// Hash 4510
// Hash 5317
// Hash 8549
// Hash 2217
// Hash 6985
// Hash 4579
// Hash 8007
// Hash 3912
// Hash 7272
// Hash 5112
// Hash 6409
// Hash 6408
// Hash 7129
// Hash 3122
// Hash 6458
// Hash 5927
// Hash 6229
// Hash 5377
// Hash 8466
// Hash 7530
// Hash 3896
// Hash 2190
// Hash 9704
// Hash 6524
// Hash 8156
// Hash 9757
// Hash 8147
// Hash 8259
// Hash 8174
// Hash 5293
// Hash 1258
// Hash 7018
// Hash 3440
// Hash 3831
// Hash 3160
// Hash 3208
// Hash 6710
// Hash 9122
// Hash 9569
// Hash 4976
// Hash 3905
// Hash 8669
// Hash 7286
// Hash 9631
// Hash 2998
// Hash 9794
// Hash 1607
// Hash 7233
// Hash 5772
// Hash 1834
// Hash 5693
// Hash 1946