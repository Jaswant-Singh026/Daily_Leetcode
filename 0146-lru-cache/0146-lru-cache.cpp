class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* resNode = mp[key];
        int res = resNode->value;

        mp.erase(key);
        deleteNode(resNode);

        addNode(resNode);
        mp[key] = resNode;

        return res;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];

            mp.erase(key);
            deleteNode(existingNode);
        }

        if (mp.size() == capacity) {
            Node* lruNode = tail->prev;

            mp.erase(lruNode->key);
            deleteNode(lruNode);
        }

        Node* newNode = new Node(key, value);

        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */