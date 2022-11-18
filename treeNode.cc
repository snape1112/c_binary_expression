#include "treeNode.h"

TreeNode::TreeNode(std::string cntt): content {cntt} {}

std::string TreeNode::getContent() const {
  // your code starts here
  return content;
}

TreeNode *TreeNode::getLeftChild() const {
  // your code starts here
  return leftChild;
}
TreeNode *TreeNode::getRightChild() const {
  // your code starts here
  return rightChild;
}

void TreeNode::updateLeftChild(TreeNode *lChild) {
  // your code starts here
  leftChild = lChild;

}

void TreeNode::updateChildren(TreeNode *lChild, TreeNode *rChild) {
  // your code starts here
  leftChild = lChild;
  rightChild = rChild;
}

OperatorNode::OperatorNode(std::string cntt): TreeNode{cntt} {}

bool OperatorNode::evaluate(const std::map<std::string, bool> &assignment) const {
  // your code starts here
  bool left = getLeftChild()->evaluate(assignment);
  std::string content = getContent();
  if (content == "-") {
    return !left;
  } else {
    bool right = getRightChild()->evaluate(assignment);
    if (content == "+")
      return left | right;
    else
      return left & right;
  }
}

ConstantNode::ConstantNode(std::string cntt): TreeNode{cntt} {}

bool ConstantNode::evaluate(const std::map<std::string, bool> &assignment) const {
  // your code starts here
  return getContent() == "1";
}

VariableNode::VariableNode(std::string cntt): TreeNode{cntt} {}

bool VariableNode::evaluate(const std::map<std::string, bool> &assignment) const {
  // your code starts here
  std::string content = getContent();
  if (assignment.find(content) == assignment.end())
    throw std::runtime_error("incomplete assignment");
  return assignment.at(content);
}

TreeNode::~TreeNode() {
  // your code starts here
}
