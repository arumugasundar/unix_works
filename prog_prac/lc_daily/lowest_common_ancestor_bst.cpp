#include<iostream>
#include<fstream>
using namespace std;

class node{
	public:
		int data;
		node *lchild;
		node *rchild;
};

class bst{
	public:
		node *root;

		bst();
		void insert(int val);
		node* lowest_common_ancestor(node* root,int p,int q);
};

bst::bst(){
	root = NULL;
}

void bst::insert(int val){
	node *parent,*temp,*I;
	I = new node;
	I->data = val;
	I->lchild = NULL;
	I->rchild = NULL;

	parent = NULL;
	temp = root;
	while(temp!=NULL){
		parent = temp;
		if(I->data > temp->data)
			temp = temp->rchild;
		else
			temp = temp->lchild;
	}
	if(parent==NULL)
		root=I;
	else{
		if(I->data > parent->data)
			parent->rchild = I;
		else
			parent->lchild = I;
	}
}

node* bst::lowest_common_ancestor(node* root,int p,int q){
	if(root->data > p && root->data > q)
		return lowest_common_ancestor(root->lchild,p,q);
	else if(root->data < p && root->data < q)
		return lowest_common_ancestor(root->rchild,p,q);
	else
		return root;
}

int main(){
	fstream input_file, output_file;
	string word;
	input_file.open("input.txt");
	if(input_file){
		bst tree;
		string n_str;
		input_file>>n_str;
		int n = stoi(n_str);
		string temp_str;
		for(int i=0;i<n;i++){
			input_file>>temp_str;
			if(temp_str != "null"){
				int temp = stoi(temp_str);
				tree.insert(temp);
			}
		}
		string p_str,q_str;
		int p,q;
		input_file>>p_str;
		input_file>>q_str;
		p = stoi(p_str);
		q = stoi(q_str);

		node* result = tree.lowest_common_ancestor(tree.root,p,q);
		cout<<"The lowest common ancestor of "<<p<<" and "<<q<<" is "<<result->data<<endl;

		output_file.open("output.txt");
		if(output_file){
			output_file<<result->data;
			output_file.close();
		}
		else
			cout<<"Output File Not Found";

		input_file.close();
	}
	else
		cout<<"Input File Not Found";
	return 0;
}
