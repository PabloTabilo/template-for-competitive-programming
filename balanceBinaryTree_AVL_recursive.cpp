#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    int height = 0;
    int bf = 0;
    Node * left = nullptr;
    Node * right = nullptr;
    Node(int val) : value(val) {}
};

class AVL{
    public:
	Node * root = nullptr;
	AVL(){}

	void update(Node * node){
	    int leftNodeHeight = (!node->left ? -1 : node->left->height);
	    int rightNodeHeight = (!node->right ? -1 : node->right->height);
	    node->height = 1 + max(leftNodeHeight, rightNodeHeight);
	    node->bf = rightNodeHeight - leftNodeHeight;
	}
	
	Node * insert(Node * node, int new_val){
	    //cout << "new_val = " << new_val << endl; 
	    if(!node){
		return new Node(new_val);
	    }
	    //cout << "node->value = " << node->value << endl; 
	    if(new_val < node->value){
		//cout << "go to left node" << endl;
		node->left = insert(node->left, new_val);
	    }else{
		//cout << "go to right node" << endl;
		node->right = insert(node->right, new_val);
	    }

	    update(node);

	    return balance(node);
	}

	void insert(int new_val){
	    root = insert(root, new_val);
	}

	Node * balance(Node * node){
	    if(node->bf == -2){
		
		if(node->left->bf <= 0){
		    return leftLeftCase(node);
		}else{
		    return leftRightCase(node);
		}

	    }else if(node->bf == 2){

		if(node->right->bf >= 0){
		    return rightRightCase(node);
		}else{
		    return rightLeftCase(node);
		}

	    }
	    return node;
	}

	Node * leftLeftCase(Node * node){
	    return rightRotation(node);
	}

	Node * leftRightCase(Node * node){
	    node->left = leftRotation(node->left);
	    return leftLeftCase(node);
	}

	Node * rightRightCase(Node * node){
	    return leftRotation(node);
	}

	Node * rightLeftCase(Node * node){
	    node->right = rightRotation(node);
	    return rightRightCase(node);
	}

	Node * leftRotation(Node * node){
	    Node * newParent = node->right;
	    node->right = newParent->left;
	    newParent->left = node;
	    update(node);
	    update(newParent);
	    return newParent;
	}

	Node * rightRotation(Node * node){
	    Node * newParent = node->left;
	    node->left = newParent->right;
	    newParent->right = node;
	    update(node);
	    update(newParent);
	    return newParent;
	}

	void remove(int val){
	    root = remove(root, val);
	}

	Node * remove(Node * node, int val){
	    
	    if(node->value > val){
		node->left = remove(node->left, val);
	    }
	    else if(node->value < val){
		node->right = remove(node->right, val);
	    }
	    else{
		if(!node->left)
		{
		    return node->right;
		}
		else if(!node->right)
		{
		    return node->left;
		}
		else
		{
		   if(node->left->height > node->right->height)
		   {
		       Node * successor = findMax(node->left);
		       node->value = successor->value;
		       node->left = remove(node->left, successor->value);
		   } 
		   else
		   {
		       Node * successor = findMin(node->right);
		       node->value = successor->value;
		       node->right = remove(node->right, successor->value);

		   }
		}
	    }
	    update(node);
	    return balance(node);
	}
	
	Node * findMin(Node * node){
	    while(!node->left) node = node->left;
	    return node;
	}

	Node * findMax(Node * node){
	    while(!node->right) node = node->right;
	    return node;
	}

	int find_nearest_least(int val){
	    return find_nearest_least(root, val);
	}

	int find_nearest_least(Node * node, int val){
	    if(!node) return -1;
	    int ans = -1;
	    //cout << "node->value = " << node->value << ", val = " << val << endl;
	    if(node->value > val){
		//cout << "go to left" << endl;
		ans = find_nearest_least(node->left, val);
	    }else if(node->value < val){
		//cout << "go to right" << endl;
		ans = find_nearest_least(node->right, val);
	    }else{
		//cout << "found! exists val = " << val << endl;
		return val;
	    }
	    // return nearest node
	    if(ans == -1) return node->value;
	    else{
		//cout << "val, node->value, ans = " << val << ", " << node->value << ", " << ans << endl;
		int diff_c = val - node->value;
		int diff_ans = val - ans;
		if(diff_c < 0){
		    return ans;
		}else if(diff_ans < 0){
		    return node->value;
		}else{
		    if(diff_c < diff_ans){
			return node->value;
		    }
		    return ans;
		}
	    }
	}
};

int main(){
    // not duplicates, but add map freq for save duplicates
    int n, m;
    cin >> n >> m;
    AVL tree_avl;
    unordered_map<int, int> f;
    for(int i=0;i<n;i++){
	int x;
	cin >> x;
	f[x]++;
	if(f[x] == 1){
	    tree_avl.insert(x);
	}
	//cout << endl << "x = " << x << " inserted on AVL" << endl;
    }
    int t;    
    while(m--){
	cin >> t;
	int val = tree_avl.find_nearest_least(t);
	if(val > t){
	    cout << -1 << endl;
	    continue;
	}
	cout << val << endl;
	f[val]--;
	if(f[val] == 0){
	    tree_avl.remove(val);
	}
    }
    return 0;
}
