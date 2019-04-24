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
            pointer = &head;
            for(int i=0;i<this->size();i++){
                if( cmp(search, ((*pointer)->next)->data) ){
                    return true;
                }
                pointer=&((*pointer)->next);
            }
            return false;
        }

             
        bool insert(T data) {
            Node<T>* newNode = new Node<T>(data);
            Node<T>** ptr;
            if (not find(data,ptr)) {
                newNode->next=(*ptr)->next;
                **ptr = *newNode;
            } else {
                return false;
            }
        }
             
        bool remove(T item) {
            Node<T>** ptr;
            bool found = find(item,ptr);
            if (found) {
                Node<T>* temp = *ptr;
                ptr=&((*ptr)->next);
                delete temp;
                return true;
            } else {
                return false;
            }
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
            int count=0;
            Node<T>* last = this->head;
            if (this->size()<index)
                throw out_of_range("index>size");
            while (count<index){
                last=last->next;
                count++;
            }
            return last->data;
        }

        ~List() {
            delete this;
        }         
};

#endif