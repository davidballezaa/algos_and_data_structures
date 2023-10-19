#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
    public:
        int value;
        Node* up;
        Node* left;
        Node* right;

    Node(int value){
        this->value = value;
        this->up = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
        Node* root;

    BST() {
        this->root = NULL;
    }

    BST(int value) {
        Node *new_node = new Node(value);
        this->root = new_node;
    }
    
    void insert(int value);
    void remove(int value);
    Node* search(int value);

    void preorder(Node* aux);
    void inorder(Node* aux);
    void postorder(Node* aux);

    void showTree(Node* aux);

    void levelorder();
    void dfs();
};

void BST::insert(int value){
    Node *new_node = new Node(value);
    if(!this->root){
        this->root = new_node;
    } else {
        Node *curr = this->root;
        while(curr){
            if(new_node->value > curr->value){
                if(curr->right == NULL){
                    curr->right = new_node;
                    break;
                } else {
                    curr = curr->right;
                }
            } else {
                if(curr->left == NULL){
                    curr->left = new_node;
                    break;
                } else {
                    curr = curr->left;
                }
            }
        }
        new_node->up = curr;
    }
}

void BST::remove(int value){
    Node *toBeRemoved = BST::search(value);
    if(!toBeRemoved) return; // edge case value is not found
    if(!toBeRemoved->left && !toBeRemoved->right){ // if leaf, cut link from parent
        Node *parent = toBeRemoved->up;
        if(toBeRemoved->value > parent->value){ // leaf is on right side
            parent->right = NULL;
        }  else { // leaf is on right side
            parent->left = NULL;
        }
        delete toBeRemoved;
    } else if(toBeRemoved->left && toBeRemoved->right){ // if it has two children
        // Find minimum in right subtree
        Node *successor = toBeRemoved->right;
        Node *successorParent = toBeRemoved;
        
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        toBeRemoved->value = successor->value;

        if (toBeRemoved->right == successor) {
            toBeRemoved->right = successor->right;
        } else {
            successorParent->left = successor->right;
        }

        delete successor;
    } else { // if it only has one children (left / right)
        if(toBeRemoved->left){ // if children is on left side
            Node *parent = toBeRemoved->up;
            if(toBeRemoved->value > parent->value){ 
                parent->right = toBeRemoved->left;
            }  else { 
                parent->left = toBeRemoved->left;
            }
        } else { // if it only has children on right
            Node *parent = toBeRemoved->up;
            if(toBeRemoved->value > parent->value){ 
                parent->right = toBeRemoved->right;
            }  else {
                parent->left = toBeRemoved->right;
            }
        }
    }
}

Node* BST::search(int value){
    if(!this->root) return NULL;
    Node* curr = this->root;
    while(curr){
        if(value == curr->value){
            return curr;
        } else if(value > curr->value){
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    cout << "Nodo no encontrado.\n";
    return curr; // NULL
}

void BST::preorder(Node *aux){
    if(!aux) return; 
    cout << aux->value << '\n';
    preorder(aux->left);
    preorder(aux->right);
}

void BST::inorder(Node *aux){
    if(!aux) return;
    inorder(aux->left);
    cout << aux->value << '\n';
    inorder(aux->right);
}

void BST::postorder(Node *aux){
    if(!aux) return;
    postorder(aux->left);
    postorder(aux->right);
    cout << aux->value << '\n';
}

void BST::showTree(Node *aux){
    int L = -1, R = -1;
    if(!aux) return;
    if(aux->left) L = aux->left->value;
    if(aux->right) R = aux->right->value;
    cout << "L(" << L << "), (" << aux->value << "), R(" << R << ")\n";
    showTree(aux->left);
    showTree(aux->right);
}

void BST::levelorder(){
 if (!root)
        return;

    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        Node* current = nodeQueue.front();
        cout << current->value << ' ';

        if (current->left)
            nodeQueue.push(current->left);
        if (current->right)
            nodeQueue.push(current->right);

        nodeQueue.pop();
    }

    cout << endl;
}

void BST::dfs() {
    if (!root) return;

    stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* current = nodeStack.top();
        cout << current->value << ' ';
        nodeStack.pop();

        // Push the right child first, if it exists
        if (current->right)
            nodeStack.push(current->right);

        // Push the left child, if it exists
        if (current->left)
            nodeStack.push(current->left);
    }

    cout << endl;
}

int main(int argc, char* argv[]){
    BST *bst = new BST(25);

	Node* aux = bst->search(25);

	aux = bst->search(30);

	bst->insert(20);
	bst->insert(34);
	bst->insert(2);
	bst->insert(22);
	bst->insert(30);
	bst->insert(40);

    bst->showTree(bst->root);

    cout << "Removing 20: \n";

	bst->remove(20);

    bst->showTree(bst->root);

    cout << "BFS with queue: \n";
    bst->levelorder();

    cout << "DFS with stack: \n";
    bst->dfs();
    return 0;
}