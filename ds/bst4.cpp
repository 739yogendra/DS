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

void min(struct Lnode *Lroot){
    struct Lnode* temp = Lroot;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    cout<<"["<<temp->low<<" "<<temp->high<<"]"<<endl;
}

void max(struct Hnode *Hroot){
    struct Hnode* temp = Hroot;
    //int Min[1000],i=0;
    while(temp->right!=NULL){
        //Min[i++]=tempp->low;
        temp=temp->right;
    }
    cout<<"["<<temp->low<<" "<<temp->high<<"]"<<endl;
}

void Lsucc(struct Lnode* Lroot, int L, int H){

    struct Lnode* search =Lroot;
    //int Sea=0;
    while(search->low != L){
        if(search->low < L){
            search = search->right;
        }

        else{
            search = search->left;
        }
    }

    if(search->right!=NULL){
        search = search->right;
        cout<<"["<<search->low<<" "<<search->high<<"]"<<endl;
    }
    else{
        struct Lnode* current = Lroot;
        struct Lnode* prev_current = Lroot;

        while(current->low != L){
            if(current->low < L){
                prev_current = current;
                current = current->right;
            }

            else{
                current = current->left;
            }
        }

        cout<<"["<<prev_current->low<<" "<<prev_current->high<<"]"<<endl;
    }

}


void Hsucc(struct Hnode* Hroot, int L, int H){

    struct Hnode* search =Hroot;
    //int Sea=0;
    while(search->high != H){
        if(search->high < H){
            search = search->right;
        }

        else{
            search = search->left;
        }
    }

    if(search->right!=NULL){
        search = search->right;
        cout<<"["<<search->low<<" "<<search->high<<"]"<<endl;
    }
    else{
        struct Hnode* current = Hroot;
        struct Hnode* prev_current = Hroot;

        while(current->high != H){
            if(current->high < H){
                prev_current = current;
                current = current->right;
            }

            else{
                current = current->left;
            }
        }

        cout<<"["<<prev_current->low<<" "<<prev_current->high<<"]"<<endl;
    }

}


void Overlap(struct Lnode* Lroot, int low, int high){
    struct Lnode* interval = Lroot;
    int overLAP=0;
    while(interval != NULL){
        if(high<interval->low){
            interval = interval->left;
        }

        else if(low>interval->high){
            interval = interval->right;
        }
        else{
            cout<<"1"<<endl;
            overLAP=1;
            break;
        }
    }

    if(overLAP==0)
    cout<<"0"<<endl;
}

void Ldelete(struct Lnode* Lroot, int L, int H){
    struct Lnode* prev = Lroot;
    while(prev!=NULL){
        if(L < prev->low){
            Lroot = prev;
            prev = prev->left;
        }

        else if(L > prev->low){
            Lroot = prev;
            prev = prev->right;
        }

        else{
            if((prev->left==NULL)&&(prev->right==NULL)){
                if(prev==Lroot->left)
                delete Lroot->left;

                else
                delete Lroot->right;
            }

            else if(prev->left==NULL){
                struct Lnode* temp = prev->right;
                if(prev==Lroot->left){
                    delete Lroot->left;
                    Lroot->left = temp;
                }


                else{
                    delete Lroot->right;
                    Lroot->right = temp;
                }
            }

            else if(prev->right==NULL){
                struct Lnode* temp = prev->left;
                if(prev==Lroot->left){
                    delete Lroot->left;
                    Lroot->left = temp;
                }


                else{
                    delete Lroot->right;
                    Lroot->right = temp;
                }
            }
        }
    }
}


void Hdelete(struct Hnode* Hroot, int L, int H){
    struct Hnode* prev = Hroot;
    while(prev!=NULL){
        if(H < prev->high){
            Hroot = prev;
            prev = prev->left;
        }

        else if(H > prev->high){
            Hroot = prev;
            prev = prev->right;
        }

        else{
            if((prev->left==NULL)&&(prev->right==NULL)){
                if(prev==Hroot->left){
                    delete Hroot->left;
                    Hroot->left = NULL;
                }


                else{
                    delete Hroot->right;
                    Hroot-> right = NULL;
                }

            }

            else if(prev->left==NULL){
                struct Hnode* temp = prev->right;
                if(prev==Hroot->left){
                    delete Hroot->left;
                    Hroot->left = temp;
                }


                else{
                    delete Hroot->right;
                    Hroot->right = temp;
                }
            }

            else if(prev->right==NULL){
                struct Hnode* temp = prev->left;
                if(prev==Hroot->left){
                    delete Hroot->left;
                    Hroot->left = temp;
                }


                else{
                    delete Hroot->right;
                    Hroot->right = temp;
                }
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
	            Ldelete(Lroot,low,high);
	            Hdelete(Hroot,low,high);
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
	            Lsucc(Lroot,low,high);
	        }

	        else if(op[0]=='h'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            Hsucc(Hroot,low,high);
	        }

	        else if(op[0]=='o'){
	            int low,high;
	            cin>>low;
	            cin>>high;
	            Overlap(Lroot,low,high);
	        }

	    }

	    //Linorder(Lroot);
	    //Hinorder(Hroot);

	    M--;
	}
	return 0;
}
