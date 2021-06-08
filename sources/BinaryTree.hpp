//
// Created by amit on 20/05/2021.
//

#ifndef BINARYTREE_A_BINARYTREE_H
#define BINARYTREE_A_BINARYTREE_H
#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <stack>
#include <queue>

using namespace std;
namespace ariel {

    template<typename T> class Node{
    public:
        T value;
        Node* left;
        Node* right;

        Node(T& value_) : value(value_), right(NULL),  left(NULL) {}

        Node(Node &src) = default;
        Node(Node&& other) = delete;

        ~Node() = default;
        
        Node& operator=(Node& other) = delete;
        Node& operator=(Node&& other) = delete;
    };
    
    template<typename T> class BinaryTree {

    private:

        Node<T>* root;

        void copytree(const Node<T>& src, Node<T>& dest){

            if(src.right!=NULL) {
                dest.right = new Node<T>(src.right->value);
                copytree(*src.right,*dest.right);
            }

            if(src.left!=NULL) {
                dest.left = new Node<T>(src.left->value);
                copytree(*src.left,*dest.left);
            }
        }

        Node<T>* search( T& value , Node<T>* root){
            stack<Node<T> *> s;
            Node<T> *curr = root;

            while (curr != NULL || s.empty() == false)
            {
                /* Reach the left most Node of the
                   curr Node */
                while (curr != NULL)
                {
                    /* place pointer to a tree node on
                       the stack before traversing
                      the node's left subtree */
                    s.push(curr);
                    //Check if this node is the one we looking for
                    if(curr->value == value){
                        return curr;
                    }
                    curr = curr->left;
                }

                /* Current must be NULL at this point */
                curr = s.top();
                s.pop();


                /* we have visited the node and its
                   left subtree.  Now, it's right
                   subtree's turn */
                curr = curr->right;

            } /* end of while */
            throw invalid_argument("Node not found.");
        }

    public:
        BinaryTree() : root(NULL) {}
        ~BinaryTree() {};


        BinaryTree(BinaryTree<T>&& other){
            root = other.root;
            other.root = NULL;
        }


        BinaryTree(const BinaryTree<T> &otherTree){
            if(otherTree.root!=NULL) {
                root = new Node<T>(otherTree.root->value);
                copytree(*otherTree.root,*root);
            }
        }

        //Overload
        BinaryTree& operator=(BinaryTree other){
            if(this == &other){
                return *this;
            }
            if(root != NULL){
                delete this->root;
            }
            root = new Node<T>(other.root->value);
            copytree(*other.root,*this->root);

            return *this;
        }

        BinaryTree& operator=(BinaryTree&& otherTree){
            *this->root = otherTree.root;
        }

        BinaryTree& add_root(T value){
            if(root!= NULL){
                root->value= value;
            }
            else{
                root = new Node<T>(value);
            }
            return *this;
        }

        // adds a node to the left
        BinaryTree &add_left( T parent_value,  T left_value){
            Node<T> * father = search(parent_value,root);

            if(father->left == NULL){
                father->left = new Node<T>(left_value);
            }
            else{
                father->left ->value = left_value;
            }
            return *this;
        }

        BinaryTree &add_right( T parent_value,  T right_value){
            Node<T> * father = search(parent_value,root);
            if(father->right == NULL){
                father->right = new Node<T>(right_value);
            }
            else{
                father->right ->value = right_value;
            }
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree){
            os << "This tree";
            return os;
        }

        // Inner iterator class
        class iter{

        private:

            void preorder_fill(Node<T>* n){
                if(n == NULL){return;}

                q.push(n);
                preorder_fill(n->left);
                preorder_fill(n->right);
            }

            void inorder_fill(Node<T>* n){
                if(n == NULL){return;}

                inorder_fill(n->left);
                q.push(n);
                inorder_fill(n->right);
            }

            void postorder_fill(Node<T>* n){
                if(n == NULL){return;}

                postorder_fill(n->left);
                postorder_fill(n->right);
                q.push(n);
            }

        public:

            Node<T>* current_node;
            queue<Node<T>*> q;

            iter():current_node(NULL){}

            iter(Node<T>* t):current_node(t){}

            iter(Node<T>* root ,const string &type){
                if(root != NULL){
                    if(type == "pre") {preorder_fill(root);}
                    if(type == "in") {inorder_fill(root);}
                    if(type == "post") {postorder_fill(root);}
                    current_node = q.front();
                }
                else{
                    current_node =NULL;
                }
            }

            T &operator*() const {
                return current_node->value;
            }

            T *operator->() const {
                return &(current_node->value);
            }

            iter &operator++(){
                if(q.size()>1){
                    q.pop();
                    current_node = q.front();
                }
                else{
                    current_node =NULL;
                }
                return *this;
            }

            iter operator++(int){
                iter t(q.front());
                ++*this;
                return t;
            }

            bool operator==(const iter &other) const {
                return current_node == NULL;
            }

            bool operator!=(const iter &other) const {
                return !(*this == other);
            }
        }; // end of iter class

        //Default - Inorder
        iter begin(){
            return iter{root,"in"};
        };
        iter end(){
            return iter{};
        };

        // preorder (parent - left - right).
        iter begin_preorder(){
            return iter{root,"pre"};
        }
        iter end_preorder(){
            return iter{};
        }

        // inorder (left - parent - right).
        iter begin_inorder(){
            return iter{root,"in"};
        }
        iter end_inorder(){
            return iter{};
        }

        // postorder (left - right - parent).
        iter begin_postorder(){
            return iter{root,"post"};
        }
        iter end_postorder(){
            return iter{};
        }
    };
}

#endif //BINARYTREE_A_BINARYTREE_H