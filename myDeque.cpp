template <typename typeInElement> struct element{ // struct, that will be used as element of stack
    element* back;
    typeInElement value;
    element* front;
};
template <typename type> class deque{
    private:
        element<type>* firstElement;
        element<type>* lastElement;
        long long int size;
    public:
        deque(); // constructor
        ~deque(); // destructor
        void pushFront(type x); // add new element to the start of deque
        void popFront(); // delete first element
        void pushBack(type x); // add new element to the end of deque
        void popBack(); // delete last element
        type front(); // return value of first element
        type back(); // return value of last element
        long long int getSize(); // return size
        bool empty(); // check if deque is empty
};
template <typename type> deque<type>::deque(){
    size = 0;
    firstElement = nullptr;
    lastElement = nullptr;
}
template <typename type> deque<type>::~deque(){
    for (int i = 0; i < size; i++){ // delete size elements, because deque include size elements, when we delete size elements, deque becomes empty
        element<type> *cur = firstElement;
        firstElement = (*cur).back;
        delete cur;
    }
}
template <typename type> void deque<type>::pushFront(type x){
    if (size == 0){ // if size == 0 firstElement and lastElement have to be the same
        element<type> *cur = new element<type>; // allocate memory for new element
        (*cur).value = x;
        (*cur).front = nullptr;
        (*cur).back = nullptr;
        firstElement = cur;
        lastElement = cur;
        size = size + 1;
    }else{
        element<type> *cur = new element<type>; // allocate memory for new element
        (*cur).value = x;
        (*cur).front = nullptr;
        (*cur).back = firstElement;
        (*firstElement).front = cur;
        firstElement = cur;
        size = size + 1;
    }
}
template <typename type> void deque<type>::popFront(){
    if (size <= 0){ // if size == 0 return
        return;
    }else if (size == 1){ // if size == 1 queue becomes empty
        firstElement = nullptr;
        lastElement = nullptr;
        size = size - 1;
    }else{
        element<type> *cur = firstElement;
        firstElement = (*cur).back;
        delete cur; //deallocate memory of first element
        size = size - 1;
    }
}
template <typename type> void deque<type>::pushBack(type x){
    if (size == 0){ // if size == 0 firstElement and lastElement have to be the same
        element<type> *cur = new element<type>; // allocate memory for new element
        (*cur).value = x;
        (*cur).front = nullptr;
        (*cur).back = nullptr;
        firstElement = cur;
        lastElement = cur;
        size = size + 1;
    }else{
        element<type> *cur = new element<type>; // allocate memory for new element
        (*cur).value = x;
        (*cur).front = lastElement;
        (*cur).back = nullptr;
        (*lastElement).back = cur;
        lastElement = cur;
        size = size + 1;
    }
}
template <typename type> void deque<type>::popBack(){
    if (size <= 0){ // if size == 0 return
        return;
    }else if (size == 1){ // if size == 1 queue becomes empty
        firstElement = nullptr;
        lastElement = nullptr;
        size = size - 1;
    }else{
        element<type> *cur = lastElement;
        lastElement = (*cur).front;
        delete cur; // deallocate memory of last element
        size = size - 1;
    }
}
template <typename type> type deque<type>::front(){
    return (*firstElement).value;
}
template <typename type> type deque<type>::back(){
    return (*lastElement).value;
}
template <typename type> long long int deque<type>::getSize(){
    return size;
}
template <typename type> bool deque<type>::empty(){
    if (size == 0){
        return 1;
    }else{
        return 0;
    }
}
