/*

  sorting.cpp

  Please refer to sorting.h for documentation on each function.

  Your Name: Adam Sunshine
  Your TA: Shang Ma
  List O' Collaborators: Fletcher Richman, Sarah Lacoste


   + ------ N O T E: -- Big scary warning! ------------------------------
   |
   |    We clearly can't use unit testing to ensure that you're
   |    actually implementing the correct algorithm. I suppose we could
   |    write some complicated static analysis checker. But it is
   |    easier to just look at it with our eyeballs.
   |
   |    After the assignment is due, we will look at the most recent
   |    version of your implementation that got the highest score and
   |    make sure you're not doing something sneaky like using a
   |    standard library call to sort a vector.
   |
   |    Anyone caught doing this (even though it is kinda funny) will
   |    be given 0/15 on the assignment.
   |
   +-------------------------------------------------------------------- 

 */

#include "sorting.h"
#include <math.h>

using namespace std;


void quicksort(vector<int> &data, int low_idx, int high_idx)
{
	if ( high_idx > low_idx)
	{
		int pivot_index = (low_idx +high_idx)/2;
		int temp = data[pivot_index];
		data[pivot_index] = data[high_idx];
		data[high_idx] = temp;
		pivot_index = low_idx;
		int pivot;
		pivot = quicksort_partition( data, low_idx, high_idx, pivot_index);
		quicksort( data, low_idx, (pivot-1));
		quicksort ( data, (pivot+1), high_idx);
	}
}

int quicksort_partition(vector<int> &data, int low_idx, int high_idx, int pivot_index)
{
	for ( int i= low_idx; i < high_idx; i++)
	{
		if (data[i] < data[high_idx])
		{
			int temp = data[i];
			data[i] = data[pivot_index];
			data[pivot_index] = temp;
			pivot_index ++;
		}
	}
	int temp_2 = data[pivot_index];
	data[pivot_index] = data[high_idx];
	data[high_idx] = temp_2;
	
	return pivot_index;
}

void bubblesort(vector<int> &data)
{
	int flag;
	int length = data.size();
	int temp;
	while(flag)
	{
		flag = false;
		for( int i = 0; i < length; i++)
		{
			if (data[i] > data[i+1])
			{
				temp = data[i];
				data[i] = data[i+1];
				data[i+1] = temp;
				flag = true;
			}
		}
	}
}

void mergesort(vector<int> &data)
{
               
  if (data.size() <= 1)
        return;
       
 int middle = floor((data.size())/2.0);
 
  vector<int> left;
  vector<int> right;
  for ( int i = 0; i < data.size(); i++){
          if (i < middle){
          left.push_back(data[i]);
        }
          else{
          right.push_back(data[i]);
        }
        }
 
  if(left.size() > 1 )
        mergesort(left);
  if(right.size() > 1)
        mergesort(right);
       
  data = merge(left, right);
 
 
}
 
vector<int> merge(vector<int> &left, vector<int> &right) {
       
        vector<int> result;
       
        while (right.size() > 0 || left.size() > 0 ) {
               
                if ( right.size() > 0 && left.size() > 0){
                       
                        if ( left[0] <= right[0]) {
                                result.push_back(left[0]);
                                left.erase(left.begin());
                        }
                        else {
                                result.push_back(right[0]);
                                right.erase(right.begin());
                        }
                }
                else if (right.size() > 0){
                                result.push_back(right[0]);
                                right.erase(right.begin());
                        }
                else if (left.size() > 0){
                                result.push_back(left[0]);     
                                left.erase(left.begin());
                        }
                }
        return result;
       
}
void mystery_sort(vector<int> &data)
{
	int a,b,c;
	int length = data.size();
		for( a=1; a<length; a++)
		{
			b=a;
			while( b > 0 && data[b-1] > data[b])
			{
				c = data[b];
				data[b] = data[b-1];
				data[b-1] = c;
				b--;
			}
		}
  

}

