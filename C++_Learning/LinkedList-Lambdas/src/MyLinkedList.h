//#pragma once
#include <string>
#include <memory>


//class template
template<typename ValueType>
class LL_Member {
public:
    ValueType value;
    std::unique_ptr<LL_Member<ValueType>> next;

    LL_Member(ValueType val) {
        this->value = val;
        this->next = nullptr;
    };
};

template<typename ValueType>
class MyLinkedList {
public:
    std::unique_ptr<LL_Member<ValueType>> start;
    LL_Member<ValueType> *end;
    unsigned long length;

    // insert the given number at the end of the list
    void insert(ValueType value) {
        if (!this->start) {
            this->start = std::make_unique<LL_Member<ValueType>>(value);
            this->end = this->start.get();
        } else {
            this->end->next = std::make_unique<LL_Member<ValueType>>(value);
            this->end = this->end->next.get();
        }
        this->length++;
    }

    // returns true if the element was found
    bool includes(ValueType val) {
        // just a local variable that doesn't need to be unique_ptr
        LL_Member<ValueType> *current = this->start.get();
        for (unsigned long i = 0; i < this->length; i++) {
            if (val == current->value)
                return true;
            current = current->next.get();
        }
        return false;
    };

    // returns true if the element was found and removed
    bool remove(ValueType val) {
        LL_Member<ValueType> * current = this->start.get();
        LL_Member<ValueType> * previous = nullptr;
        for (unsigned long i = 0; i < this->length; i++) {
            if (current->value == val) {
                // check whether list holds more than one element
                if (this->length > 1) {
                    if (previous) {
                        previous->next = std::move(current->next);
                        // update end pointer if necessary
                        if (current == this->end)
                            this->end = previous;
                    } else {
                        // removing first element
                        this->start = std::move(this->start->next);
                    }
                } else
                    this->start = nullptr;

                this->length--;
                return true;
            }
            previous = current;
            current = current->next.get();
        }
        return false;
    };

    std::string toString() {
        std::string str = "[";
        LL_Member<ValueType> *current = this->start.get();
        for (unsigned long i = 0; i < this->length; i++) {
            str += std::to_string(current->value);
            if (i != this->length - 1)
                str += ",";
            current = current->next.get();
        }
        str += "]";
        return str;
    };

    MyLinkedList() {
        this->start = nullptr;
        this->end = nullptr;
        this->length = 0;
    };

};
