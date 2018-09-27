# 题意
Least recently used (LRU) 最近最少使用的缓存替换策略，一次 get 或一次 put 都被称为使用。
这个算法策略主要是记录容量有限的缓存中每个元素是都是何时使用的。

# 解法
使用list保存数据，使用unordered_map保存迭代器。

# 源码
```c++
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
    public:
        LRUCache(int capacity) : capacity(capacity){};
        string get(string key) {
            auto it = positionMap.find(key);
            if(it == positionMap.end()) {
                return "Not Found";
            }
            dataList.splice(dataList.begin(), dataList, it->second);
            return it->second->second;
        }
        void put(string key, string value) {
            auto it = positionMap.find(key);
            dataList.push_front({key, value});
            if(it != positionMap.end()) {
                dataList.erase(it->second);
            }
            positionMap[key] = dataList.begin();
            if(dataList.size() > capacity) {
                positionMap.erase(dataList.back().first);
                dataList.pop_back();
            }
        }
    private:
        size_t capacity;
        list<pair<string, string> > dataList;
        unordered_map<string, list<pair<string, string> > :: iterator> positionMap;
};
int main()
{
    LRUCache cache(3);
    cache.put("name", "ruofeng");
    cout << cache.get("name") << endl;
    cout << cache.get("PC") << endl;
    return 0;
}
```

# 参考
https://ruofeng.me/2018/07/13/lru-cache/
