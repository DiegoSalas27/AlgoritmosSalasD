template<class T>
struct Node{
	T element;
	Node *left;
	Node *right;
	int height;
public:
	Node(){
		height = 0;
		left = nullptr;
		right = nullptr;
	}
};
template<class T>
class BinaryTree{
	Node<T>* root;
	void(*process)(T);
	int(*compare)(T, T);
	int len;

	bool _insert(Node<T>*& node, T e){
		if (node == nullptr){
			node = new Node<T>();
			node->element = e;
			len++;	
		}
		else if (compare(e, node->element) < 0){
			_insert(node->left, e);
		}
		else
			_insert(node->right, e);

		int hi = _heightTree(node->left);
		int hd = _heightTree(node->right);
		node->height = 1 + (hi > hd ? hi : hd);
		return true;
	}
	int _heightTree(Node<T>* node){
		if (node == nullptr) return -1;
		return node->height;
	}
	T _seach(Node<T>* node, T e){
		if (node == NULL) return 0;
		if (compare(e, node->element) == 0)
			return node->element;
		else
			return _seach(compare(e, node->element) > 0 ? node->right : node->left, e);
	}
	void _inOrder(Node<T>* node){
		if (node == nullptr) return;
		_inOrder(node->left);
		process(node->element);
		_inOrder(node->right);
	}
public:
	BinaryTree(void(*process)(T), int(*compare)(T, T)){
		this->process = process;
		this->compare = compare;
		root = nullptr;
		len = 0;
	}
	bool insert(T e){
		 return _insert(root, e);
	}
	void inOrder(){
		_inOrder(root);
	}
	int height(){
		return _heightTree(root);
	}
	T search(T e){
		return _seach(root, e);
	}
	int size(){ return len; }
};