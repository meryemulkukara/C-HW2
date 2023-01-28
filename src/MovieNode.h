/*
 * MovideNode.h
 *
 *  Created on: 4 Ara 2020
 *      Author: Ulku
 */

#ifndef MOVIENODE_H_
#define MOVIENODE_H_
#include <iostream>
using namespace std;

class MovieNode {
public:
	MovieNode();
	virtual ~MovieNode();
	struct Node
	{int data1;
	string data2;
	int data3;
	Node *next;};
	Node *last=NULL;

void create_node(int value1,string value2,int value3)
	{
	    struct Node *temp;
	    temp = new(struct Node);
	    temp->data1 = value1;
	    temp->data2 = value2;
	    temp->data3 = value3;
	    if (last == NULL)
	    {
	        last = temp;
	        temp->next = last;
	        last->next=temp;

	    }
	    else
	    {
	        temp->next = last->next;
	        last->next = temp;
	        last = temp;
	    }
	}

bool search_element(int value1)
{
    struct Node *s;
    if(last==NULL)
    {
    	return true;
    }
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;//"Element found at position "
        if (s->data1 == value1)
        {
            return false;
        }
        s = s->next;
    }
    if (s->data1 == value1)
    {
        counter++;//"Element found at position "
        return false;
    }
    else return true;

}



void add_begin(int value1,string value2,int value3)
{

    if(search_element(value1))
    {
    	if (last == NULL)
    	    {
    	    	create_node( value1, value2, value3);
    	        return;
    	    }
    	struct Node *temp;
    	    temp=new(struct Node);

    	    temp->data1 = value1;
    	    temp->data2 = value2;
    	    temp->data3 = value3;
    	    temp->next =last->next;
    	    last->next=temp;

    }
    else
    	{cout<<"\n			Movie "<<value1<<" already exists";
    	return; }
}

bool delete_element(int value1)
{	if(!search_element( value1))
	{
	struct Node *temp, *s;
	    s = last->next;
	      /* If List has only one element*/
	    if (last->next == last && last->data1 == value1)
	    {
	        temp = last;
	        last = NULL;
	        cout<<"\n			Movie "<<value1<<" has been deleted" ;
	        free(temp);
	        return true;
	    }
	    if (s->data1 == value1)  /*First Element Deletion*/
	    {
	        temp = s;
	        last->next = s->next;
	        cout<<"\n			Movie "<<value1<<" has been deleted" ;
	        free(temp);
	        return false;
	    }
	    while (s->next != last)
	    {
	        /*Deletion of Element in between*/
	        if (s->next->data1 == value1)
	        {
	            temp = s->next;
	            s->next = temp->next;
	            cout<<"\n			Movie "<<value1<<" has been deleted" ;
	            free(temp);

	            return false;
	        }
	        s = s->next;
	    }
	    /*Deletion of last element*/
	    if (s->next->data1 == value1)
	    {
	        temp = s->next;
	        s->next = last->next;
	        cout<<"\n			Movie "<<value1<<" has been deleted" ;
	        free(temp);
	        last = s;
	        return false;
	    }
	}
	else
		cout<<"\n			Movie "<<value1<<" does not exist" ;
};

void display_list()
{
    struct Node *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = last->next;

    while (s != last)//linked list loop
    {
        cout<<s->data1<<","<<s->data2<<","<<s->data3<<"->>";
        s = s->next;
    }
    if(s==last)
        {
        	cout<<s->data1<<","<<s->data2<<","<<s->data3<<"->>";
        	return ;
        }
    cout<<s->data1<<endl;
}


};

#endif /* MOVIENODE_H_ */
