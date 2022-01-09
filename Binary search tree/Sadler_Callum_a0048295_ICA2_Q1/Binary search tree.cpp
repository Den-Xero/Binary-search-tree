#include<iostream>
#include<stdlib.h>
using namespace std;


// Makes a Binary search tree class with structer and functions to be used. 
class BST 
{
    // The BST structer
    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;
    // How to empty the tree.
    node* Empty(node* t) {
        if (t == NULL)
            return NULL;
        {
            Empty(t->left);
            Empty(t->right);
            delete t;
        }
        return NULL;
    }
    // How to add a number in to the tree.
    node* insert(int x, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }
    // Finds what the min number is in the tree.
    node* findMin(node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    // Finds what the max number is in the tree.
    node* findMax(node* t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    // Removes the number that the user has asked to be removed.
    node* remove(int x, node* t) {
        node* temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }
    // Puts the tree in order with smallest on the left and biggest on the right.
    void inorder(node* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

// The actions the user can do.
public:
    // Sets tree to start empty for start.
    BST() {
        root = NULL;
    }
    // Empty the tree.
    ~BST() {
        root = Empty(root);
    }
    // Adds number the user has inputed.
    void insert(int x) {
        root = insert(x, root);
        
    }
    // Removes number the user has inputed.
    void remove(int x) {
        root = remove(x, root);
        
    }
    // Prints the tree.
    void display() {
        inorder(root);
        cout << endl;
        
    }

};

// Tree function.
BST t;
int TheBinarySearchTree()
{
    // Ask user what they want to do and get the comand.
    cout << "What would you like to do: " << endl;
    cout << "Type 1 = Insert, 2 = Remove, 3 = Make tree empty, 4 = Display or 5 = Exit. " << endl;
    int UserChoose;
    cin >> UserChoose;
    int UserNumber;



    // Getts the comand that the user wants to run though and call the function needed to do that comand.
    if (UserChoose == 1)
    {
        cout << "What number do u want to insert: " << endl;
        cin >> UserNumber;
        t.insert(UserNumber);
        t.display();
        TheBinarySearchTree();
    }
    else if (UserChoose == 2)
    {
        cout << "What number do want to remove: " << endl;
        cin >> UserNumber;
        t.remove(UserNumber);
        t.display();
        TheBinarySearchTree();
    }
    else if (UserChoose == 3)
    {
        cout << "Empting the tree." << endl;
        t.~BST();
        t.display();
        TheBinarySearchTree();
    }
    else if (UserChoose == 4)
    {
        cout << "The tree currently looks like this: " << endl;
        t.display();
    }
    else if (UserChoose == 5)
    {
        cout << "bye bye" << endl;
        exit(0);
    }
    else
        cout << "Not a vaild number please put a number from 1 - 7 " << endl;
        TheBinarySearchTree();


}

// Calls users actions.
int main()
{
    TheBinarySearchTree();
}



