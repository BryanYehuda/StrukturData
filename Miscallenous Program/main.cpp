#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class LinkedList
{
    private:
        Node *header;
        Node *tail;
        int size;
    public:
        LinkedList(){
            header = NULL;
            tail = NULL;
            size = 0;
    }

    int getSize(){
    return size;
    }

    void append(int data)
    {
        //create new node
        Node *n = new Node(data);
        //Case 1 : Empty List
        if (header == NULL){
            header = n;
            tail = n;
        }
        //Case 2 : List is not empty
        else{
            tail->next = n;
            tail = n;
        }
        //Increment Size Counter
        size++;
    }

    void prepend(int data){
        Node *n = new Node(data);
        if(header == NULL){
            header = n;
            tail = n;
        }
        else{
            Node *temp = header;
            header = n;
            n->next = temp;
        }
        size++;
    }

    void removeFirst(){
        if(header != NULL){
            Node *temp = header;
            header = header->next;
            delete temp;
            size--;
        }
    }

    void removeLast(){
        //Case 1: Empty
        //Case 2: only 1 node
        if(header->next == NULL)
            removeFirst();
        //Case 3: More than 1 node
        else if(header != NULL){
            Node *cur = header;
            Node *prev;
            while(cur->next != NULL){
                prev = cur;
                cur = cur->next;
            }
            tail = prev;
            tail->next = NULL;
            delete cur;
            size--;
        }
    }

    void removeAt(int pos){
        //Case 1: check for valid pos
        if(pos > size || pos <1)
            return;
        //Case 2: check if pos is the first node
        else if(pos == 1)
            removeFirst();
        //Case 3: check if pos is the last node
        else if(pos == size)
            removeLast();
        else if(header != NULL){
            Node *cur = header;
            Node *prev;
            for(int i=1; i<pos; i++){
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
            size--;
        }
    }

    void insertAt(int pos, int data){
        if(pos <1 || pos >size+1)
            return;
        else if(pos == 1)
            prepend(data);
        else if(pos == size+1)
            append(data);
        else if(header != NULL){
            Node *n = new Node(data);
            Node *cur = header;
            Node *prev;
            for(int i=1; i<pos; i++){
                prev = cur;
                cur = cur->next;
            }
            prev->next = n;
            n->next = cur;
            size++;
        }
    }

    void print(){
        Node *temp = header;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main(){
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.print();
    list.prepend(5);
    list.print();
    list.removeFirst();
    list.print();
    list.removeLast();
    list.print();
    list.append(5);
    list.print();
    list.removeAt(2);
    list.print();
    list.insertAt(3,6);
    list.print();

}
