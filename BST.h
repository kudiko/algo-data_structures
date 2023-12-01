#pragma once
#include <iostream>

template <class Type>
struct Node
{
    Node(Type new_value) : value{new_value}{}
    Type value;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

template <class Type>
class BST {
public:
    BST() = default;
    explicit BST(Type value) : root{new Node<Type>(value)} {}

    Node<Type>* begin()
    {
        return subtree_begin(root);
    }

    Node<Type>* end()
    {
        return subtree_end(root);
    }


    Node<Type>* insert(Type value)
    {
        if (!root)
        {
            root = new Node<Type>(value);
            return root;
        }

//        if (Node<Type>* found_elem_ptr = find(value))
//        {
//            return found_elem_ptr;
//        }

        Node<Type>* t = root;
        Node<Type>* r = t;

        while (t != nullptr) {
            r = t;
            if (value < t->value) {
                t = t->left;
            }
            else if (value > t->value) {
                t = t->right;
            }
            else {
                return nullptr;
            }
        }

        Node<Type>* p = new Node<Type>(value);

        p->parent = r;
        if (value < r->value)
        {
            r->left = p;
        } else {
            r->right = p;
        }


    }

    Node<Type>* find(Type value)
    {
        if (!root)
        {
            return nullptr;
        }

        Node<Type>* t = root;
        while (t)
        {
            if (value == t->value)
            {
                return root;
            }
            else if (value < root->value)
            {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return nullptr;

    }



    static Node<Type>* next(Node<Type>* node)
    {
        if (!node)
        {
            return nullptr;
        }
        if (node->right)
        {
            return subtree_begin(node->right);
        }
        while (node->parent)
        {
            if (node == node->parent->left)
            {
                return node->parent;
            }
            node = node->parent;
        }

    }

    void InorderPrint() const
    {
        InorderPrintSubtree(root);
    }

    static Node<Type>* subtree_begin(Node<Type>* subtree_root)
    {
        while (subtree_root->left)
        {
            subtree_root = subtree_root->left;
        }
        return subtree_root;
    }

    static Node<Type>* subtree_end(Node<Type>* subtree_root)
    {
        while (subtree_root->right)
        {
            subtree_root = subtree_root->right;
        }
        return subtree_root;
    }

    static void InorderPrintSubtree(Node<Type>* subtree_root)
    {
        if (subtree_root)
        {
            InorderPrintSubtree(subtree_root->left);
            std::cout << subtree_root->value << ' ';
            InorderPrintSubtree(subtree_root->right);
        }
    }

    static void PreorderPrintSubtree(Node<Type>* subtree_root)
    {
        if (subtree_root)
        {

            std::cout << subtree_root->value << ' ';
            PreorderPrintSubtree(subtree_root->left);
            PreorderPrintSubtree(subtree_root->right);
        }
    }

    static void PostorderPrintSubtree(Node<Type>* subtree_root)
    {
        if (subtree_root)
        {
            PostorderPrintSubtree(subtree_root->left);
            PostorderPrintSubtree(subtree_root->right);
            std::cout << subtree_root->value << ' ';
        }
    }


private:
    Node<Type>* root = nullptr;
};