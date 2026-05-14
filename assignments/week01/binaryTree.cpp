/**
 * @file binaryTree.cpp
 *
 * @brief Practice implementation of a binary tree.
 *
 * This file focuses on the search and print of leaf nodes.
 */

#include <iostream>

/**
 * @struct Node
 *
 * @brief Data structure for the nodes of the binary tree.
 */
struct Node
{
    int value{};        ///< Value of the tree node
    Node* parent{};     ///< Parent of the node
    Node* LBranch{};    ///< Left branch child
    Node* RBranch{};    ///< Right branch child
};

/**
 * @brief Adds a value into the binary tree.
 * 
 * If the value already exists the operation will not be performed.
 *
 * @param root Reference to the root pointer.
 * @param value Value to add.
 */
void AddValue(Node*& root, int value);

/**
 * @brief Checks if the node is a leaf.
 *
 * @param node Pointer to the node to check.
 *
 * @return True if the node is a leaf, false otherwise.
 */
bool IsLeaf(Node* node);

/**
 * @brief Prints the leaf nodes of the binary tree.
 *
 * @param root Pointer to the root.
 */
void PrintLeaves(Node* root);

/**
 * @brief Clears the nodes and pointers created for the binary tree.
 * 
 * @param root Reference to the root pointer.
 */
void Clear(Node*& root);


void AddValue(Node*& root, int value)
{
    Node* aux = root;
    Node* parent{};
    bool isLeft = false;
    while(aux != nullptr)
    {
        if(value < aux->value)
        {
            parent = aux;
            aux = aux->LBranch;
            isLeft = true;
        }
        else if(value > aux->value)
        {
            parent = aux;
            aux = aux->RBranch;
            isLeft = false;
        }
        else
        {
            std::cout << "Value " << "\"" << value << "\"" << " already exists in the tree." << "\n";
            return;
        }        
    }

    Node* newNode = new Node();
    newNode->value = value;
    newNode->parent = parent;

    if(parent == nullptr)
    {
        root = newNode;
    }
    else
    {
        if(isLeft)
        {
            parent->LBranch = newNode;
        }
        else
        {
            parent->RBranch = newNode;
        }
    }
}

bool IsLeaf(Node* node)
{
    if(node != nullptr)
    {
        return node->LBranch == nullptr && node->RBranch == nullptr;
    }

    return false;
}

void PrintLeaves(Node* root)
{
    if(root != nullptr)
    {
        if(IsLeaf(root))
        {
            std::cout << root->value << "\n";
        }
        else
        {
            PrintLeaves(root->LBranch);
            PrintLeaves(root->RBranch);
        }
    }
}

void Clear(Node*& root) {
    if(root != nullptr)
    {
        Clear(root->LBranch);
        Clear(root->RBranch);
        
        delete root;
        root = nullptr;
    }
}

int main()
{
    int values[] = {10, 5, 2, 8, 15, 20, 17, 1, 7, 13, 11, 9, 3};   ///< Initial values Array
    Node* root{};   ///< Pointer for the root

    for(const int &x : values)
    {
        AddValue(root, x);
    }

    std::cout << "----------" << "\n";    
    PrintLeaves(root);
    std::cout << "----------" << "\n";    

    Clear(root);

    return 0;
}