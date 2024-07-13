#include<iostream> //  is the Standard C++ way to include header files, 
//the 'iostream' is an identifier that maps to the file iostream.h. 
#include<conio.h> //  includes the console input output library functions. 
// The getch () function is defined in conio.h file.  
using namespace std;  // The built in C++ library routines are kept in the standard namespace. 
//That includes stuff like cout, cin, string, vector, map, etc.

//A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations.
//A linked-list is a sequence of data structures which are connected together via links.
class library{
	private: // priv data type
		struct Node{ // creating node in link list with help of struct
			int id;
			string name,author,publisher;
			// next_add means next address
			Node *next_add; // pointer that is pointing next node
		};
	public: // public data type
	// we will give head pointer first value null because node is empty
		Node *head; // pointer that is pointing link list first node "head"
		// creating functions
		void menu();
		void insert();
		void search();
		void update();
		void del();
		void sort();
		void display();
};

void library::menu(){ // class name and function // whole menu of program
    p:
    // cls for cleaning the screen or data
	system("cls");
	int choice;
	cout<<"\n\n\t\t\t=================================================";
	cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	cout<<"\n\n\t\t\t=================================================";
	cout<<"\n\n 1: Insert New Record";
	cout<<"\n\n 2: Search Record";
	cout<<"\n\n 3: Update Record";
	cout<<"\n\n 4: Delete Record";
	cout<<"\n\n 5: Show all Record";
	cout<<"\n\n 6: Exit";
	cout<<"\n\n Enter your choice: ";
	cin>>choice;
	switch(choice){
		case 1:
			insert(); // first insert function is called
			break;
		case 2:
		    search(); // second function which will call is search
			break;
		case 3: 
            update(); // third case is search case 	   
			break;
		case 4: 
		    del(); // fourth case is delete case
			break;
		case 5:
			// both are called in case 5 because we want it first to sort and then display
			sort(); // fifth case is sorting case
		    display();
			break;
		case 6:
		    exit(0); // case 6 is exit case for exiting
		default: 
		    cout<<"\n\nInvalid Choice! Please try again.";
		}
		// to hold the output screen for some time until the user passes a key from the keyboard to exit the console screen. 
		// we can hide the input character provided by the users in the ATM PIN, password, etc.
	getch();	
	goto p;
	// The goto statement is a jump statement which is sometimes also referred to as unconditional jump statement. 
	// The goto statement can be used to jump from anywhere to anywhere within a function.
}

void library::insert(){ // for inserting the data
	// cls for cleaning the screen or data
	system("cls");
	cout<<"\n\n\t\t\t=================================================";
	cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	cout<<"\n\n\t\t\t=================================================";
	Node *new_node=new Node;  // creating new node and saving address of new node
	cout<<"\n\n Book ID: ";
	cin>>new_node->id; // placing the book id in new_node pointer
	cout<<"\n\n Name: ";
	cin>>new_node->name; // new_node is poiniting which is having "name" variable place the value in it
	cout<<"\n\n Author Name: ";
	cin>>new_node->author;  // new_node is poiniting which is having "author" variable place the value in it
	cout<<"\n\n Publisher Name: ";
	cin>>new_node->publisher;  // new_node is poiniting which is having "publisher" variable place the value in it
	// we are saving null here b/c "next_add" is pointing address of next node we don't have another node here so we are saving null here
	new_node->next_add=NULL; // we are saving Null in "next_add" pointer which is pointed by "new_node" pointer
	
	// the node we have created if it is first node of link list so we will give its address to head otherwise we will give its address to last node
	// To know that if our link list is empty or not we are applying here conditions
	if(head==NULL){
		// if head is null then we know that the node we created is our first node of link list
		head=new_node; // head pointer will be equalto new node pointer , give address of new node to head
	}
	else{
		// if its not a first node then give its address to last node
		// "ptr" pointer is for finding last node
		// we gave "ptr" address of head because we have to visit every node so that we will know which one is our last node
		Node *ptr=head;
		// we are applying this loop to check if the node we are at is last or not
		// if next address or "next_add" is null then it is last node 
		// "ptr" is pointing the pointer "next_add" if its value is not equal to null then go inside the loop
		while(ptr->next_add!=NULL){
			// we are moving "ptr" next
			// The pointer "ptr" is pointing we will save next address in it
			ptr=ptr->next_add;
		}
		// when this loop will end the address which "ptr' will have will eventually the address of last node
		// ptr which now have last node address we will go inside last node and go to it's next and give next_add's address to new_node
		ptr->next_add=new_node; 
	}
	// msg for the insersion of new book
	cout<<"\n\n\t\t\tNew Book Inserted Successfully!";
}

