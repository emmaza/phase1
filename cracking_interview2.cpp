//linked list
#include <iostream>
using namespace std;


struct node {
  int x;
  node *next;
};

void printList(node *root);
node * MYcreateList(int n); //wrong. printed n+1 nodes, the first one is extra.
node * LNcreateList(int n); // print n nodes, as expected.
node * reverseList(node *root);
void findLoop(node * root);
node * createCirList(int n, int m);
node * SmartfindLoop(node * root);

int main(){
	//printList(LNcreateList(5) -> next);
	//printList(MYcreateList(5)); //the last node is printed as 0, though I haven't given it a value.
	//node * testList=LNcreateList(5);
	//printList(testList);
	//printList(reverseList(testList));
	//createCirList(6,2);
	node * p=createCirList(5,3);
	findLoop(p);
	printf("loop is at %p\n", SmartfindLoop(p));
	cout << "loop is at " << SmartfindLoop(p) << endl;
}
node * SmartfindLoop(node * root){ //O(n) rather than O(n**2). much faster than findLoop()
	node * n1=root;
	node * n2=root;
	//find meeting point
	while(n2->next != NULL){
		n1=n1->next;
		n2=n2->next->next;
		if(n1==n2) break;
	}
	//if no loop
	if(n2->next == NULL){
		printf("%s\n", "no loop");
		return NULL;
	}
	//find loop beginning
	n1=root;
	while(n1 != n2){
		n1=n1->next;
		n2=n2->next;
	}
	return n2;
}
void findLoop(node * root){
	node * test, *tmp;
	int i;
	//question: can a list with one node be circular?????
	test=root->next; 
	while(test->next != NULL){
		test = test-> next;//the node i'm looking at. starting at the 2nd node in the linked list.
		i=1;
		tmp=root; //tmp->next points to nodes before the test node.
		while(tmp != test){
			if(tmp->next != test-> next){ //just comparing tmp and test can also find the loop. but then can't use tmp=test to stop testing. can use counter instead.
				tmp=tmp->next;
				i++;
			} 
			else{
				printf("loop is at node number %d.\n", i);
				return;
			}
		}
	}
	if(test->next == NULL){
		printf("%s\n", "no loop");
		return;
	} 
}

node * createCirList(int n, int m){ // n is number of list nodes. m is where the loop is.
	node * root;
	node * tmp;
	node * tail;
	root = new node;
	//tmp = new node;
	tmp = root;
	int i,j;
	// the data of the list starts with 1, not 0 as before.
	for(i=1;i<=n; i++){
		tmp -> next = new node;
		tmp = tmp -> next;
		tmp -> x = i; // careful about the order; wrong if this goes before tmp->next= new node
	}
	if(m<1) return root; //if m=0, means no loop.
	tail=tmp; //linked list is done. now create the loop.
	tmp->next=root->next;
	for(j=1; j<=m; j++){ 
		tmp=tmp->next;
		tail->next=tmp;
	}
	printList(root);
	return root;
}

node * reverseList(node *root){ //using the method of creating n+1 nodes.
	node *first;
	node *curr;
	node * third;
	node *oldroot; 
	oldroot=root;
	root=oldroot-> next; //oldroot is a pointer pointing to the "head" node that marks the beginning of the list. but "head" is not part of the list
	if(root==NULL) return oldroot;
	first = NULL;
	curr = root;
	//printList(curr);
	third = root -> next;
	curr->next=NULL;
	//printList(third);
	while(curr != NULL){
				//printf("%s\n", "curr");
		//printList(curr);
		first=curr;
		curr=third;
		if(curr==NULL) {
			oldroot->next = root;
			return oldroot;}
		if(third != NULL) third=third->next;
		curr->next=first;
		//printf("%s", "curr->next=first");
		//printList(curr);
		root=curr;
		//printf("%s\n", "root");
		//printList(root);
	}
	oldroot->next = root; //the last two lines are doing little. because the function returns when curr==NULL;
	return oldroot; //should improve this function.
}
/* wrong??
node * reverseList(node *root){ //still using the method of creating n+1 nodes.
	node *first;
	node *curr;
	//assume at least 3 nodes. deal with special cases later.
	first=root;
	curr=root -> next;
	first -> next = NULL;
	root = curr -> next;
	curr -> next = first;
	while(root){
		first = curr;
		curr = root -> next;
		root = curr -> next;
		curr -> next = first;
	}

	return root;
}*/

void printList(node *conductor){
	//node *conductor;
	//conductor = root;
	//if(root){ } //check if list is null
	if(conductor)conductor=conductor->next;//extra step probably due to imperfection in createlist. causes trouble later on when using printlist in other functions.
	else return;
	int i=0;
	while(conductor != 0){
		cout<< conductor << "  " << conductor -> x<<endl;
		conductor = conductor -> next;
		i++;
		if(i>15) break; // temporary solution for circularly linked list. to be improved. 
	}
	cout <<"-------------------"<<endl;
}
//created linked list with values 0 to n-1; mistakes not corrected here.
node * MYcreateList(int n){
	node *root;
	node *conductor;
	root = new node; // n+1 nodes created in the end, not n nodes
	conductor = root;
	int i;
	for( i=0; i<n; i++){
		conductor -> next = new node; //without this, segamentation fault:11
		conductor ->x = i; //
		conductor = conductor -> next;
	}
	//conductor -> x =i; //if write "for(i=0; i<n; i++)" and don't add "conductor -> x =i" after for loop
	//there will be an extra conductor -> x = 0. why?
	printf("x=%d\n", conductor -> x);
	return root;
}
//created linked list with values 0 to n-1;
node * LNcreateList(int n){
	node *root;
	node *conductor;
	root = new node;
	conductor = root;
	int i;
	for( i=0; i<n; i++){
		conductor -> next = new node; //without this, segamentation fault:11
		conductor -> next->x = i; //
		conductor = conductor -> next;
	}
	//conductor -> x =i; //if write "for(i=0; i<n; i++)" and don't add "conductor -> x =i" after for loop
	//there will be an extra conductor -> x = 0. why?
	//printf("x=%d\n", conductor -> x);
	return root;
}
//copied from http://www.cprogramming.com/tutorial/c/lesson15.html
//c++: http://www.cprogramming.com/tutorial/lesson15.html
int linkedListC()
{
    /* This won't change, or we would lose the list in memory */
    struct node *root, *root1;       
    /* This will point to each node as it traverses the list */
    struct node *conductor;  

    root = (struct node *)malloc( sizeof(struct node) );  
    root1 = (struct node *)malloc( sizeof(struct node) );  
    root->next = root1;   
    root->x = 12;
    root1->x = 12;
    conductor = root; 
    /*if ( conductor != 0 ) {
        while ( conductor->next != 0)
        {
            conductor = conductor->next;
        }
    }*/
    /* Creates a node at the end of the list */
    conductor->next =  (struct node *)malloc( sizeof(struct node) );  

    conductor = conductor->next; 

    if ( conductor == 0 )
    {
        printf( "Out of memory" );
        return 0;
    }
    /* initialize the new memory */
    conductor->next = 0;         
    conductor->x = 42;
	conductor = root;
	while ( conductor != 0 ) {
   		printf( "%d\n", conductor->x );
    	conductor = conductor->next;
}    return 0;
}
