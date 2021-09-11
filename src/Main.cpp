#include <iostream>
#include <vector>

class Visitor;

struct Node {
  virtual void getType() {}
  virtual int accept(Visitor * v);
};

// Integer: 10, 20...
struct IntegerLiteral : Node {
  int value;
  virtual int accept(Visitor * v);
};

// AddExpression: LeftNode  RightNode
struct AddExpression : Node {
  Node *left, *right;
  virtual int accept(Visitor * v);
};

// SubExpression: LeftNode  RightNode
struct SubExpression : Node {
  Node *left, *right;
  virtual int accept(Visitor * v);
};

// MulExpression: LeftNode  RightNode
struct MulExpression : Node {
  Node *left, *right;
  virtual int accept(Visitor * v);
};

// DivExpression: LeftNode  RightNode
struct DivExpression : Node {
  Node *left, *right;
  virtual int accept(Visitor * v);
};

class Visitor {
  public:
  
  int visit(Node * node);
  
  int visit(IntegerLiteral * node);

  int visit(AddExpression * node);

  int visit(SubExpression * node);

  int visit(MulExpression * node);

  int visit(DivExpression * node);
};

int Node::accept(Visitor * v) {
  return v->visit(this);
}

int IntegerLiteral::accept(Visitor * v) {
  return v->visit(this);
}

int AddExpression::accept(Visitor * v) {
  return v->visit(this);
}

int SubExpression::accept(Visitor * v) {
  return v->visit(this);
}

int MulExpression::accept(Visitor * v) {
  return v->visit(this);
}

int DivExpression::accept(Visitor * v) {
  return v->visit(this);
}



int Visitor::visit(Node * node) {
  return -1;
}

int Visitor::visit(IntegerLiteral * node) {
  return node->value;
}

int Visitor::visit(AddExpression * node) {
  int leftVal = node->left->accept(this);
  int rightVal = node->right->accept(this);
  return leftVal + rightVal;
}

int Visitor::visit(SubExpression * node) {
  int leftVal = node->left->accept(this);
  int rightVal = node->right->accept(this);
  return leftVal - rightVal;
}

int Visitor::visit(MulExpression * node) {
  int leftVal = node->left->accept(this);
  int rightVal = node->right->accept(this);
  return leftVal * rightVal;
}

int Visitor::visit(DivExpression * node) {
  int leftVal = node->left->accept(this);
  int rightVal = node->right->accept(this);
  return leftVal / rightVal;
}


// Program AST
// > 1 + 2
// > (3 - 1) + 5
// > (5 / (10 - 5))
std::vector<Node*> demoProgram() {
  std::vector<Node*> lines;

  // line 1
  Node* line1 = new AddExpression();
  
  Node* line1_leftOpe = new IntegerLiteral();
  ((IntegerLiteral*)line1_leftOpe)->value = 1;

  Node* line1_rightOpe = new IntegerLiteral();
  ((IntegerLiteral*)line1_rightOpe)->value = 2;

  ((AddExpression*)line1)->left = line1_leftOpe;

  ((AddExpression*)line1)->right = line1_rightOpe;

  // line 2
  Node* line2 = new AddExpression();
  
  Node* line2_leftOpe = new SubExpression();
  
  Node* line2_11 = new IntegerLiteral();
  ((IntegerLiteral*)line2_11)->value = 3;

  Node* line2_12 = new IntegerLiteral();
  ((IntegerLiteral*)line2_12)->value = 1;

  ((SubExpression*)line2_leftOpe)->left = line2_11;
  ((SubExpression*)line2_leftOpe)->right = line2_12;
  
  Node* line2_rightOpe = new IntegerLiteral();
  ((IntegerLiteral*)line2_rightOpe)->value = 5;

  ((AddExpression*)line2)->left = line2_leftOpe;

  ((AddExpression*)line2)->right = line2_rightOpe;

  // line 3
  Node* line3 = new DivExpression();
  Node* line3_leftOpe = new IntegerLiteral();
  
  ((IntegerLiteral*)line3_leftOpe)->value = 5;

  Node* line3_rightOpe = new SubExpression();

  Node* line3_11 = new IntegerLiteral();
  ((IntegerLiteral*)line3_11)->value = 10;

  Node* line3_12 = new IntegerLiteral();
  ((IntegerLiteral*)line3_12)->value = 5;

  ((SubExpression*)line3_rightOpe)->left = line3_11;
  ((SubExpression*)line3_rightOpe)->right = line3_12;

  ((AddExpression*)line3)->left = line3_leftOpe;

  ((AddExpression*)line3)->right = line3_rightOpe;


  lines.push_back(line1);
  lines.push_back(line2);
  lines.push_back(line3);

  return lines;
}

int main() {
  std::vector<Node*> program = demoProgram();
  Visitor* v = new Visitor();
  for (auto & node : program) {
    std::cout << node->accept(v) << std::endl;
  }

}