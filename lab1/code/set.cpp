#include "set.hpp"

#include <algorithm>  //std::swap

/*
* std::size_t is defined in the C++ standard library
* std::size_t is an unsigned integer type that can store the maximum size of any possible object
* sizes are non-negative integers -- i.e. unsigned integer type
*/

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ************************************ */

// Default constructor
Set::Set() : head{new Node{0, nullptr}}, counter{0} {  // create the dummy node
}

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {
    insert(x);
}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() {
    for (int x : elements)
        insert(x);
}

// copy constructor
Set::Set(const Set& rhs) : Set() {
    Node* ptr = head;
    Node* ptr2 = rhs.head->next;

    while(ptr2 != nullptr) {
        ptr->next = new Node{ptr2->value, nullptr};
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    counter = rhs.counter;

}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) {

    std::swap(head, rhs.head);
    std::swap(counter, rhs.counter);
    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    Node* ptr = head;
    // We work with a temporary pointer to stay on the safe side.
    while(ptr != nullptr) {
        Node* tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    counter = 0;
}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    return counter;
}

// Test if set is empty
bool Set::empty() const {
    if (head->next == nullptr && counter == 0) {
        return true;
    }
    return false;
}

// Test if x is an element of the set
bool Set::member(int x) const {
    // Starting to step through, while it's not nullptr and the value is less than x, we continue stepping through.
    // If it's not nullptr and the value is equal to x, we return true.
    Node* ptr = head->next;
    while(ptr != nullptr && ptr->value < x) {
        ptr = ptr->next;
    }
    if (ptr == nullptr || ptr->value != x) {
        return false;
    } else {
        return true;
    }
}

// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const {
    
    Node* ptr = head->next;
    Node* ptr2 = b.head->next;

    while(ptr != nullptr && ptr2 != nullptr) {
        if (ptr->value < ptr2->value) {
            return false;
        } else if (ptr->value == ptr2->value) {
            ptr = ptr->next;
            ptr2 = ptr2->next;
        } else {
            ptr2 = ptr2->next;
        }
    }
    if (ptr == nullptr) {
        return true;
    } else {
        return false;
    }
}
// Return a new Set representing the union of Sets *this and b
// Repeated values are not allowed
// Implement an algorithm similar to the one in exercise 3/Set 1, but don't use vectors
Set Set::set_union(const Set& b) const {
    Node* ptr = head->next; // *this
    Node* ptr2 = b.head->next; // b
    Set S3{}; // new set

    while(ptr != nullptr && ptr2 != nullptr) {
        if (ptr->value < ptr2->value) {
            S3.insert(ptr->value);
            ptr = ptr->next;
        } else if (ptr->value == ptr2->value) {
            S3.insert(ptr->value);
            ptr = ptr->next;
            ptr2 = ptr2->next;
        } else {
            S3.insert(ptr2->value);
            ptr2 = ptr2->next;
        }
    }
    if (ptr == nullptr) {
        while(ptr2 != nullptr) {
            S3.insert(ptr2->value);
            ptr2 = ptr2->next;
        }
    } else {
        while(ptr != nullptr) {
            S3.insert(ptr->value);
            ptr = ptr->next;
        }
    }
    return S3;
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

std::ostream& operator<<(std::ostream& os, const Set& rhs) {
    if (rhs.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* ptr = rhs.head->next;
        os << "{ ";

        while (ptr != nullptr) {
            os << ptr->value << " ";
            ptr = ptr->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

void Set::insert(int x) {
    Node* ptr = head->next;
    while(ptr != nullptr && ptr->value < x) {
        ptr = ptr->next;
    }
    if (ptr == nullptr || ptr->value != x) {
        Node* tmp = new Node(x, ptr);
        head->next = tmp;
        ++counter;
    }
}
