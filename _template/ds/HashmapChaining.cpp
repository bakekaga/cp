#include <vector>

template<typename K, typename V>
class HashMap {
	struct Node {
		K key;
		V val;
		Node* next;
        Node() : next(nullptr) {}
		Node(Node *next) : next(next) {}
		Node(const K &key, const V &val) : key(key), val(val), next(nullptr) {}
	};

	std::vector<Node*> table;
	int capacity;
	int totalKeys{};
	double loadFactor;

public:
	HashMap(int initSize, int initCapacity, double lf) : table(initSize), capacity(initCapacity), loadFactor(lf) {
        for (int i = 0; i < table.size(); i++) {
            table[i] = new Node{};
        }
    }
	HashMap(int initCapacity, double lf) : HashMap(4, initCapacity, lf) {}
	HashMap(int initCapacity) : HashMap(initCapacity, 0.75) {}
	HashMap() : HashMap(4) {}
	~HashMap();

	std::size_t hash(const K &key) const;
	void insert(const K &key, const V &val);
	bool get(const K &key, V &out) const;
	bool remove(const K &key, V &out);
	void resize();
};

template<typename K, typename V>
HashMap<K, V>::~HashMap() {
	for (int i = 0; i < table.size(); i++) {
		Node *entry = table[i];
		while (entry != nullptr) {
			Node *prev = entry;
			entry = entry->next;
			delete prev;
		}
		table[i] = nullptr;
	}
	table.clear();
}

template<typename K, typename V>
std::size_t HashMap<K, V>::hash(const K &key) const {
	return std::hash<K>{}(key);
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K &key, const V &val) {
	std::size_t idx = hash(key) % table.size();
	Node *cur = table[idx];
	while (cur->next != nullptr && cur->key != key) {
		cur = cur->next;
	}
	if (cur->key == key) {
		cur->val = val;
		return;
	}
	cur->next = new Node{key, val};
	totalKeys++;
	if (totalKeys >= loadFactor * capacity) {
		resize();
	}
}

template<typename K, typename V>
bool HashMap<K, V>::get(const K &key, V &out) const {
	std::size_t idx = hash(key) % table.size();
	Node *cur = table[idx];
	while (cur != nullptr) {
		if (cur->key == key) {
			out = cur->val;
            return true;
		}
		cur = cur->next;
	}
	return false;
}

template<typename K, typename V>
bool HashMap<K, V>::remove(const K &key, V &val) {
	std::size_t idx = hash(key) % table.size();
	Node *cur = table[idx];
	while (cur->next != nullptr) {
		if (cur->next->key == key) {
			Node *out = cur->next;
			val = out->val;
			cur->next = out->next;
			delete out;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

template<typename K, typename V>
void HashMap<K, V>::resize() {
	capacity *= 2;
	std::vector<Node*> oldTable = table;
	table.clear();
	table.resize(capacity);
    for (int i = 0; i < table.size(); i++) {
        table[i] = new Node{};
    }
    for (int i = 0; i < oldTable.size(); i++) {
		Node *cur = oldTable[i]->next;
        delete oldTable[i];
		while (cur != nullptr) {
			insert(cur->key, cur->val);
            Node *old = cur;
			cur = cur->next;
            delete old;
		}
	}
}
