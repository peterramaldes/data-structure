#include <iostream>

using namespace std;

class Node {
  private: 
    Node *left, *right;
    int value;

  public: 
    Node(int value);
    Node* getLeft();
    void setLeft(Node* node);
    Node* getRight();
    void setRight(Node* node);
    int getValue();
    void setValue(int value);
};

Node::Node(int value) {
  left = NULL;
  right = NULL;
  this->value = value;
}

Node* Node::getLeft() {
  return left;
}

void Node::setLeft(Node* node) {
  left = node;
}

Node* Node::getRight() {
  return right;
}

void Node::setRight(Node* node) {
  right = node;
}

int Node::getValue() {
  return value;
}

void Node::setValue(int value) {
  this->value = value;
}

class Tree {
  private: 
    Node* root;
    void insertAux(Node* node, int value);

  public: 
    Tree();
    void insert(int value);
    void preOrder(Node* node);
    void inOrder(Node* node);
    void posOrder(Node* node);
    Node* getRoot();
};

Tree::Tree() {
  root = NULL;
}

void Tree::insertAux(Node* node, int value) {
    if (value > node->getValue()) {
      if (node->getRight() == NULL) {
        Node* new_node = new Node(value);
        node->setRight(new_node);
      } else
          insertAux(node->getRight(), value);
    }

    if (value < node->getValue()) {
      if (node->getLeft() == NULL) {
        Node* new_node = new Node(value);
        node->setLeft(new_node);
      } else
          insertAux(node->getLeft(), value);
    }
}

void Tree::insert(int value) {
  if (root == NULL)
    root = new Node(value);
  else 
    insertAux(root, value);
}

void Tree::preOrder(Node* node) {
  cout << "value: " << node->getValue() << endl;
  
  if (node->getLeft() != NULL)
    preOrder(node->getLeft());

  if (node->getRight() != NULL)
    preOrder(node->getRight());
}

Node* Tree::getRoot() {
  return root;
}

int main() {
  Tree *tree = new Tree();
  tree->insert(7);
  tree->insert(14);
  tree->insert(5);
  tree->insert(28);
  tree->insert(6);
  tree->insert(4);

  tree->preOrder(tree->getRoot());

  return 0;
}