void library::search(){ // for seacrhing the data
	// cls for cleaning the screen or data
	system("cls");
	// t_id var is basically text id variable use to ask user which book id they want to search
	// found var is use to check if the book id we are looking for is found or not
	int t_id,found=0;
	cout<<"\n\n\t\t\t=================================================";
	cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	cout<<"\n\n\t\t\t=================================================";
	// for searching first we have to check that the list in which we are searching if it has data or not
	// if head pointer is null then eventually the list will be empty there will be no node 
	if(head==NULL){
		cout<<"\n\nLinked List is Empty!";
	}
	else{
		// to ask user which book id you want to search
		cout<<"\n\n Book ID: ";
		// t_id var is basically text id variable use to ask user which book id they want to search
		cin>>t_id;
		// we will match this t_id with every node of link list
		Node *ptr=head; // we will give value of head to "ptr" pointer
		// this while loop will run until "ptr" will not equal to null
		while(ptr!=NULL){
			// The test id we are searching for is equal to the id (node which "ptr" is pointing that have already id we are matching it with the test id)
			if(t_id==ptr->id){
				// if it matches then record is found
				cout<<"\n\n\t\t\t=================================================";
	            cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	            cout<<"\n\n\t\t\t=================================================";
	            cout<<"\n\n Book ID: "<<ptr->id; // id is save inside the pointer which ptr is pointing
	            cout<<"\n\n Book Name: "<<ptr->name; // name is save inside the pointer which ptr is pointing
	            cout<<"\n\n Author Name: "<<ptr->author; // author is save inside the pointer which ptr is pointing
	            cout<<"\n\n Publisher Name: "<<ptr->publisher; // publisher is save inside the pointer which ptr is pointing
	            found++; // ++ because we found the record
	            // found variable has initially value 0
			}
			// after checking one node we have to move to the next node
			// we will move "ptr" to next address or next node
			ptr=ptr->next_add;
		}
		// if found is 0 that means we haven't found the record
		if(found==0){
			cout<<"\n\n Invalid Book ID!";
		}
	}
}

void library::update(){  // for updating the data
	// cls for cleaning the screen or data
	system("cls");
	// t_id is text id of book
	// found is for found case will 0 in start
	int t_id,found=0;
	cout<<"\n\n\t\t\t=================================================";
	cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	cout<<"\n\n\t\t\t=================================================";
	// if head is null list will be empty
	if(head==NULL){
		cout<<"\n\nLinked List is Empty!";
	}
	else{
		// otherwise we will ask for book id
		cout<<"\n\n Book ID: ";
		cin>>t_id;
		// one by one starting from head we will check by matching test id with the id that already nodes have
		Node *ptr=head; // giving value of head to the "ptr" pointer for matching
		// this while loop will run until "ptr" will not equal to null
		while(ptr!=NULL){
			// The test id we are searching for is equal to the id (node which "ptr" is pointing that have already id we are matching it with the test id)
			if(t_id==ptr->id){
				system("cls");
				cout<<"\n\n\t\t\t=================================================";
	            cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	            cout<<"\n\n\t\t\t=================================================";
	            cout<<"\n\n Book ID: ";
	            // the diff between insert and update is here we are cin all input values 
				cin>>ptr->id; // id is save inside the pointer which ptr is pointing
	            cout<<"\n\n Book Name: ";
	            // cin for updating the values
				cin>>ptr->name; // name is save inside the pointer which ptr is pointing
	            cout<<"\n\n Author Name: ";
				cin>>ptr->author; // author is save inside the pointer which ptr is pointing
	            cout<<"\n\n Publisher Name: ";
				cin>>ptr->publisher; // publisher is save inside the pointer which ptr is pointing
	            found++; // found will increament after every found case
	            // In case record is updated this msg will be print
	            cout<<"\n\n\t\t\tNew Book Updated Successfully!";
			}
			// this is for checking address of every next node
			ptr=ptr->next_add;
		}
		// if found is 0 that means we haven't found the record
		if(found==0){
			cout<<"\n\n Invalid Book ID!";
		}
	}
}

