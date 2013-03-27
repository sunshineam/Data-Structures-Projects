//
// binary_search_tree.cpp
// Adam Sunshine

// description: this program will create a binary search tree, and will manipulate basic components of the binary search tree
// to find the data we may need. This includes adding nodes, removing nodes, and making an array of the data of nodes.
// 
//Please refer to binary_search_tree.h for documentation.
//
// Collaborators: Fletcher Richman, Sarah Lacoste

#include "binary_search_tree.h"

bt_node* init_node(int data) 
{
	bt_node* start = new bt_node;
	start->data = data;
	start->right = NULL;
	start-> left = NULL;
	
	
  return start;
}

void insert(bt_node** top_ref, bt_node* new_node) 
{
	bt_node* pointer = *top_ref;
	if ( pointer == NULL)
	{	
		*top_ref = new_node;
	}
	if((new_node->data) < (pointer->data))
		{
			if (pointer->left != NULL)
			{
				insert( &(pointer->left), new_node);
			}
			else
			{
				pointer->left = new_node;
			}
		}
		else
		{
			if (pointer->right != NULL)
			{
				 insert (&(pointer->right), new_node);
			}
			else
			{
				pointer->right =  new_node;
			}
		}
		
	
}

void insert_data(bt_node** top_ref, int data) 
{
	bt_node* cursor = init_node(data);
	insert( top_ref, cursor);	
  
}

void remove(bt_node** top_ref, int data)
{
	if((*top_ref) == NULL)
	{
		return;
	}
	if((*top_ref)->data > data)
	{
		remove(&((*top_ref)->left), data);
	}
	else if ((*top_ref)->data < data)
	{
		remove(&((*top_ref)->right), data);
	}
	else
	{
		bt_node* temp;
		if ((*top_ref)->left==NULL)
		{
			temp = (*top_ref)->right;
			*top_ref = temp;
		}
		else if ((*top_ref)->right == NULL)
		{
			temp = (*top_ref)->left;
			*top_ref= temp;
		}
		else // two children
		{
			temp = (*top_ref)->right;
			bt_node* parent = NULL;
			while (temp->left !=NULL)
			{
				parent = temp;
				temp = temp->left;
			}
			(*top_ref)->data = temp->data;
			if (parent !=NULL)
				remove(&(parent->left), parent->left->data);
			else
				remove(&((*top_ref)->right), (*top_ref)->right->data);
		}
	}
	
}

bool contains(bt_node* top, int data)
{
	if (top == NULL)
		return false;
		
	if ( top->data == data)
		return true;
		
	if ((top->data) > (data))
		return contains(top->left, data);
	else
		return contains(top->right, data);
		
}

bt_node* get_node(bt_node* top, int data)
{
	if (top == NULL)
		return NULL;
	if (top->data == data)
		return top;
	else
	{
		if ((top->data) > data)
			return get_node(top->left, data);
		else
			return get_node(top->right, data);
	}
		
}

int size(bt_node* top) 
{
	int count = 0;
	if (top == NULL)
		return count;
	else
		count ++;
	if (top->left !=NULL)
	{
		count += size(top->left);
	}
	if (top->right !=NULL)
	{
		count+=size(top->right);
	}
	
	  
  return count;
}

void to_array(bt_node* top, int arr[]) {
  static int count = 0;
  if (top != NULL)
  {
	  to_array(top->left, arr);
	  arr[count++] = top->data;
	  to_array(top->right, arr);
  }
}
