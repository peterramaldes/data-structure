#include <iostream>

using namespace std;

class Node
{
  private: 
    Node *left, *right;
    int value;

  public: 
    Node(int value);
    Node* get_left();
    void set_left(Node* node);
    Node* get_right();
    void set_right(Node* node);
    int get_value();
    void set_value(int value);
};

Node::Node(int value)
{
  left = NULL;
  right = NULL;
  this->value = value;
}

Node* Node::get_left() 
{
  return left;
}

void Node::set_left(Node* node) 
{
  left = node;
}

Node* Node::get_right() 
{
  return right;
}

void Node::set_right(Node* node) 
{
  right = node;
}

int Node::get_value() 
{
  return value;
}

void Node::set_value(int value) 
{
  this->value = value;
}

class Tree
{
  private: 
    Node* root;
    void insert_aux(Node* node, int value);

  public: 
    Tree();
    void insert(int value);
    void delete_elem(); // Melhorar esse nodeme
    void find();
    void pre_order(Node* node);
    void in_order(Node* node);
    void pos_order(Node* node);
    Node* get_root();
};

Tree::Tree()
{
  root = NULL;
}

void Tree::insert_aux(Node* node, int value)
{
    if (value > node->get_value())
    {
      // TODO: Criar uma função insert_right?
      if (node->get_right() == NULL) 
      {
        Node* new_node = new Node(value);
        node->set_right(new_node);
      }
      else
        insert_aux(node->get_right(), value);
    }

    // TODO: ELSE? E se for igual?
    if (value < node->get_value())
    {
      // TODO: Criar uma função insert_left?
      if (node->get_left() == NULL) 
      {
        Node* new_node = new Node(value);
        node->set_left(new_node);
      }
      else
        insert_aux(node->get_left(), value);
    }

}

void Tree::insert(int value) 
{
  if (root == NULL)
    root = new Node(value);
  else 
    insert_aux(root, value);
}

void Tree::delete_elem() 
{
  // TODO
}

void Tree::find() 
{
  // TODO
}

void Tree::pre_order(Node* node) {
  cout << "value: " << node->get_value() << endl;
  
  if (node->get_left() != NULL)
    pre_order(node->get_left());

  if (node->get_right() != NULL)
    pre_order(node->get_right());
}

Node* Tree::get_root() {
  return root;
}

int main()
{
  Tree *tree = new Tree();
  tree->insert(7);
  tree->insert(14);
  tree->insert(5);
  tree->insert(28);
  tree->insert(6);
  tree->insert(4);
  tree->pre_order(tree->get_root());
  return 0;
}

