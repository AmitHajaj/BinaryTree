//
// Created by amit on 20/05/2021.
//

#ifndef BINARYTREE_A_BINARYTREE_H
#define BINARYTREE_A_BINARYTREE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


namespace ariel{
    template<typename T>
    class BinaryTree{
    public:
        struct Node{
            T value;
            Node *left_child;
            Node *right_child;
        };

        class inorder_iterator{
        public:
            inorder_iterator(Node* ptr = nullptr) : m_pointer(ptr){}

            inorder_iterator& operator ++(){
                return *this;
            }

            bool operator <(inorder_iterator& i){
                return false;
            }

            bool operator!=(const inorder_iterator& i){
                return false;
            }

            T& operator *(){
                return m_pointer->value;
            }

            T* operator ->(){
                return &(m_pointer->value);
            }

        private:
            Node* m_pointer;
        };

        class preorder_iterator{
        public:
            preorder_iterator(Node* ptr = nullptr) : m_pointer(ptr){}

            preorder_iterator& operator ++(){
                return *this;
            }

            bool operator <(preorder_iterator& i){
                return false;
            }

            bool operator!=(const preorder_iterator& i){
                return false;
            }

            T& operator *() const{
                return m_pointer->value;
            }

            T* operator ->() const{
                return &(m_pointer->value);
            }

        private:
            Node* m_pointer;
        };

        class postorder_iterator{
        public:
            postorder_iterator(Node* ptr = nullptr) : m_pointer(ptr){}

            postorder_iterator& operator ++(){
                return *this;
            }

            bool operator <(postorder_iterator& i){
                return false;
            }

            bool operator!=(const postorder_iterator& i){
                return false;
            }

            T& operator *(){
                return m_pointer->value;
            }

            T* operator ->(){
                return &(m_pointer->value);
            }

        private:
            Node* m_pointer;
        };

        BinaryTree<T>(){

        }

        BinaryTree<T> add_root(T root){
            return *this;
        }

        BinaryTree<T> add_left(T node, T left_child){
            return *this;
        }

        BinaryTree<T> add_right(T node, T right_child){
            return *this;
        }

        inorder_iterator end(){
            return inorder_iterator{root};
        }

        inorder_iterator begin(){
            return inorder_iterator{root};
        }

        preorder_iterator end_preorder(){
            return preorder_iterator{root};
        }

        preorder_iterator begin_preorder(){
            return preorder_iterator{root};
        }

        inorder_iterator end_inorder(){
            return inorder_iterator{root};
        }

        inorder_iterator begin_inorder(){
            return inorder_iterator{root};
        }

        postorder_iterator end_postorder(){
            return postorder_iterator{root};
        }

        postorder_iterator begin_postorder(){
            return postorder_iterator{root};
        }


        friend ostream& operator<< (ostream& os, const BinaryTree<T>& other){
            os << " ";
            return os;
        }

    private:
        Node* root;

    };
}

#endif //BINARYTREE_A_BINARYTREE_H
