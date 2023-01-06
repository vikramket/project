#include<bits/stdC++.h>
using namespace std;

// A single Node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

// allocation of new tree new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

// Creates Huffman Tree and decode given input text
void createHuffTree(string text)
{
    // count frequency of appearance of each character
    // and store it in a unordered map
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of huffman tree
    priority_queue<Node*, vector<Node*>, comp> pqueue;

    // Create a leaf node for each character and add it to the priority queue.
    for (auto pair: freq) {
        pqueue.push(getNode(pair.first, pair.second, NULL, NULL));
    }

    // do till there is more than one node in the queue
    while (pqueue.size() != 1){
        Node *left = pqueue.top(); pqueue.pop();
        Node *right = pqueue.top(); pqueue.pop();
        int sum = left->freq + right->freq;
        pqueue.push(getNode('\0', sum, left, right));
    }

    // root of huffman tree
    Node* root = pqueue.top();

    // traverse the Huffman Tree and store Huffman Codes in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout <<endl<<"Huffman Codes are :"<<endl<< endl;
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }

    // printing encoded string
    string str = "";
    for (char k: text) {
        str += huffmanCode[k];
    }

    cout <<endl<< "Encoded string is :"<<endl<< str <<endl;

    // decoding when you have tree(root)
    int index = -1;
    cout <<endl<< "Decoded string is: "<<endl;
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
}

// encoder traversing tree and storing data
void encode(Node* root, string str,unordered_map<char, string> &huffmanCode)
{
    if (root == NULL){
        return;
    }

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}



// decoding by traversing the tree(you can also do this without tree by using huffman codes and encoded string)
void decode(Node* root, int &ind, string str)
{
    if (root == NULL) {
        return;
    }

    // found a leaf node
    if (!root->left && !root->right){
        cout << root->ch;
        return;
    }

    index++;

    if (str[ind] =='0'){
        decode(root->left, ind, str);
    }
    else{
        decode(root->right, ind, str);
    }
}

// main function with input
int main()
{
    string text;
    getline(cin,text);
    cout <<endl<< "Original string was :"<<endl << text << endl;
    createHuffTree(text);

    return 0;
}
