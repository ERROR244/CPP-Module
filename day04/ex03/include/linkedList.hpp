#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "AMateria.hpp"

typedef struct s_node {
          void*   addr;
          s_node* next;
}     Node;

Node*   insertNode(Node* node, void* value);
void    deleteList(Node* node);

#endif