void library::del(){ // for deleting the data
	// cls for cleaning the screen or data
	system("cls");
	// t_id is text id of book
	// found is for found case will 0 in start
	int t_id,found=0; // found will check if we get the record or not
	cout<<"\n\n\t\t\t=================================================";
	cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	cout<<"\n\n\t\t\t=================================================";
	// if head is null list will be empty
	if(head==NULL){
		cout<<"\n\nLinked List is Empty!";
	}
	else{
		// if list is not null then take the book id which we have to delete
		cout<<"\n\n Book ID: ";
		cin>>t_id;
		// if the book record we want to delete is in first node which is head
		if(t_id==head->id){
	        Node *ptr=head; // taking address of first node
	        // giving address new value
			head=head->next_add; // we are giving head address of next node because we want to delete head
			delete ptr; // deleting ptr 
			cout<<"\n\nBook Deleted Successfully!";	
			found++; // after finding the id we want to get found var will be increamented
		}
		// if the node you want to delete is not the first node of link list
		else{
			// if we want to delete curr node we have to give address of next node to the previous node
			// here we are taking two pointers one is previous and ptr pointer will point current node
			Node *pre=head;
			Node *ptr=head;
			while(ptr!=NULL){ // work until ptr is not equal to null
				// we will visit every node and compare our test id with it
				if(t_id==ptr->id){ // if test id is equal to id which ptr is pointing 
				// ptr will be delete so the address of the next node is in next_add pointer we will give its address to prev pointer
					pre->next_add=ptr->next_add;  // prev's next will be equal to ptr's next and ptr will be delete
					delete ptr; // delete ptr
					cout<<"\n\nBook Deleted Successfully!";	
			        found++; // increament in found after every found case
			        break; // break because when one node is delete  we don't move to its next
				}
				// if it will not delete
				pre=ptr; // previous will be equal to ptr
				ptr=ptr->next_add; // ptr will be equal to ptr's next address
			}
		}
		// if found is 0 that means we haven't found the record
		if(found==0){
			cout<<"\n\nBook ID is Invalid!";	
		}
	}
}

