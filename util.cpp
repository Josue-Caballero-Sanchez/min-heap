#include "util.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int CheckFile(){
    int size;
    int count = 0;
    string line;
    ifstream file("HEAPinput.txt");

    if(file.is_open()){
        getline(file, line);
        size = stoi(line);
        
        while(getline(file, line)){
            count++;
        }
        file.close();
    }
    else{
        cout << "There was a problem opening file HEAPinput.txt for reading.\n";
        return -1;
    }

    if(count != size){
        cout << "The number of elements in file is less than as specified in the beginning of file.\n";
        return 0;
    }
    return 1;
}

int GetSize(){
    int size;
    string line;
    ifstream file("HEAPinput.txt");

    if(file.is_open()){
        getline(file, line);
        size = stoi(line);
        file.close();
    }
    return size;
}

element* ReadFile(){
    int size;
    int nums;
    int i = 1;
    element* e;
    string line;
    ifstream readFile("HEAPinput.txt");

    if(readFile.is_open()){
        getline(readFile, line);
        size = stoi(line);
        e = new element[size +1];

        while(getline(readFile, line)){
            nums = stoi(line);
            e[i].key = nums;
            i++;
        }

        readFile.close();
    }
    return e;
}

int nextCommand(int *i, int *v, int *f, int *n, int *k){
    char c;
    while(1){
        scanf("%c", &c);
        if(c == ' ' || c == '\t' || c == '\n'){
            continue;
        }
        if(c == 'S' || c == 'R' || c == 'W' || c == 's' || c == 'r' || c == 'w'){
            break;
        }
        if(c == 'K' || c == 'k'){
            scanf("%d", f);
            scanf("%d", i);
            scanf("%d", v); 
            break;
        }
        if(c == 'C' || c == 'c'){
            scanf("%d", n);
            break;
        }
        if(c == 'I' || c == 'i'){
            scanf("%d", f);
            scanf("%d", k);
            break;
        }
        if(c == 'D' || c == 'd'){
            scanf("%d", f);
            break;
        }
        cout << "Invalid Command\n";
    }
    return c;
}

int main(){
    char c;
    int i;
    int v;
    int f;
    int n;
    int k;
    int check;
    int deleteMin;

    heap *h = new heap();

    while(1){
        c = nextCommand(&i, &v, &f, &n, &k);
        switch(c){
            case 's':
            case 'S': 
                printf("COMMAND: %c.\n", c);
                printf("Terminating program\n");
                exit(0);

            case 'k':
            case 'K':
                printf("COMMAND: %c %d %d %d.\n", c, f, i, v);
                h->DecreaseKey(*h, f, i, v);
                break;
            
            case 'r':
            case 'R':
                printf("COMMAND: %c.\n", c);

                check = CheckFile();
                if(check != 1){
                    break;
                } 
                h->BuildHeap(h, ReadFile(), GetSize());
                break;

            case 'w':
            case 'W':
                printf("COMMAND: %c.\n", c);
                h->PrintHeap(*h);
                break;

            case 'c':
            case 'C':
                printf("COMMAND: %c %d.\n", c, n);
                *h = h->Initialize(n);
                break;

            case 'i':
            case 'I':
                printf("COMMAND: %c %d %d.\n", c, f, k);
                h->Insert(h, f, k);
                break;

            case 'd':
            case 'D':
                printf("COMMAND: %c %d.\n", c, f);

                deleteMin = h->DeleteMin(h, f).key;
                if(deleteMin != -1234567){
                    cout << deleteMin << endl;
                }
                break;

            default:
                break;
        }
    }
}