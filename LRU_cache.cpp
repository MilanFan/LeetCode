/*
 * LRU_cache.cpp
 *
 *  Created on: Jun 16, 2014
 *      Author: Milan Fan
 */

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
    	m_capacity = capacity;
    }

    int get(int key) {
    	if (m_um.find(key) != m_um.end()) {
    		m_list.splice(m_list.begin(), m_list, m_um[key]);
    		m_um[key] = m_list.begin();
    		return m_list.begin()->val;
    	} else {
    		return -1;
    	}
     }

    void set(int key, int value) {
    	if (m_um.find(key) != m_um.end()) {
    		m_list.splice(m_list.begin(), m_list, m_um[key]);
    		m_um[key] = m_list.begin();
    		m_list.begin()->val = value;
    	} else {
    		if (m_list.size() >= m_capacity) {
    			m_um.erase(m_list.back().key);
    			m_list.pop_back();
    		}
    		m_list.push_front(Node(key, value));
    		m_um[key] = m_list.begin();
    	}

    }

private:
    struct Node {
    	int key;
    	int val;
    	Node(int k, int v) : key(k), val(v) {}
    };
    int m_capacity;
    list<Node> m_list;
    unordered_map<int, list<Node>::iterator> m_um;
};
