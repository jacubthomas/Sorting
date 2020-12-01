#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;

int* find_min ( int *start, int *end )
{

    // pointer arithmetic, if list is length 1, base case
    if( end - start == 1 )
    {
        return start;
    }
    
    // recursive call to find minimum of the remainder of the list
    int* m = find_min( start + 1, end );
   
    return *m < *start ? m : start;
}

void selection_sort( int *start, int *end )
{
    // base case: list of length one is sorted
    if( end - start == 1)
    {
        return;
    }
    // find the minimum of the rest of the list
    int* m = find_min( start+1, end );
    
    // if the minimum is less than the first item, swap
    if( *m < *start )
    {
        swap( *m, *start );
    }
    
    // recurse
    selection_sort( start + 1, end );
}

int main( int argc, char const *argv[] )
{
    int test[10] = { 9,8,7,6,5,4,3,2,1,0 };
    for(int i= 0; i < 10; i++)
    {
        cout << test[i] << endl;
    }
    selection_sort( test, test + 10);
    for(int i=0; i<10; i++)
    {
        cout << test[i] << endl;
        
    }
    return 0;
}

/*
    Alternative find_min()
     
    int* temp = start;
    int* min = start;
    while( temp < end )
    {
        if( *temp < *min )
        {
            min = temp;
        }
        temp++;
    }
    return min;
    */
    /*
       if( *m < *start )
       {
           return m;
       }
       else
       {
           return start;
       }
   */
