// Paolo Vicencio, pjv7nd, 2/21/21, List.cpp
#include <iostream>
#include "List.h"
using namespace std;

List :: List() {
    count = 0;
    head = new ListNode();
    tail = new ListNode();

    tail->previous = head;
    head->next = tail;

    tail->next = NULL;
    head->previous = NULL;


}

// creating a NEW list from an existing one
List :: List(const List& source) {
	head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List :: ~List() {
	// not sure what to put here just yet
    makeEmpty();
    delete head;
    delete tail;
}

// setting an existing list equal to another
List& List :: operator=(const List& source) {
	if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List :: isEmpty() const {
	if (tail->previous == head && head->next == tail) {
        return true;
    }
    else {
        return false;
    }
}

void List :: makeEmpty() {
    ListItr iterator = ListItr(head);
    ListItr iterator2 = ListItr(tail);
    iterator.moveForward();
    iterator2.moveBackward();
    while (iterator.isPastEnd() != true) {
        iterator.current->next = NULL;
        iterator.current->previous = NULL;
        iterator.moveForward();
    }
    while (iterator2.isPastBeginning() != true) {
        iterator2.current->next = NULL;
        iterator2.current->previous = NULL;
        iterator2.moveBackward();
    }

}

ListItr List :: first() {
    ListItr iterator = ListItr(head);
    iterator.moveForward();
    return iterator;

}

ListItr List :: last() {
    ListItr iterator =  ListItr(tail);
    iterator.moveBackward();
    return iterator;
    
}

void List :: insertAfter(int x, ListItr position) {
    count++;
    ListNode *newNode = new ListNode();
    newNode->value = x;
    newNode->next = position.current->next;
    newNode->previous = position.current;

    position.current->next->previous = newNode;
    position.current->next = newNode;


}

void List :: insertBefore(int x, ListItr position) {
    count++;
    ListNode *newNode = new ListNode();
    newNode->value = x;
    newNode->next = position.current;
    newNode->previous = position.current->previous;

    position.current->previous->next = newNode;
    position.current->previous = newNode;

}

void List :: insertAtTail(int x) {
    ListNode *newNode = new ListNode();
    // assigning the new node a value
    newNode->value = x;
    // making the new node's next pointer point to the tail
    newNode->next = tail;
    // making the new node's previous pointer point to the tails old previous pointer
    newNode->previous = tail->previous;
    // making the new nodes previous node's next pointer point to the new node
    tail->previous->next = newNode;
    // making the tails new previous pointer point to the new node
    tail->previous = newNode;
    count++;
}


ListItr List :: find(int x) {
    ListItr iterator = ListItr(head);
    ListItr iterator2 = ListItr(tail);
    iterator.moveForward();
    while (iterator.isPastEnd() != true) {
        if (iterator.current->value == x) {
            return iterator;
        }
        else {
            iterator.moveForward();
        }
    }
    return iterator2;

}



void List :: remove(int x) {
    ListItr iterator = first();
    while (iterator.isPastEnd() != true) {
        if (iterator.current->value == x) {
            iterator.current->previous->next = iterator.current->next;
            iterator.current->next->previous = iterator.current->previous;
            
            iterator.current->next = NULL;
            iterator.current->previous = NULL;
            iterator.current->value = 0;
            
            count--;
        }
        else {
            iterator.moveForward();
        }
    }
}

int List :: size() const {
    return count;
}

void printList(List& source, bool forward) {
    // source.first();
    // source.last();
    // printing forwards to backwards
    ListItr firstItr = ListItr(source.first());
    ListItr lastItr = ListItr(source.last());


    if (forward == true) {
        while (firstItr.isPastEnd() == false) {
            cout << firstItr.retrieve() << " " ;
            firstItr.moveForward();
        }
    }
    // printing backwards to forwards
    else {
        while (lastItr.isPastBeginning() == false) {
            cout << lastItr.retrieve() << " " ;
            lastItr.moveBackward();
        }
    }
    cout<<endl;

}
















