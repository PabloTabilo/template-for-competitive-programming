#include <bits/stdc++.h>
using namespace std;

using ll = long long;


ll target = 0;
vector<string> nums;
bool found = false;

struct TreeNode{
    string val;
    TreeNode(string val) : val(val){};
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
};

ll evaluate(TreeNode * root){
    if(!root->left && !root->right){
	return stoll(root->val);
    }
    ll leftVal = evaluate(root->left);
    ll rightVal = evaluate(root->right);
    if(root->val == "+"){
	return leftVal + rightVal;
    }else if(root->val == "*"){
	return leftVal * rightVal;
    }
    return 0;
}

void buildExpression(TreeNode * root, int i){
    if(found) return;

    if(i == nums.size()){
	if(evaluate(root) == target){
	    found = true;
	}
	return;
    }
    
    TreeNode * plusMe = new TreeNode("+");
    plusMe->left = root;
    plusMe->right = new TreeNode(nums[i]);
    buildExpression(plusMe, i+1);

    TreeNode * multiMe = new TreeNode("*");
    multiMe->left = root;
    multiMe->right = new TreeNode(nums[i]);
    buildExpression(multiMe, i+1);
}

bool isPossibleTarget(string input){
    stringstream ss(input);
    string t, numsStr;
    getline(ss, t, ':');
    getline(ss, numsStr);
    
    target = stoll(t);
    
    //cout << "target = " << target << endl;

    stringstream ssNums(numsStr);
    string num;
    while(ssNums >> num){
	nums.push_back(num);
    }
    
    //cout << "nums:"; for(auto x : nums) cout << x << " "; cout << endl;

    found = false;
    
    TreeNode * root = new TreeNode(nums[0]);
    buildExpression(root, 1);
    
    nums.clear();
    
    return found;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<string> operators;
    {
	string line;
	while(true){
	    if(!getline(cin, line)) break;
	    operators.push_back(line);
	}
    } 
    ll ans = 0;
    for(string ope : operators){
	//cout << "ope = " << ope << endl;
	if(isPossibleTarget(ope)){
	    ans += target;
	}
    }
    cout << ans << endl;
    return 0;
}

