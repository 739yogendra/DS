#include <iostream>
using namespace std;

struct Lnode
{
	int low, high;
	struct Lnode *left, *right, *parent;
};

// A utility function to create a new BST node
struct Lnode *LnewNode(int L,int H)
{
	struct Lnode *temp = new Lnode;
	temp->low = L;
	temp->high = H;
	temp->left = NULL;
	temp->right = NULL;
	//temp->parent = NULL;
	return temp;
}

/* A utility function to insert a new node with given key in BST */
struct Lnode* Linsert(struct Lnode* Lnode, int low, int high)
{
	/* If the tree is empty, return a new node */
	if (Lnode == NULL) return LnewNode(low,high);

	/* Otherwise, recur down the tree */
	if (low < Lnode->low)
		Lnode->left = Linsert(Lnode->left, low, high);
	else if (low > Lnode->low)
		Lnode->right = Linsert(Lnode->right, low, high);

	/* return the (unchanged) node pointer */
	return Lnode;
}

void Linorder(struct Lnode *Lroot)
{
	if (Lroot != NULL)
	{
		Linorder(Lroot->left);
		printf("%d %d\n", Lroot->low, Lroot->high);
		Linorder(Lroot->right);
	}
}



struct Hnode
{
	int low, high;
	struct Hnode *left, *right, *parent;
};

// A utility function to create a new BST node
struct Hnode *HnewNode(int L,int H)
{
	struct Hnode *temp = new Hnode;
	temp->low = L;
	temp->high = H;
	temp->left = NULL;
	temp->right = NULL;
	//temp->parent = NULL;
	return temp;
}

/* A utility function to insert a new node with given key in BST */
struct Hnode* Hinsert(struct Hnode* Hnode, int low, int high)
{
	/* If the tree is empty, return a new node */
	if (Hnode == NULL) return HnewNode(low,high);

	/* Otherwise, recur down the tree */
	if (high < Hnode->high)
		Hnode->left = Hinsert(Hnode->left, low, high);
	else if (high > Hnode->high)
		Hnode->right = Hinsert(Hnode->right, low, high);

	/* return the (unchanged) node pointer */
	return Hnode;
}

void Hinorder(struct Hnode *Hroot)
{
	if (Hroot != NULL)
	{
		Hinorder(Hroot->left);
		printf("%d %d\n", Hroot->low, Hroot->high);
		Hinorder(Hroot->right);
	}
}

int min(struct Lnode *Lroot){
    struct Lnode* temp = Lroot;
    //int Min[1000],i=0;
    while(temp->left!=NULL){
        //Min[i++]=tempp->low;
        temp=temp->left;
    }
    return temp->low;
}

int max(struct Hnode *Hroot){
    struct Hnode* temp = Hroot;
    //int Min[1000],i=0;
    while(temp->right!=NULL){
        //Min[i++]=tempp->low;
        temp=temp->right;
    }
    return temp->high;
}

int main() {
	int M;
	cin>>M;
	while(M){
	    int N;
	    cin>>N;

	    struct Lnode *Lroot = NULL;
	    struct Hnode *Hroot = NULL;

	    for(int i=0;i<N;i++){
	        char op[10];
	        cin>>op;

	        if(op[0]=='+'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            //cout<<low;
	            //cout<<high<<endl;
	            Lroot = Linsert(Lroot,low,high);
	            Hroot = Hinsert(Hroot,low,high);
	        }

	        else if(op[0]=='-'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            //cout<<low;
	            //cout<<high<<endl;
	            //Linsert(Lroot,low,high);
	            //Hinsert(Hroot,low,high);
	        }

	        else if(op[2]=='n'){
	            cout<<min(Lroot)<<endl;
	        }

	        else if(op[2]=='x'){
	            cout<<max(Hroot)<<endl;
	        }

	        else if(op[0]=='l'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            //Lsucc(Lroot,low,high);
	        }

	        else if(op[0]=='h'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            //Hsucc(Hroot,low,high);
	        }

	        else if(op[0]=='o'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            //Overlap(Lroot,low,high);
	        }

	    }

	    Linorder(Lroot);
	    Hinorder(Hroot);

	    M--;
	}
	return 0;
}
