#pragma once
#include "header.h"

Node* createNode(int data);
void addTail(Node* &pHead, int data);
void changePosData(Node* &pHead, int pos, int data);
int getData(Node* &pHead, int pos);