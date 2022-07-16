#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class MyLinkedList {
    Node *head;
    public:
    MyLinkedList() {
        head = NULL;
    }
    int get(int index) {
        Node *tmp =head;
        int c = 0;
        while(tmp != NULL)
        {
            if(c == index)
            {
                return tmp->data;
            }
            tmp = tmp->next;
            
            c++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        
        newNode->next = head;
        head = newNode;
    }
        void addAtTail(int val) {
            Node *newNode = new Node(val);
            if(head == NULL)
            {
             head = newNode;
             cout<<newNode<<endl;
             cout<<head<<endl;
             return;   
            }
            Node *tmp = head;
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;

    }
    
    void addAtIndex(int index, int val) {
        int c = 0;
        Node *temp = head;
        Node *beforeTemp = NULL;
        Node *newNode = new Node(val);
        if(index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        int f = 0;
        while(temp != NULL)
        {
            if( c == index )
            {
                newNode->next = temp;
                beforeTemp->next = newNode;
                f = 1;
                break;
            }
            c++;
            beforeTemp = temp;
            temp = temp->next;
        }
        if(!f)
        {
            if(index == c)
            {
                addAtTail(val);
            }
        }
    }
    
    void deleteAtIndex(int index) {
        Node* tmp = head;
        Node* beforeTmp = NULL;
        int c = 0;
        if(index == 0 && head == NULL)
        {
            return;
        }
        else if(index == 0 && head != NULL)
        {
            head = head->next;
            return;
        }
        while(tmp != NULL)
        {
            if(c == index)
            {
                beforeTmp->next = tmp->next;
                return;
            }
            c++;
            beforeTmp = tmp;
            tmp = tmp->next;
        }
    }
    void printList()
    {
        if(head == NULL)
        {
            cout<<"Empty List"<<endl;
            return;
        }
        Node *tmp = head;
        while(tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<endl;

    }
    bool hasCycle() {
        Node *c1 = head;
        bool f = false;
        vector<Node*> vec;
        vec.push_back(head);
        while(c1 != NULL)
        { 
            for(int i=0;i<vec.size();i++)
            {
                if(c1 == vec[i])
                {
                    f = true;
                    break;
                }
            }
            if(f)
                break;
            vec.push_back(c1);
            c1 = c1->next;
        }
        return f;
    }

};

int main()
{
   MyLinkedList *list = new MyLinkedList();
   list->addAtHead(2);
   list->hasCycle();

    return 0;
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */