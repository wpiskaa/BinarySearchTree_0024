#include <iostream>
using namespace std;

class node {
public:
    int info;
    node *leftchild;
    node *rightchild;

    // Konstruktor class node
    node() {
        leftchild = nullptr;
        rightchild = nullptr;
    }
};

class BinaryTree {
public:
    node *ROOT;

    BinaryTree() {
        ROOT = nullptr;
    }

    // Fungsi untuk mencari node dan parent-nya
    void search(int element, node* &parent, node* &currentNode) {
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element)) {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }
// Tambahkan fungsi insert dengan pengecekan duplikat
    void insert() {
        int x;
        cout << "Masukkan nilai: ";
        cin >> x;

        node *parent, *currentNode;
        search(x, parent, currentNode);

        // Cegah duplikat
        if (currentNode != nullptr) {
            cout << "Nilai sudah ada di dalam tree.\n";
            return;
        }

        // Step 1 & 2: Buat dan isi nilai ke newNode
        node *newNode = new node();
        newNode->info = x;

        if (parent == nullptr) {
            ROOT = newNode;
            return;
        }

        if (x < parent->info)
            parent->leftchild = newNode;
        else
            parent->rightchild = newNode;
    }
// Tambahkan fungsi traversal inorder pada Binary Tree
    void inorder(node *ptr) {
        if (isEmpty()) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }
// Tambahkan fungsi traversal preorder pada Binary Tree
    void preorder(node *ptr) {
        if (isEmpty()) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
// Tambahkan fungsi traversal postorder pada Binary Tree
    void postorder(node *ptr) {
        if (isEmpty()) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " ";
    }

    bool isEmpty() {
        return ROOT == nullptr;
    }
};


int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}