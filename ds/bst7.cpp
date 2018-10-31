#include <bits/stdc++.h>
using namespace std;

struct Lnode
{
	int low, high,max=0;
	struct Lnode *left, *right, *parent;
};


struct Lnode *LnewNode(int L,int H)
{
	struct Lnode *temp = new Lnode;
	temp->low = L;
	temp->high = H;
	temp->max=H;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}


struct Lnode* Linsert(struct Lnode* Lnode, int low, int high)
{

	if (Lnode == NULL) return LnewNode(low,high);


	if (low < Lnode->low) {
		Lnode->left = Linsert(Lnode->left, low, high);
		Lnode->left->parent = Lnode;
	}
	else if (low > Lnode->low) {
	    Lnode->right = Linsert(Lnode->right, low, high);
		Lnode->right->parent = Lnode;
	}

    if (Lnode->max < high)
        Lnode->max = high;

	return Lnode;
}

int maximum(int a,int b,int c){
    if(a>=b&&a>=c)
    return a;
    else if(a<=b&&b>=c)
    return b;
    else
    return c;
}

int Maxfix(struct Lnode* Lroot){
    if(Lroot==NULL)
    return 0;

    else if(Lroot->left==NULL&&Lroot->right==NULL)
    return Lroot->max;

    else{
        Lroot->max = maximum(Maxfix(Lroot->left),Maxfix(Lroot->right),Lroot->high);
    }
}

struct Lnode* Ldelete(struct Lnode* Lroot, int L, int H){
        if(Lroot == NULL)
        return Lroot;

        if(L>Lroot->low){
        //path.push_back(Lroot);
        Lroot->right = Ldelete(Lroot->right,L,H);

        }
        else if(L<Lroot->low){
        //path.push_back(Lroot);
        Lroot->left = Ldelete(Lroot->left,L,H);
        }
        else{

            if((Lroot->left == NULL)&&(Lroot->right == NULL)){
               delete Lroot;
               return NULL;
            }

            if(Lroot->left == NULL){
                struct Lnode* temp = Lroot->right;
                delete Lroot;
                return temp;
            }
            else if(Lroot->right == NULL){
                struct Lnode* temp = Lroot->left;
                delete Lroot;
                return temp;
            }

            struct Lnode* current = Lroot->right;
            while(current->left!=NULL){
                //path.push_back(current);
                current = current->left;
            }

            Lroot->low = current->low;
            Lroot->high = current->high;

            Lroot->right = Ldelete(Lroot->right,current->low,current->high);

        }
        return Lroot;
    }


int overlap(struct Lnode* Lnode, int L, int H){

    if(Lnode == NULL)
    return -1;

    if((Lnode->low<L&&Lnode->high>H)||(Lnode->low>L&&Lnode->high<H)||(Lnode->high<H&&Lnode->high>L)||(Lnode->low>L&&Lnode->low<H))
    return 1;

    if(Lnode->left!=NULL&&Lnode->left->max>L)
    return overlap(Lnode->left,L,H);

    else{
        if(Lnode->right!=NULL)
        return overlap(Lnode->right,L,H);
    }

    return 0;
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
	temp->parent = NULL;
	return temp;
}

/* A utility function to insert a new node with given key in BST */
struct Hnode* Hinsert(struct Hnode* Hnode, int low, int high)
{
	/* If the tree is empty, return a new node */
	if (Hnode == NULL) return HnewNode(low,high);

	/* Otherwise, recur down the tree */
	if (high < Hnode->high){
		Hnode->left = Hinsert(Hnode->left, low, high);
		Hnode->left->parent = Hnode;
	}
	else if (high > Hnode->high){
		Hnode->right = Hinsert(Hnode->right, low, high);
		Hnode->right->parent = Hnode;
	}

	/* return the (unchanged) node pointer */
	return Hnode;
}



/*void Linorder(struct Lnode *Lroot)
{
	if (Lroot != NULL)
	{
		Linorder(Lroot->left);
		printf("%d %d %d\n", Lroot->low, Lroot->high, Lroot->max);
		Linorder(Lroot->right);
	}
}


void Hinorder(struct Hnode *Hroot)
{
	if (Hroot != NULL)
	{
		Hinorder(Hroot->left);
		printf("%d %d\n", Hroot->low, Hroot->high);
		Hinorder(Hroot->right);
	}
}*/


struct Hnode* Hdelete(struct Hnode* Hroot, int L, int H){
        if(Hroot == NULL)
        return Hroot;

