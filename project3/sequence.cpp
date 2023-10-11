#include "Sequence.h"

Sequence::Sequence(size_type sz) {
    for (size_type i = 0; i < sz; i++)
        push_back(0);

}

Sequence::Sequence(const Sequence &s) {
    SequenceNode *currHead = s.head;
    while (currHead) {
        push_back(currHead->elt);
        currHead = currHead->next;
    }

}

Sequence::~Sequence() {
    clear();
}

Sequence &Sequence::operator=(const Sequence &s) {
    if (this != &s) {
        clear();
        SequenceNode *currHead = s.head;
        while (currHead) {
            push_back(currHead->elt);
            currHead = currHead->next;
        }
    }
    return *this;
}

Sequence::value_type &Sequence::operator[](size_type position) {
    if (position >= numElts) {
        throw exception();
    }

    SequenceNode *current = head;

    for (size_type i = 0; i < position; ++i) {
        current = current->next;
    }

    return current->elt;
}

void Sequence::push_back(const value_type &value) {
    auto *newNode = new SequenceNode(value);
    newNode->prev = tail;
    newNode->next = nullptr;
    if (tail)
        tail->next = newNode;

    tail = newNode;

    if (!head)
        head = newNode;

    numElts++;
}

void Sequence::pop_back() {
    if (numElts <= 0)
        throw exception();

    SequenceNode *toRemoveNode = tail;
    tail = tail->prev;
    delete toRemoveNode;

    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    numElts--;
}

void Sequence::insert(size_type position, value_type value) {
    if (position > numElts)
        throw exception();

    if (position == numElts)
        push_back(value);
    else {
        SequenceNode *currNode = head;
        for (size_type i = 0; i < position; i++) {
            currNode = currNode->next;
        }

        SequenceNode *newNode = new SequenceNode(value);
        newNode->prev = currNode->prev;
        newNode->next = currNode;

        if (currNode->prev)
            currNode->prev->next = newNode;
        else
            head = newNode;

        currNode->prev = newNode;
        numElts++;
    }
}

const Sequence::value_type &Sequence::front() const {
    if (numElts == 0)
        throw exception();

    return head->elt;
}

const Sequence::value_type &Sequence::back() const {
    if (numElts == 0)
        throw exception();

    return tail->elt;
}

bool Sequence::empty() const {
    return numElts == 0;
}

Sequence::size_type Sequence::size() const {
    return numElts;
}

void Sequence::clear() {

    while (numElts > 0)
        pop_back();
}

void Sequence::erase(size_type position, size_type count) {
    if (position >= numElts || position + count >= numElts)
        throw exception();

    if (count == 0)
        return;

    // Getting to the start node
    SequenceNode *startNode = head;
    for (size_type i = 0; i < position; i++)
        startNode = startNode->next;

    // Getting to the end node
    SequenceNode *endNode = head;
    for (size_type i = 0; i < (position + count - 1); i++)
        endNode = endNode->next;

    if (startNode->prev)
        startNode->prev->next = endNode->next;
    else
        head = endNode->next;

    if (endNode->next)
        endNode->next->prev = startNode->prev;
    else
        tail = startNode->prev;

    // delete nodes from start to end
    while (startNode != endNode) {
        SequenceNode *nodeToRemove = startNode;
        startNode = startNode->next;
        delete nodeToRemove;
    }

    delete endNode;
    numElts -= count;
}

// Place code for printing sequence here (well not here, inside the method)
void Sequence::print(ostream &os) const {
    SequenceNode* currNode = head;

    os << "<";
    while (currNode) {
        if (currNode->next)
            os << currNode->elt << ", ";
        else
            os << currNode->elt;

        currNode = currNode->next;
    }

    os << ">" << endl;
}

// Don't modify, do the output in the print() method
ostream &operator<<(ostream &os, const Sequence &s) {
    s.print(os);
    return os;
}

