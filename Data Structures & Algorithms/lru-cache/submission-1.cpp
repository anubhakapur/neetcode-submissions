class Node{
    public:
        int val;
        int key;
        Node*prev;
        Node*next;
        Node(int k,int v){
            val=v;
            key=k;
            prev=next=nullptr;
        }
};
class LRUCache {
public:
    unordered_map<int,Node*>mp;
    int capacity;
    // Node*head=nullptr;
    Node*left=nullptr;
    Node*right=nullptr;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        Node*temp=mp[key];
        if(temp==left)return temp->val;
        
        Node*prevNode=temp->prev;
        Node*nextNode=temp->next;

        prevNode->next=nextNode;

        if(nextNode==nullptr){
            right=prevNode;
        }else{
            nextNode->prev=prevNode;
        }

        temp->prev=nullptr;
        temp->next=left;

        left->prev=temp;
        left=temp;

        //mp[key]=left; as node is still same
        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node*temp=mp[key];
            temp->val=value;

            if(temp!=left){
                Node*prevNode=temp->prev;
                Node*nextNode=temp->next;

                prevNode->next=nextNode;

                if(nextNode==nullptr){
                    right=prevNode;
                }else{
                    nextNode->prev=prevNode;
                }

                temp->prev=nullptr;
                temp->next=left;

                left->prev=temp;
                left=temp;
            }
        }else{
            if(mp.size()>=capacity){
                Node*temp=right;
                mp.erase(temp->key);
                right=right->prev;
                if(right)right->next=nullptr;
                else{
                    left=nullptr;
                }
                delete temp;
            }
            Node*nn=new Node(key,value);
            mp[key]=nn;
            if(left==nullptr){
                left=right=nn;
            }else{
                nn->next=left;
                left->prev=nn;
                left=nn;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */