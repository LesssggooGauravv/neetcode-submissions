class Node{
public: 
    int key,val;
    Node*prev;
    Node*next;
    Node(int k ,int v):key(k),val(v),prev(nullptr),next(nullptr){}
};

class LRUCache {
public:
    unordered_map<int, Node*>mpp;
    int cap;
    Node*head;
    Node*tail;

    void deleteNode(Node*node){
        Node*prev = node->prev;
        Node*nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insertAtHead(Node*node){
        Node*temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAtHead(node);
        }
        else{
            if(mpp.size()>=cap){
                Node*node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node*node = new Node(key,value);
            mpp[key] = node;
            insertAtHead(node);
        }
    }
};
