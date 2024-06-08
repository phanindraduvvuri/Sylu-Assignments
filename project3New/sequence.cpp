/// @name Allu Sylender Reddy



#include "Sequence.h"

/// Initializing a new sequence
Sequence::Sequence(size_type size) {
    for (size_type i = 0; i < size; i++)
        push_back(0);

}


/// Initializing a new sequence
Sequence::Sequence(const Sequence &sequence) {
    SequenceNode *current_head = sequence.head;
    while (current_head) {
        push_back(current_head->elt);
        current_head = current_head->next;
    }

}

/// clearing the sequence
Sequence::~Sequence() {
    clear();
}


/// Overriding the equals (=) operator.
Sequence &Sequence::operator=(const Sequence &sequence) {
    if (this != &sequence) {
        clear();
        SequenceNode *current_head = sequence.head;
        while (current_head) {
            push_back(current_head->elt);
            current_head = current_head->next;
        }
    }
    return *this;
}


/// Overriding the ([]) operator
Sequence::value_type &Sequence::operator[](size_type position) {
    if (position >= num_elements) {
        throw exception();
    }

    SequenceNode *current = head;

    for (size_type i = 0; i < position; ++i) {
        current = current->next;
    }

    return current->elt;
}


/// Function to push_back new value into the back of the sequence
void Sequence::push_back(const value_type &value) {
    auto *new_node = new SequenceNode(value);
    new_node->prev = tail;
    new_node->next = nullptr;
    if (tail)
        tail->next = new_node;

    tail = new_node;

    if (!head)
        head = new_node;

    num_elements++;
}

/// Function to pop_back values from sequence
void Sequence::pop_back() {
    if (num_elements <= 0)
        throw exception();

    SequenceNode *to_remove_nodes = tail;
    tail = tail->prev;
    delete to_remove_nodes;

    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    num_elements--;
}

/// Function to insert a value a specific position
void Sequence::insert(size_type position, value_type value) {
    if (position > num_elements)
        throw exception();

    if (position == num_elements)
        push_back(value);
    else {
        SequenceNode *curr_node = head;
        for (size_type i = 0; i < position; i++) {
            curr_node = curr_node->next;
        }

        auto *new_node = new SequenceNode(value);
        new_node->prev = curr_node->prev;
        new_node->next = curr_node;

        if (curr_node->prev)
            curr_node->prev->next = new_node;
        else
            head = new_node;

        curr_node->prev = new_node;
        num_elements++;
    }
}

const Sequence::value_type &Sequence::front() const {
    if (num_elements == 0)
        throw exception();

    return head->elt;
}

const Sequence::value_type &Sequence::back() const {
    if (num_elements == 0)
        throw exception();

    return tail->elt;
}

bool Sequence::empty() const {
    return num_elements == 0;
}

Sequence::size_type Sequence::size() const {
    return num_elements;
}

void Sequence::clear() {

    while (num_elements > 0)
        pop_back();
}

/// Erase a sequence
void Sequence::erase(size_type position, size_type count) {
    if (position >= num_elements || position + count >= num_elements)
        throw exception();

    if (count == 0)
        return;

    // Getting to the start node
    SequenceNode *start_node = head;
    for (size_type i = 0; i < position; i++)
        start_node = start_node->next;

    // Getting to the end node
    SequenceNode *end_node = head;
    for (size_type i = 0; i < (position + count - 1); i++)
        end_node = end_node->next;

    if (start_node->prev)
        start_node->prev->next = end_node->next;
    else
        head = end_node->next;

    if (end_node->next)
        end_node->next->prev = start_node->prev;
    else
        tail = start_node->prev;

    // delete nodes from start to end
    while (start_node != end_node) {
        SequenceNode *node_to_remove = start_node;
        start_node = start_node->next;
        delete node_to_remove;
    }

    delete end_node;
    num_elements -= count;
}

/// Place code for printing sequence here (well not here, inside the method)
void Sequence::print(ostream &os) const {
    SequenceNode* curr_node = head;

    os << "<";
    while (curr_node) {
        if (curr_node->next)
            os << curr_node->elt << ", ";
        else
            os << curr_node->elt;

        curr_node = curr_node->next;
    }

    os << ">" << endl;
}

// Don't modify, do the output in the print() method
ostream &operator<<(ostream &os, const Sequence &s) {
    s.print(os);
    return os;
}

