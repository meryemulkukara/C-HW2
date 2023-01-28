/*
 * Node.h
 *
 *  Created on: 3 Ara 2020
 *      Author: Ulku
 */
#include <iostream>
#include <string>
#ifndef USERNODE_H_
#define USERNODE_H_
using namespace std;

class UserNode {

struct Node
		{
		int info1;
		string info2;
		Node *next;
		Node *prev;

		};
private:
    Node* head;
    Node* tail;
    int counter;
    int data1;
    string data2;
public:
Node*  create_node(int data1,string data2)
    {
        counter++;
        Node *temp;
        temp = new(struct Node);
        temp->info1 =data1;
        temp->info2=data2;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    };
	UserNode(){ head = tail = nullptr; };
	virtual ~UserNode();

	bool searchInsert(int data1)
	{
	    int pos = 0,i;
	    bool flag = false;
	    struct Node *s;
	    s = head;
	    for (i = 0;i < counter;i++)
	    {
	        pos++;
	        if (s->info1 == data1)
	        {
	            flag = true;
	            return flag;
	        }
	        s = s->next;
	    }
	    return false;
	}
void insert_last(int data1,string data2)
	{	if(!searchInsert(data1))
		{



	    struct Node *temp;
	    temp = create_node(data1,data2);
	    if (head == tail && head == NULL)
	    {
	        //cout<<"Element inserted in empty list"<<endl;
	        head = tail = temp;
	        head->next = tail->next = NULL;
	        head->prev = tail->prev = NULL;
	        cout<<"	\n			User "<<data1<<" has been added";
	    }
	    else
	    {
	        tail->next = temp;
	        temp->prev = tail;
	        tail = temp;
	        head->prev = tail;
	        tail->next = head;
	        cout<<"	\n			User "<<data1<<" has been added";
	    }
		}
	else
			cout<<"	\n			User "<<data1<<" already exist";
						return ;
	}

void display()
{
    int i;
    Node *s;
    if (head == tail && head == NULL)
    {
        cout<<"The List is empty, nothing to display";
        return;
    }
    s = head;
    for (i = 0;i < counter-1;i++)
    {
        cout<<"\n			User id: "<<s->info1<<" User name: "<<s->info2;
        s = s->next;
    }
    cout<<"\n			User id: "<<s->info1<<" User name: "<<s->info2;

}

int searchDel(int data1)
{
    int pos = 0,i;
    bool flag = false;
    struct Node *s;
    if (head == tail && head == NULL)
    {
        cout<<"	\n			User "<<data1 <<" does not exits";
        return 0;
    }
    s = head;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->info1 == data1)
        {
            //cout<<"Element "<<data1<<" found at position: "<<pos<<endl;
            flag = true;
            return pos;
        }
        s = s->next;
    }
    if (!flag)
        {cout<<"\n			User "<<data1<<" does not exit";
        int count=counter+1;
    	return count;}

}


void delete_pos(int data1)
{
    int pos=searchDel(data1);
	int i;
    Node *ptr, *s;


  if (counter < pos)
    {
        cout<<endl;
        return ;
    }
    s =head;
    if(pos == 1)
    {
        counter--;
        tail->next = s->next;
        s->next->prev = tail;
        head = s->next;
        cout<<"\n				User "<<data1<<" has been deleted ";
        free(s);

        return;
    }
    for (i = 0;i < pos - 1;i++ )
    {
        s = s->next;
        ptr = s->prev;
    }
    ptr->next = s->next;
    s->next->prev = ptr;
    if (pos == counter)
    {
        tail = ptr;
    }
    counter--;
    cout<<"	\n			User "<<data1<<" has been deleted ";
    free(s);
    return;

}



	};
#endif /* USERNODE_H_ */
