#include <bits/stdc++.h>
using namespace std;


/**
    Implement a min-heap below, by completing the un-implemented functions.
    You can assume that the heap will not contain more than
    10^5 (i.e. 100000) elements.

    You can add as many variables within the heap structure
    as you need.
*/
struct Heap{
     int ara[100000];
     int sz;
    /**
        If the variables within the heap structure need any form of
        initialization, you can initialize the variables within the
        constructor below. If no initialization is needed, leave it
        blank.
    */
    Heap(){
        sz = 0;
    }


    /**
        Add a new value to the heap using the following function.
    */

    void insertValue(int v){
        sz++;
        ara[sz] = v;
        int i = sz;

        while(i!=1 && ara[i]<ara[i/2]){
            swap(ara[i],ara[i/2]);
            i = i/2;
        }
    }

    /**
        Return the minimum number in the heap.
        You can assume that the heap is not empty.

        The minimum number should NOT be removed from
        the heap by the getMin function.
    */

    int getMin(){
        return ara[1];
    }
    /**
        Delete the minimum value from the heap.
    */

    void deleteMin(){
        int i,j;
        swap(ara[1],ara[sz]);
        sz--;
        i = 1;
        j = 2*i;

        if(j==sz){
        if(ara[i]>ara[j]){
            swap(ara[i],ara[sz]);
        }
       }

        while(j<sz){
            if(ara[j+1]<ara[j]){
                j++;
            }
            if(ara[i]>ara[j]){
                swap(ara[i],ara[j]);
                i=j;
                j=2*j;

            }else{
               break;
            }
        }
    }
};
