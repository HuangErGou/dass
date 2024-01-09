#include <iostream>
#include <queue>

template <typename T>
class BTreeNode {
 public:
  BTreeNode() : _left_child(nullptr), _right_child(nullptr) {}
  BTreeNode(const T &element) {
    _element = element;

    _left_child = nullptr;
    _right_child = nullptr;
  }
  BTreeNode(const T &element, BTreeNode *left_child, BTreeNode *right_child) {
    _element = element;

    _left_child = nullptr;
    _right_child = nullptr;
  }

 public:
  T _element;
  BTreeNode *_left_child = nullptr;
  BTreeNode *_right_child = nullptr;
};

template <typename T>
class BTreeInf {
 public:
  virtual ~BTreeInf() {}
  virtual bool empty() const = 0;
  virtual size_t size() const = 0;
  virtual void preOrder(void (*)(BTreeNode<T> *), BTreeNode<T> *) = 0;
  virtual void midOrder(void (*)(BTreeNode<T> *), BTreeNode<T> *) = 0;
  virtual void postOrder(void (*)(BTreeNode<T> *), BTreeNode<T> *) = 0;
};

template <typename T>
class BTree : public BTreeInf<T> {
 public:
  BTree() {
    _root = nullptr;
    _size = 0;
  }

  ~BTree() { erase(); }

  BTree(const BTree<T> &tree) {
    _root = copy(tree._root);
    _size = tree._size;
  }

  bool empty() const override { return _size == 0; }

  size_t size() const override { return _size; }

  void preOrder(void (*visit)(BTreeNode<T> *), BTreeNode<T> *n) override {
    if (nullptr == n || nullptr == visit) return;

    visit(n);
    preOrder(visit, n->_left_child);
    preOrder(visit, n->_right_child);
  }

  void midOrder(void (*visit)(BTreeNode<T> *), BTreeNode<T> *n) override {
    if (nullptr == n || nullptr == visit) return;

    midOrder(visit, n->_left_child);
    visit(n);
    midOrder(visit, n->_right_child);
  }

  void postOrder(void (*visit)(BTreeNode<T> *), BTreeNode<T> *n) override {
    if (nullptr == n || nullptr == visit) return;

    postOrder(visit, n->_left_child);
    postOrder(visit, n->_right_child);
    visit(n);
  }

  void erase() {
    postOrder(dispose, _root);

    _root = nullptr;
    _size = 0;
  }

  void insert(const T &e) {
    if (nullptr == _root) {
      _root = new BTreeNode<T>(e);
      _size++;
      return;
    }

    BTreeNode<T> *current_node = _root;
    while (current_node != nullptr) {
      if (e <= current_node->_element) {
        if (current_node->_left_child != nullptr) {
          current_node = current_node->_left_child;
        } else {
          current_node->_left_child = new BTreeNode<T>(e);
          _size++;
          break;
        }
      } else {
        if (current_node->_right_child != nullptr) {
          current_node = current_node->_right_child;
        } else {
          current_node->_right_child = new BTreeNode<T>(e);
          _size++;
          break;
        }
      }
    }
  }

  size_t depth() const { return depth(_root); }

  size_t depth(BTreeNode<T> *node) const {
    if (nullptr == node) return 0;

    size_t l = depth(node->_left_child);
    size_t r = depth(node->_right_child);
    if (l > r) return ++l;
    return ++r;
  }

  void level_order() { level_order(_root); }

  void level_order(BTreeNode<T> *node) {
    std::queue<BTreeNode<T> *> queue;

    while (node != nullptr) {
      std::cout << node->_element << " ";

      if (node->_left_child != nullptr) {
        queue.push(node->_left_child);
      }
      if (node->_right_child != nullptr) {
        queue.push(node->_right_child);
      }

      if (queue.empty()) break;
      node = queue.front();
      queue.pop();
    }
    std::cout << std::endl;
  }

 private:
  BTreeNode<T> *_root = nullptr;
  size_t _size = 0;

 private:
  static void dispose(BTreeNode<T> *n) {
    if (nullptr == n) return;

    delete n;
    n = nullptr;
  }

  static BTreeNode<T> *copy(BTreeNode<T> *from) {
    if (from == nullptr) return nullptr;

    BTreeNode<T> *node = nullptr;
    node = new BTreeNode(from->_element);
    node->_left_child = copy(from->_left_child);
    node->_right_child = copy(from->_right_child);
    return node;
  }
};

int main(int argc, char const *argv[]) {
  BTree<int> tree;
  tree.insert(3);
  tree.insert(2);
  tree.insert(4);
  tree.insert(1);

  std::cout << "depth is:" << tree.depth() << std::endl;
  tree.level_order();

  BTree<int> tree2(tree);
  tree2.level_order();
  return 0;
}
