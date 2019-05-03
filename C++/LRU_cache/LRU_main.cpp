
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRU_cache
{
	list<int>dq;
	unordered_map<int, list<int>::iterator>mp;
	int dq_size;
public:
	LRU_cache(int sz)
	{
		dq_size = sz;
	}
	
	void put_data_cache(int key)
	{
		if (dq.size() == dq_size)
		{
			int back = dq.back();
			dq.pop_back();

			mp.erase(back);

			dq.push_front(key);
			//int front = dq.front();
			//mp.emplace(key, dq.begin());
			mp.insert(pair<int, list<int>::iterator>(key, dq.begin()));
		}
		else
		{			
			dq.push_front(key);
			mp.insert(pair<int, list<int>::iterator>(key, dq.begin()));
		}
	

	}

	int get_data_from_cache(int key)
	{
		if (mp.find(key) != mp.end())
		{
			dq.erase(mp[key]);
			dq.push_front(key);
			mp[key] = dq.begin();
			return key;
		}
		else
		{
			return -1;
		}
	}

	void display()
	{
		for (auto it = dq.begin(); it != dq.end(); it++)
			cout << *it << endl;

		cout << endl;
	}

	
};

int main()
{
	LRU_cache cache(4);
	cout << cache.get_data_from_cache(1);
	cache.display();
	cache.put_data_cache(1);
	cache.put_data_cache(2);
	cache.put_data_cache(3);
	cout << cache.get_data_from_cache(2);
	cache.display();
	cache.put_data_cache(4);

	cache.display();
	cache.put_data_cache(5);
	cache.display();

	return 0;
}