        if(H>Hroot->high){
        Hroot->right = Hdelete(Hroot->right,L,H);
        }
        else if(H<Hroot->high){
        Hroot->left = Hdelete(Hroot->left,L,H);
        }
        else{

            if((Hroot->left == NULL)&&(Hroot->right == NULL)){
               delete Hroot;
               return NULL;
            }

            if(Hroot->left == NULL){
                struct Hnode* temp = Hroot->right;
                delete Hroot;
                return temp;
            }
            else if(Hroot->right == NULL){
                struct Hnode* temp = Hroot->left;
                delete Hroot;
                return temp;
            }

            struct Hnode* current = Hroot->right;
            while(current->left!=NULL){
                current = current->left;
            }

            Hroot->low = current->low;
            Hroot->high = current->high;

            Hroot->right = Hdelete(Hroot->right,current->low,current->high);

        }
        return Hroot;
    }

void min(struct Lnode *Lroot){

    if(Lroot == NULL)
    cout<<"INVALID"<<endl;
    else{
        struct Lnode* temp = Lroot;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        cout<<"["<<temp->low<<" "<<temp->high<<"]"<<endl;
    }
}

void max(struct Hnode *Hroot){

    if(Hroot == NULL)
    cout<<"INVALID"<<endl;
    else{
        struct Hnode* temp = Hroot;
    //int Min[1000],i=0;
        while(temp->right!=NULL){
        //Min[i++]=tempp->low;
            temp=temp->right;
        }
        cout<<"["<<temp->low<<" "<<temp->high<<"]"<<endl;
    }
}

int maxL(struct Lnode* Lroot){
    struct Lnode* search = Lroot;
    if(search!=NULL){
        while(search->right!=NULL){
            search = search->right;
        }
        return search->low;
    }

    else
    return 0;
}



void Lsucc(struct Lnode* Lroot, int L){

    if((Lroot == NULL)||(L==maxL(Lroot))){
        cout<<"INVALID"<<endl;
        return;
    }


    else{
        struct Lnode* search = Lroot;

    while((search!=NULL)&&(search->low != L)){
        if(search->low < L){
            search = search->right;
        }

        else{
            search = search->left;
        }
    }

    if(search==NULL){
        cout<<"INVALID"<<endl;
        return;
    }
    else{

    if(search->right!=NULL){
        struct Lnode* prev_current = search->right;
        while(prev_current->left!=NULL){
            prev_current = prev_current->left;
        }
        cout<<"["<<prev_current->low<<" "<<prev_current->high<<"]"<<endl;
    }
    else{
        struct Lnode* current = search->parent;
        //cout<<current->low<<endl;
        //struct Lnode* prev_current = Lroot;

        while((current != NULL)&&(search == current->right)){
           search = current;
           current = current->parent;
        }

        cout<<"["<<current->low<<" "<<current->high<<"]"<<endl;
    }
    }

    }

}

int maxH(struct Hnode* Hroot){
    struct Hnode* search = Hroot;
    if(search!=NULL){
        while(search->right!=NULL){
            search = search->right;
        }
        return search->high;
    }
    else
    return 0;
}


void Hsucc(struct Hnode* Hroot, int H){

    if(Hroot == NULL||(H==maxH(Hroot))){
        cout<<"INVALID"<<endl;
        return;
    }


    else{
        struct Hnode* search = Hroot;

    while((search!=NULL)&&(search->high != H)){
        if(search->high < H){
            search = search->right;
        }

        else{
            search = search->left;
        }
    }

    if(search==NULL){
        cout<<"INVALID"<<endl;
        return;
    }
    else{

    if(search->right!=NULL){
        struct Hnode* prev_current = search->right;
        while(prev_current->left!=NULL){
            prev_current = prev_current->left;
        }
        cout<<"["<<prev_current->low<<" "<<prev_current->high<<"]"<<endl;
    }
    else{
        struct Hnode* current = search->parent;
        //cout<<current->low<<endl;
        //struct Lnode* prev_current = Lroot;

        while((current != NULL)&&(search == current->right)){
           search = current;
           current = current->parent;
        }

        cout<<"["<<current->low<<" "<<current->high<<"]"<<endl;
    }
    }

    }

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

	            Lroot = Linsert(Lroot,low,high);
	            Hroot = Hinsert(Hroot,low,high);
	        }

	        else if(op[0]=='-'){
	            int low,high;
	            cin>>low;
	            cin>>high;


	            Lroot = Ldelete(Lroot,low,high);
	            Hroot = Hdelete(Hroot,low,high);
	        }

	        else if(op[2]=='n'){
	            min(Lroot);
	        }

	        else if(op[2]=='x'){
	            max(Hroot);
	        }

	        else if(op[0]=='l'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            //cout<<low<<" "<<high<<endl;
	            //if(Lroot!=NULL)
	            Lsucc(Lroot,low);
	        }

	        else if(op[0]=='h'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            Hsucc(Hroot,high);
	        }

	        else if(op[0]=='o'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            int val = overlap(Lroot,low,high);
	            if(val == -1)
	            cout<<"INVALID"<<endl;

	            else
	            cout<<val<<endl;
	        }

	    }

	    //Linorder(Lroot);
	    //Hinorder(Hroot);

	    M--;
	}
	return 0;
}
