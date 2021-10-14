//
//  main.cpp
//  UnchainedHashTable
//
//  Created by Ryan Scott on 10/14/21.
//  This is a hash table that uses chaining to handle collisons
//  It uses an int type variable
#include <list>
#include <iostream>
using namespace std;

class Hash {
    int BUCKET; // No. of buckets
    
    // Point to an array containing buckets
    list<int> *table;
public:
    Hash(int V); // Constructor
    
    // inserts key into hash table
    void insertItem(int x);
    
    // deletes key from hash table
    void deleteItem(int key);
    
    // has function to map values to keys
    int hashFunction(int x){
        return (x % BUCKET);
    }
    
    void displayHash();
};// Hash class

Hash::Hash(int b){
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}// Hash

void Hash::insertItem(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}// InsertItem

void Hash::deleteItem(int key){
    // get the hash index of key
    int index = hashFunction(key);
    
    // find the key in (index)th list
    list <int> :: iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++){
        if (*i == key)
            break;
    }// for
    
    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
    
}// deleteItem

// function to display hash table
void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++){
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }// for
}// displayHash

int main(int argc, const char * argv[]) {
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);
    
    // insert the keys into the hash table
    Hash h(7); // 7 is the count of buckets in the hash table
    
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);
    
    // delete 12 from the hash table
    h.deleteItem(12);
    
    // display the Hash table
    h.displayHash();
    
    return 0;
}
