#include <iostream>

template <typename T>
struct node {
  T data;
  node* parent;
  node* left;
  node* right;

  node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class bst {
 private:
  node<T>* root;

 public:
  bst() { root = nullptr; }

  void insert(node<T>*& root, T value) {
    if (!root) {
      root = new node<T>(value);
      return;
    }

    if (value < root->data) {
      insert(root->left, value);
    } else if (value > root->data) {
      insert(root->right, value);
    }
  }

  void insert(T data) { insert(root, data); }

  void inorderTraversal(node<T>* root) {
    if (root != nullptr) {
      inorderTraversal(root->left);
      std::cout << root->data << " ";
      inorderTraversal(root->right);
    }
  }
  void inorderTraversal() { inorderTraversal(root); }

  bool search(node<T>*& root, T value) {
    if (root == nullptr || root->data == value) {
      return root != nullptr;
    }

    if (root->data < value) {
      search(root->right, value);

    } else if (root->data > value) {
      search(root->left, value);
    }
  }

  bool search(T value) { return search(root, value); }

  void deleteNode(node<T>*& root, T value) {
    if (!root && search(value)) {
      return;
    }

    if (root->data < value) {
      deleteNode(root->right, value);

    } else if (root->data > value) {
      deleteNode(root->left, value);
    } else {
      if (!root->left && !root->right) {
        delete root;
        root = nullptr;

      }

      else if (root->left && !root->right) {
        node<T>* temp = root;
        root = root->left;
        delete temp;

      } else if (root->right && !root->left) {
        node<T>* temp = root;
        root = root->right;
        delete temp;

      } else {
        node<T>* temp = findMin(root);
        root->data = temp->data;
        deleteNode(root->right, temp->data);
      }
    }
  }

  void deleteNode(T value) { deleteNode(root, value); }

  node<T>* findMin(node<T>* root) {
    while (root && root->left) {
      root = root->left;
    }
    return root;
  }
  T findMin() {
    node<T>* temp = (root) ? findMin(root) : nullptr;
    if (temp) {
      return temp->data;
    }
    temp = nullptr;
    delete temp;
  }
};

int main(int argc, char const* argv[]) {
  bst<int> tree;
  tree.insert(6);
  tree.insert(1);
  tree.insert(7);
  tree.insert(5);
  tree.inorderTraversal();
  std::cout << tree.search(7) << "\n";

  tree.deleteNode(1);
  tree.inorderTraversal();
  return 0;
}
