// 
// btree.cpp
//
// Your Name: Adam Sunshine
// 
// Collaboration is not only encouraged, it is basically
// demanded. Work together! Share code!
//
// Just write down your main collaborators here:
// Sarah Lacoste, Thomas Horn , Fletcher Richman


#include <iostream>
#include "btree.h"

using namespace std;


// -------------------------------------------- I N S E R T ---------
//
// Insert the given key into a b-tree rooted at 'root'.  If the key is
// already contained in the btree this should do nothing.  
// 
// On exit: 
// -- the 'root' pointer should refer to the root of the
//    tree. (the root may change when we insert or delete)
// -- the btree pointed to by 'root' is valid.
void split(btree* &root)
{
	
	btree* left = new btree();
	btree* right = new btree();
	int middle = BTREE_ORDER/2;
	right->num_keys = 0;
	left->num_keys = 0;
	right->is_leaf = true;
	left->is_leaf = true;
	for ( int i =0; i < middle; i++)
	{
		left->keys[i] = root->keys[i];
		left->num_keys ++;
	}
	for (int i=0; i< middle; i++)
	{
		right->keys[i] = root->keys[i+3];
		right->num_keys ++;
	}
	root->keys[0] = root->keys[middle];
	root->children[0] = left;
	root->children[1] = right;
	root->is_leaf = false;
	root->num_keys=1;
}

void insert_helper(btree* &root, int key) //btree** b_return, int* insert_key)
{
        
        int num_keys = root -> num_keys;
        int j = num_keys;
        if(root == NULL)
        {
                cout << "Doesn't Work" << endl;
        }
        if(contains(root, key))
        {
                cout << "This is a duplicate key" << endl;
        }
        if (root -> is_leaf == true)
        {
                for(; j > 0; j--)
                {
                        if(root->keys[j-1] > key)
                                root->keys[j] = root->keys[j-1];
                        else
                                break;
                }
                root->keys[j] = key;
                (root->num_keys)++;
		}
                 
        
			if( root->num_keys == BTREE_ORDER)
			{
				split(root);
			}
	
				
		  
		  
		  
}


 
 
void insert(btree* &root, int key)
{
        //int insert_key;
        //btree* b_return;
        insert_helper(root, key);
}

// -------------------------------------------- R E M O V E ---------
//
// Remove the given key from a b-tree rooted at 'root'. If the key is
// not in the btree this should do nothing.
//
// On exit:
// -- the 'root' pointer should refer to the root of the
//    tree. (the root may change when we insert or delete)
// -- the btree pointed to by 'root' is valid.
void remove_helper(btree* &root, int key)
{
	int num_keys = root->num_keys;
	for (int j = 0; j < num_keys; j++)
			{
                if(root -> keys[j] == key)
					{
                        root->keys[j] = root->keys[j+1];
						
						cout << num_keys << endl;
						
						
					}
			} 
			
      
}


void remove(btree* &root, int key)
{
	int num_keys = root->num_keys;
	if(root == NULL)
	{
		cout << "cannot remove" << endl;
	}
	if(root->is_leaf)
	{
		remove_helper(root, key);
		root->num_keys--;
		
			 //root->num_keys--;
	}
	else
		{
			int i =0;
			while ( key > root->keys[i])
			{
				i++;
			} 
				
			//for ( int i = 0; i < num_keys; i++)
				
			remove( root->children[i] , key);
					
					//root -> num_keys--; 
					
			
		}


}

// ----------------------------------------- C O N T A I N S --------
//
// Return true if any node accessed from the given root node contains
// the provided key value.
bool contains(btree* &root, int key)
{
	if( root== NULL)
		return false;
	int i;
	for (i= 0; i < root->num_keys; i++)
	{
		if( key == (root->keys[i]))
			return true;
		else if (key < (root->keys[i]))
		{
			if ( root->is_leaf == true)
				return false;
			else
				return contains( root->children[i], key);
		}
	
	}
	if (root-> is_leaf ==false)
		return contains( root->children[root->num_keys], key); 
	
  return false;
}
