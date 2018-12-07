/** Hilina Awgichew CS163 Project2 this is the impelimentaion 
 * file. in this file all the function are defined. and there are 
 * two ADTs stack linear linked list of array and queue circular 
 * linked list. 
 */

#include"stack.h"
#include"queue.h"

using namespace std;
//constructor to allocate
stack::stack() {
    //setting head to null
    head = 0;
    //setting top_index to 0
    top_index = 0;
}
//stack destructor to deallocate all memory
stack::~stack() {
    //the list is empty
    if(!head)
        return;
//temporary pointer
    node * current = head;
    head->next = NULL;
    //when we have list or item
    while(current) {
        head = current->next;
        //to clear memory
        delete [] current->entry;
        delete current;
        current = head;
    }
}
//constructor
create_shope::create_shope() {
    //setting feature and location to null
    feature = NULL;
    location = NULL;
    a_feature = NULL;
    a_location = NULL;

}
//destructor
create_shope::~create_shope() {
   //deallocating feature 
    if(a_feature != NULL) {
        delete [] a_feature;
        a_feature = NULL;
    }
    //deallocating location
    if(a_location != NULL) {
        delete [] a_location;
        a_location = NULL;
    }
    //calling the destructor function
    remove();
}
//destructor 
int create_shope::remove() {
    //deallocating memory for feature
    if(feature) {
        delete [] feature;
        feature = NULL;
    }
    //deallocating memory for location
    if(location) {
        delete [] location;
        location = NULL;
    }

    return 1;
}
//constructor
queue::queue() {
    //set rear to null
    rear = NULL;
}
//destructor
queue::~queue() {
    //the list is empty
    if(!rear)
        return;
//temporary pointer
    q_node * temp = rear->next;
    rear->next = NULL;
//when temp is not null
    while(temp) {
        q_node * current = temp;
        temp = temp->next;
        //clear the memory 
        delete current->loca;
        //clear memory
        delete current;
        current = NULL;
    }
}
//create function to the stack
int create_shope::create_stack(char * features, char * locations) {
//to create feature to the stack
    feature = new char [strlen(features) + 1];
    strcpy(feature, features);
    //to create loction to the stack
    location = new char [strlen(locations) + 1];
    strcpy(location, locations);

    return 1;
}
//to create item to the queue
int create_shope::create_queue(char * features, char * locations) {
//to create feature to the queue
    a_feature = new char [strlen(features) + 1];
    strcpy(a_feature, features);
    //to create location to the queue
    a_location = new char [strlen(locations) + 1];
    strcpy(a_location, locations);

    return 1;
}
//to copy to the satck
int create_shope::copy(create_shope & to_copys) {
//copy feature to the stack
    a_feature = new char [strlen(to_copys.a_feature) + 1];
    strcpy(a_feature, to_copys.a_feature);
    //copy location to stack
    a_location = new char [strlen(to_copys.a_location) + 1];
    strcpy(a_location, to_copys.a_location);

    return 1;
}
//to copy to the stack
int create_shope::copy_entry(create_shope & to_copy) {
    //copy feature
    feature = new char [strlen(to_copy.feature) + 1];
    strcpy(feature, to_copy.feature);
    //copy location
    location = new char [strlen(to_copy.location) + 1];
    strcpy(location, to_copy.location);

    return 1;
}
//wrapper function to display
int stack::display_all(node * head) {
    //is empty
    if(!head)
        return 0;
    //loop to get through to all list
    for(int i = 0; i < MAX; ++i)
        //call the display function
        head -> entry[i].display();
    return display_all(head->next);
}
//display function
int stack::display_all() {
    //the list is empty
    if(!head)
        return 0;
    //for loop to get to all the item
    for(int i = 0; i < top_index; ++i) {
        //call the display function
        head->entry[i].display();
    }
    return display_all(head->next);
}

int stack::push(create_shope & to_add) {
    //the list is empty
    if(!head) {
        //new node
        head = new node;
        //new entry to the list
        head -> entry = new create_shope[MAX];
        //add to the copy fucntion
        head -> entry[top_index].copy_entry(to_add);
        //decrement top index
        ++top_index;
    } else if(top_index == MAX) {
        //temporary pointer
        node * temp;
        //new node
        temp = new node;
        //setting top index to zero
        top_index = 0;
        //create new entry
        temp->entry = new create_shope[MAX];
        //copy to the function
        temp->entry[top_index].copy_entry(to_add);
        ++top_index;
        temp->next = head;
        head = temp;
        temp = NULL;
    } else {
        //to add to the stack
        head -> entry[top_index].copy_entry(to_add);
        ++top_index;
    }

    return 1;
}

int stack::pop() {
//the list is empty
    if(!head)
        return 0;
    //there is one item in the index
    if(top_index == 1) {
        node * temp = head->next;
        //to prevent memory leak
        delete [] head->entry;
        delete head;
        head = NULL;

        top_index = MAX;
        head = temp;
    } else {
        //this call the distructo function
        head->entry[top_index-1].remove();
        --top_index;
    }
    return 1;
}

int stack::peek(create_shope & to_top) {
//the list is empty
    if(!head)
        return 0;
    //when index is zero
    if(top_index == 0)
        return 0;

    if(to_top.copy_entry(head->entry[top_index -1]))
        return 1;


    return 0;
}
//to display
int create_shope::display() {
    //to read from the application program
    cout<<"Shopping Features \n\n " << feature << endl;
    cout<<"Shopping Location \n\n " << location << endl;

    return 1;
}

//to display to the stack
int create_shope::displays() {
    //to read from the application program
    cout<<"Feature \n\n " << a_feature << endl;
    cout<<"Location \n\n " << a_location << endl;

    return 1;
}

int queue::enqueue(create_shope & to_add) {
    //the list is empty
    if(!rear) {
        //new node 
        rear = new q_node;
        //new array of caracter
        rear->loca = new create_shope();
        //copy to the list 
        rear -> loca -> copy(to_add);
        rear->next = rear;
    } else {
        //temporary pointer
        q_node * temp = new q_node;
        temp->loca = new create_shope();
        //adding to the list
        temp->loca->copy(to_add);
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
    return 1;
}

int queue::dequeue() {
    //the list is empty
    if(!rear)
        return 0;
    else {
        //temporary pointer
        q_node * temp = rear->next;
        rear->next = temp->next;
        //to break up the list
        if(temp == rear) {
            delete rear->loca;
            delete rear;
            rear = NULL;
        } else {
            //to privent memory leak
            delete temp->loca;
            delete temp;
            temp = NULL;
        }
    }
    return 1;
}
//to display from the dequeue
int queue::display_queue() {
    //if the list is empty
    if(!rear)
        return 0;
    //temporary pointer
    q_node * temp = rear->next;
    //to break up the list
    while(temp != rear) {
        temp -> loca -> displays();
        temp = temp -> next;
    }
    //call the display function
    rear -> loca -> displays();

    return 1;
}
