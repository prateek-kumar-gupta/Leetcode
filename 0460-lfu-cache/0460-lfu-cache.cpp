class Node{
public:
    int key,val,cnt;
    Node *next,*prev;

    Node(int key,int val){
        this->key=key;
        this->val=val;
        cnt=1;
        next=NULL;
        prev=NULL;
    }
};

class List{
public:
    int size;
    Node *head,*tail;

    List(){
        size=0;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void addFront(Node *node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
        size++;
    }

    void removeNode(Node *node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        size--;
    }
};

class LFUCache {
public:

    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqList;

    int maxSize;
    int curSize;
    int minFreq;

    LFUCache(int capacity) {
        maxSize=capacity;
        curSize=0;
        minFreq=0;
    }

    void updateFreq(Node *node){

        keyNode.erase(node->key);

        freqList[node->cnt]->removeNode(node);

        if(node->cnt==minFreq && freqList[node->cnt]->size==0)
            minFreq++;

        node->cnt++;

        if(freqList.find(node->cnt)==freqList.end())
            freqList[node->cnt]=new List();

        freqList[node->cnt]->addFront(node);

        keyNode[node->key]=node;
    }

    int get(int key) {

        if(keyNode.find(key)==keyNode.end())
            return -1;

        Node *node=keyNode[key];

        int ans=node->val;

        updateFreq(node);

        return ans;
    }

    void put(int key, int value) {

        if(maxSize==0)
            return;

        if(keyNode.find(key)!=keyNode.end()){

            Node *node=keyNode[key];

            node->val=value;

            updateFreq(node);

            return;
        }

        if(curSize==maxSize){

            List *list=freqList[minFreq];

            Node *node=list->tail->prev;

            keyNode.erase(node->key);

            list->removeNode(node);

            curSize--;
        }

        curSize++;

        minFreq=1;

        Node *node=new Node(key,value);

        if(freqList.find(1)==freqList.end())
            freqList[1]=new List();

        freqList[1]->addFront(node);

        keyNode[key]=node;
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */