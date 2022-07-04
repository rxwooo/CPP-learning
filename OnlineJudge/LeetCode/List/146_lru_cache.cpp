#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        length = capacity;
        curLen = 0;
    }
    int get(int key)
    {
        if (nodeMap.find(key) == nodeMap.end())
            return -1;

        cache.push_front({key, (*nodeMap[key])[1]});
        cache.erase(nodeMap[key]);
        nodeMap[key] = cache.begin();
        return (*nodeMap[key])[1];
    }
    void put(int key, int value)
    {
        if (nodeMap.find(key) != nodeMap.end())
            cache.erase(nodeMap[key]);
        else
            curLen++;
        cache.push_front({key, value});
        nodeMap[key] = cache.begin();
        if (curLen > length)
        {
            nodeMap.erase(cache.back()[0]);
            cache.pop_back();
            curLen--;
        }
    }
    int length;
    int curLen;
    list<vector<int>> cache;
    unordered_map<int, list<vector<int>>::iterator> nodeMap;
};

int main()
{
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4

    return 0;
}