//Bubble sort is a simple sorting algorithm. This sorting algorithm is comparison-based algorithm 
//in which each pair of adjacent elements is compared and the elements are swapped if they are not in order.
// we will applying here bubble sorting
void library::sort(){
	// if head is null the msg will display
	if(head==NULL){
		system("cls");
		cout<<"\n\n\t\t\t=================================================";
	    cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	    cout<<"\n\n\t\t\t=================================================";
		cout<<"\n\nLinked List is Empty!";
		//  we can hide the input character provided by the users in the ATM PIN, password, etc.
		getch(); // to hold the output screen for some time until the user passes a key from the keyboard to exit the console screen. 
		menu(); // if head is null it will simply go to menu
	}
	// for sorting we should know how much values we have to sort
	// "count" var is for counting number of nodes
	// t_id is for test id
	int count=0,t_id;
	// these all are test strings for testing or matching
	string t_name,t_author,t_publisher; // for saving data temporary
	Node *ptr=head; // giving value of head to the "ptr" pointer for matching
	// this loop will work untill ptr is not null
	while(ptr!=NULL){
		count++; // first time the value of count will be 0 then it will increament everytime
		ptr=ptr->next_add; // for moving to next node will are assigning ptr->next_add
	}
	// bubble sort for loop
	// this loop will run in how much we want to manage record
	for(int i=1;i<=count;i++){   // by this loop we will sort everytime from first node
		// for visiting every node
		// creating node
		Node *ptr=head; // giving value of head to the "ptr" pointer for matching
		// if we write the above statement inside the second looop so the second loop will start everytime time from first node which we dont want so we are writing this statement before 2nd loop
		for(int j=1;j<count;j++){   // by this loop we will sort everytime from next node
		// when these both loop will work one time it will take the record and apply sorting technique on it
		  // ptr have now address of cuurent node
		  // we are doing here ascending order sorting
		  // sorting in ascending order will take place if current value is bigger than next value
			// here in the below condition the id that ptr is pointing is greater than the id which ptr ->next_add have
			if(ptr->id > ptr->next_add->id){  // if this cond is true it will swap
		        // Saving data in temporary variables
		        // we will do swaping by saving curr variables value in temporary variables
		        // the address of the node will never change once it is given we will only swap data
			    t_id=ptr->id; // t_id will have the data of id which ptr is pointing
			    t_name=ptr->name; // t_name will have the data of name which ptr is pointing
			    t_author=ptr->author; // t_author will have the data of author which ptr is pointing
			    t_publisher=ptr->publisher; // t_publisher will have the data of publisher which ptr is pointing
			    // Save data in current node
			    // here we are putting address of second node in the first node
			    ptr->id=ptr->next_add->id; // ptr's id and the ptr->next_add's id will be equal
			    ptr->name=ptr->next_add->name; // ptr's name and the ptr->next_add's name will be equal
			    ptr->author=ptr->next_add->author; // ptr's author and the ptr->next_add's author will be equal
			    ptr->publisher=ptr->next_add->publisher; // ptr's publisher and the ptr->next_add's publisher will be equal
			    // Save data in next node
			    // now the data we saved previously in temporary variables we will place it in second node
		        //because temp var have current node's data
		        // the next node which we previously = to curr node will now equal to the temp var
				ptr->next_add->id=t_id;
			    ptr->next_add->name=t_name;
			    ptr->next_add->author=t_author;
			    ptr->next_add->publisher=t_publisher;
			}
			// after checking one node we have to move to the next node
			// we will move "ptr" to next address or next node
			// putting this condition inside the for loop b/c we wanted to run for loop again and again
			ptr=ptr->next_add;
		}
	}
}

void library::display(){ // for displaying the data
	system("cls");  // The system (“cls”) is used to clear our screen
	cout<<"\n\n\t\t\t=================================================";
	cout<<"\n\n\t\t\t===========LIBRARY MANAGEMENT SYSTEM=============";
	cout<<"\n\n\t\t\t=================================================";
	Node *ptr=head; // giving value of head to the "ptr" pointer for matching
	while(ptr!=NULL){ 	// this while loop will run until "ptr" will not equal to null
	    cout<<"\n\n Book ID: "<<ptr->id; // id is save inside the pointer which ptr is pointing
	    cout<<"\n\n Book Name: "<<ptr->name; // name is save inside the pointer which ptr is pointing
	    cout<<"\n\n Author Name: "<<ptr->author; // author is save inside the pointer which ptr is pointing
	    cout<<"\n\n Publisher Name: "<<ptr->publisher; // publisher is save inside the pointer which ptr is pointing
		cout<<"\n\n\t\t\t=================================================";
		// after checking one node we have to move to the next node
		ptr=ptr->next_add; // we will move "ptr" to next address or next node
	}
}

main(){
	library obj; // library class object
	obj.menu(); // calling menu function
} 
