#include <iostream>
#include <vector>
#include <list>
using namespace std;
class LFUCache {
private:
    struct Node {
        int value;
        int freq;
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node> cache;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> position;

    void updateFreq(int key) {
        int freq = cache[key].freq;

        // Remove from old frequency list
        freqList[freq].erase(position[key]);

        // Update minFreq if needed
        if (freqList[freq].empty()) {
            freqList.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        // Move to next frequency
        cache[key].freq++;

        freqList[freq + 1].push_front(key);
        position[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        updateFreq(key);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (cache.find(key) != cache.end()) {
            cache[key].value = value;
            updateFreq(key);
            return;
        }

        // Evict if full
        if (cache.size() == capacity) {
            int removeKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            cache.erase(removeKey);
            position.erase(removeKey);
        }

        // Insert new key
        cache[key] = {value, 1};

        freqList[1].push_front(key);
        position[key] = freqList[1].begin();

        minFreq = 1;
    }
};