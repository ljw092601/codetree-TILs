#include <iostream>
using namespace std;

class Order{
	private:
	int orderID;
	string customerName;
	int orderAmount;
	friend class Tree;
	friend class Node;
	public:
	Order(int id, string name, int amount) : orderID(id), customerName(name), orderAmount(amount) {}
	bool operator< (Order other) {
		return this->orderID < other.orderID;
	}
    Order() : orderID(-1), customerName("\0"), orderAmount(0) {}
    friend ostream& operator<< (ostream& os, Order order) {
        os << order.orderID << " - Name : " << order.customerName << " Amount : " << order.orderAmount;
        return os;
    }
};

class Node {
	private:
	Order val;
	Node* left;
	Node* right;
	friend class Tree;
	public:
	Node(Order order) : val(order) {
		left = nullptr;
		right = nullptr;
	}
};

class Tree {
	private:
	Node* root;
    void print_order(Node* cur) {
        if(cur == nullptr) return;
        print_order(cur->left);
        cout << cur->val << endl;
        print_order(cur->right);
    }
	public:
	Tree() {root = nullptr;}
	void add(Order order) {
		Node* new_node = new Node(order);
		if (root == nullptr) {
			root = new_node;
			return;
		}
		Node* cur = root;
		Node* parent;
		bool left_child;
		while(cur != nullptr) {
			if (cur->val < new_node->val) {
				parent = cur;
				cur = parent->right;
				left_child = false;
			}
			else {
				parent = cur;
				cur = parent->left;
				left_child = true;
			}
		}
		if (left_child) parent->left = new_node;
		else parent->right = new_node;
	}
	
	Order search(int id) {
		if (root == nullptr) return Order();
		Node* cur = root;
		while(cur != nullptr) {
            if (cur->val.orderID == id) return cur->val;
            if (cur->val.orderID < id) cur = cur->right;
            else cur = cur->left;
        }
        return Order();
	}

    bool del(int id) {
        if (root == nullptr) return false;
		Node* cur = root;
        Node* parent = nullptr;
        bool left_child;
		while(cur != nullptr) {
            if (cur->val.orderID == id) break;
            if (cur->val.orderID < id) {
                parent = cur;
                cur = cur->right;
                left_child = false;
            }
            else {
                parent = cur;
                cur = cur->left;
                left_child = true;
            }
        }
        if (cur == nullptr) return false;
        if (parent == nullptr) {
            root = nullptr;
            return true;
        }
        if (cur->right == nullptr) {
            if (left_child) {
                parent->left = cur->left;
            }
            else {
                parent->right = cur->left;
            }
        }
        else if (cur->left == nullptr) {
            if (left_child) {
                parent->left = cur->right;
            }
            else {
                parent->right = cur->right;
            }
        }
        else {
            Node* change = cur->right;
            Node* change_parent = nullptr;
            while(change->left != nullptr) {
                change_parent = change;
                change = change->left;
            }
            if (change_parent != nullptr) {
                change_parent->left = change->right;
                if (left_child) {
                    parent->left = change;
                }
                else {
                    parent->right = change;
                }
                change->left = cur->left;
                change->right = cur->right;
            }
            else {
                if (left_child) {
                    parent->left = change;
                }
                else {
                    parent->right = change;
                }
                change->left = cur->left;
            }
        }
        delete cur;
        return true;
    }

    void print() {
        print_order(root);
    }
};

int main() {
		
	return 0;
}