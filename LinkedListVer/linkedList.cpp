#include "linkedList.h"

Node* createNode(int data){
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	return p;
}

void addTail(Node* &pHead, int data){
	if(pHead == NULL){
		pHead = createNode(data);
	}
	else{
		Node* p = pHead;
		while(p->pNext){
			p = p->pNext;
		}
		p->pNext = createNode(data);
	}
}

void changePosData(Node* &pHead, int pos, int data){
    Node* p = pHead;
    for(int i = 0; i <= pos; i++){
        if(i == pos){
            p->data = data;
        }
        p = p->pNext;
    }
}

int getData(Node* &pHead, int pos){//pHead: y, pos: x
    int dataGot;
    Node* p = pHead;
    for(int i = 0; i <= pos; i++){
        if(i == pos){
            dataGot = p->data;
        }
        p = p->pNext;
    }
    return dataGot;
}