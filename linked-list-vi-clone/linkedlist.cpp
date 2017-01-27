//
//  linkedlist.cpp
//  linked-list-vi-clone
//
//  Created by Alexander Cochrane on 2017-01-24.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "linkedlist.hpp"

void linkedlist::add(std::string data) {
    Node* node;
    
    if (head == NULL) {
        head = new Node(data);
        node = head;
    }
    else {
        node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        Node* newNode = new Node(data);
        node->next = newNode;
    }
    
}

linkedlist::Node* linkedlist::get(int index) {
    if (head==NULL) throw std::exception();
    if (index==0) return head;
    Node* node = head;
    for (int i = 0; i < index; i++) {
        if (node->next==NULL) {
            throw std::exception();
        }
        node = node->next;
    }
    return node;
}

void linkedlist::insert(int index, std::string data) {
    if (head==NULL) throw std::exception();
    Node* node = head;
    int i;
    try {
        for (i = 0; i < index; i++) {
            if (node->next==NULL) {
                throw std::exception();
            }
            node = node->next;
        }
    }
    catch (...) {
        if (i>=index-1) {
            add(data);
            return;
        }
        else {
            throw std::exception();
        }
    }
    Node* newNode;
    newNode->data = data;
    
    if (node->next!=NULL) {
        newNode->next = node->next;
    }
    
    node->next = newNode;
}

void linkedlist::remove(int index) {
    if (head==NULL) {
        throw std::exception();
    }
    if (index==0) {
        removeHead();
        return;
    }
    Node* node = head;
    Node* prevNode = nullptr;
    for (int i = 0; i < index; i++) {
        if (node->next==NULL) {
            throw std::exception();
        }
        prevNode = node;
        node = node->next;
    }
    prevNode->next = node->next;
    free(node);
}

void linkedlist::removeHead() {
    Node* temp = head;
    head = head->next;
    free(temp);
}

void linkedlist::replace(int index, std::string data) {
	if (head == NULL) throw std::exception();
	Node* node = head;
	for (int i = 0; i < index; i++) {
		if (node->next == NULL) {
			throw std::exception();
		}
		node = node->next;
	}
	node->data = data;
}
