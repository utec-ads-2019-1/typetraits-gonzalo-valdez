#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        List() : head(nullptr) {};

        bool find(T search, Node<T> **&pointer) {
            Node<T>* n = this->head;
            for(int i=0;i<this->size;i++){
                if(n->data==search){
                    pointer=*n; ///////////////
                    return true;
                } else {
                    n=n->next;
                }
            }
            return false;
        }

             
        bool insert(T data) {
            Node<T>* node = new Node<T>(data);
            if (this->head){
                Node<T>* last = this->head;
                while (last->next!=nullptr){
                    last=last->next;
                }
                last->next=node;
                node->prev=last;
            } else {
                this->head=node;
            }
        }
             
        bool remove(T item) {
            Node<T>* n;
            n = find(item,&n);///////////////////
            n->prev->next=n->next;
            delete(n);
        }  
             
        int size() {
            int count=0;
            Node<T>* last = this->head;
            while (last->next!=nullptr){
                last=last->next;
                count++;
            }
            return count;
        }

        T operator[](int index) {

        }

        ~List() {
            // TODO
        }         
};

#endif