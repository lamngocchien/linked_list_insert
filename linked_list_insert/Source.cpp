#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
// A linked list node 
class Node
{
public:
    int data;
    Node (*next);
};

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */

void push (Node *(*head), int new_data){
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node (*pre_node), int new_data) {
    if (pre_node != NULL) {
        Node* new_node = new Node;
        new_node->data = new_data;
        new_node->next = pre_node->next;
        pre_node->next = new_node;
    }
    
    return;
    
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node* (*head), int new_data) {
    Node (*new_node) = new Node;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    
    Node (*last) = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;


}

void deleteNodex(Node**node, int val)
{

    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (*node == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    // If current node is the node to be deleted

    if ((*node)->data == val) {
        Node* new_temp = *node;
        *node = new_temp->next; // If it's start of the node head
                           // node points to second node
        delete (new_temp); // Else changes previos node's link to
                    // current node's link
        return;
    }
    deleteNodex(&(*node)->next, val);
}

void deleteNode(Node *(*head), int value)
{
    Node (*temp) = *head;
    Node (*pre_node) = NULL;
    
    // if delete head
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        delete temp;
        return;
    }

    // found temp and previous node
    while (temp != NULL && temp->data != value) {
        pre_node = temp;
        temp = temp->next;
    }

    // if not found temp
    if (temp == NULL)
        return;

    pre_node->next = temp->next;
    delete temp;

}


// This function prints contents of
// linked list starting from head 
void printList(Node (*node))
{   
    cout << "Created Linked list is: ";
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
    cout << endl;
}

/* Driver code*/

int main()
{
    /* Start with the empty list */
    Node (*head) = NULL;
    // Insert 6. So linked list becomes 6->NULL 
    append(&head, 6);
    printList(head);

    // Insert 7 at the beginning. 
    // So linked list becomes 7->6->NULL 
    push(&head, 7);
    printList(head);

    // Insert 1 at the beginning. 
    // So linked list becomes 1->7->6->NULL 
    push(&head, 1);
    printList(head);

    // Insert 4 at the end. So 
    // linked list becomes 1->7->6->4->NULL 
    append(&head, 4);
    printList(head);

    // Insert 8, after 7. So linked 
    // list becomes 1->7->8->6->4->NULL 
    insertAfter(head->next, 8);
    printList(head);

    //deleteNode(&head, 3);
    //printList(head);
    //deleteNode(&head, 8);
    //printList(head);
    deleteNodex(&head, 8);
    printList(head);



    return 0;
}