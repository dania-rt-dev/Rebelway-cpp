/**
 * @file binaryTreeFull.cpp
 *
 * @brief Practice implementation of a binary tree.
 *
 * This file contains the implementation for add, removal, search and print of values of the tree.
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
 * @brief Removes a value from the binary tree.
 * 
 * If the value doesn't exist the operation will not be performed.
 *
 * @param root Reference to the root pointer.
 * @param value Value to remove.
 */
void RemoveValue(Node*& root, int value);

/**
 * @brief Searches for a value in the binary tree.
 *
 * @param root Pointer to the root.
 * @param value Value to search for.
 *
 * @return Pointer to the node containing the value, or nullptr if the value wasn't found;
 */
Node* SearchValue(Node* root, int value);

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
 * @brief Prints the contents of the binary tree.
 * 
 * The print is performed following the leaves and branches from left to right.
 *
 * @param root Pointer to the root.
 */
void PrintTree(Node* root);

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

void RemoveValue(Node*& root, int value)
{

    Node* latestNode = SearchValue(root, value);
    if(latestNode != nullptr)
    {
        if(IsLeaf(latestNode))
        {
            if(latestNode->parent == nullptr)
            {
                root = nullptr;
            }
            else
            {
                if(latestNode->parent->LBranch == latestNode)
                {
                    latestNode->parent->LBranch = nullptr;
                }
                else
                {
                    latestNode->parent->RBranch = nullptr;
                }
            }
            
        }
        else if(latestNode->LBranch == nullptr)
        {
            if(latestNode->parent == nullptr)
            {
                root = latestNode->RBranch;
                latestNode->RBranch->parent = nullptr;
            }
            else
            {
                if(latestNode->parent->LBranch == latestNode)
                {
                    latestNode->RBranch->parent = latestNode->parent;
                    latestNode->parent->LBranch = latestNode->RBranch;
                }
                else
                {
                    latestNode->RBranch->parent = latestNode->parent;
                    latestNode->parent->RBranch = latestNode->RBranch;
                }
            }
        }
        else if(latestNode->RBranch == nullptr)
        {
            if(latestNode->parent == nullptr)
            {
                root = latestNode->LBranch;
                latestNode->LBranch->parent = nullptr;
            }
            else
            {
                if(latestNode->parent->LBranch == latestNode)
                {
                    latestNode->LBranch->parent = latestNode->parent;
                    latestNode->parent->LBranch = latestNode->LBranch;
                }
                else
                {
                    latestNode->LBranch->parent = latestNode->parent;
                    latestNode->parent->RBranch = latestNode->LBranch;
                }
            }
        }
        else
        {
            Node* auxNode = latestNode->RBranch;
            while(auxNode->LBranch != nullptr)
            {
                auxNode = auxNode->LBranch;
            }

            latestNode->value = auxNode->value;
            if(auxNode->parent->LBranch == auxNode)
            {
                auxNode->parent->LBranch = auxNode->RBranch;
            }
            else
            {
                auxNode->parent->RBranch = auxNode->RBranch;
            }
            if(auxNode->RBranch != nullptr)
            {
                auxNode->RBranch->parent = auxNode->parent;
            }

            latestNode = auxNode;
        }

        delete latestNode;        
    }
    else
    {
        std::cout << "Value " << "\"" << value << "\"" << " was not found in the tree." << "\n";
    }
}

Node* SearchValue(Node* root, int value)
{
    Node* current = root;
    Node* returnNode{};
    bool found = false;

    while(current != nullptr)
    {
        if(value < current->value)
        {
            current = current->LBranch;
        } 
        else if(value > current->value)
        {
            current = current->RBranch;
        }
        else
        {
            found = true;
            returnNode = current;
            break;
        }
    }

    std::cout << "The value \"" << value << "\" " << "is" << (found ? "" : " not") << " in the tree." << "\n";

    return returnNode;
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

void PrintTree(Node* root)
{
    if(root != nullptr)
    {
        PrintTree(root->LBranch);
        PrintTree(root->RBranch);

        std::cout << root->value << "\n";
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
    int values[] = {10, 5, 2, 8, 15, 20, 17, 1, 8, 7, 13, 11, 9, 3};   ///< Initial values Array
    Node* root{};   ///< Pointer for the root

    for(const int &x : values)
    {
        AddValue(root, x);
    }

    std::cout << "----------" << "\n";
    RemoveValue(root, 19);
    PrintTree(root);
    std::cout << "----------" << "\n";    

    Clear(root);

    return 0;
}