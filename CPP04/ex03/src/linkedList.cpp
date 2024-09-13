#include "linkedList.hpp"

Node* insertNode(Node* node, void* value)
{
    Node*   newNode = new Node();
    Node*   head = node;

    newNode->addr = value;
    newNode->next = NULL;
    if (node == NULL)
        return (newNode);
    while (node && node->next)
        node = node->next;
    node->next = newNode;
    return (head);
}

void deleteList(Node* node)
{
    Node* curr;

    while (node)
    {
        curr = node->next;
        delete static_cast<AMateria*>(node->addr);
        delete node;
        node = curr;
    }
}
