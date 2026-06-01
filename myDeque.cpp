template <typename typeInElement> struct element{
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
        deque(); //
        ~deque(); //
        void pushFront(type x); //
        void pushBack(type x);
        void popFront(); //
        void popBack();
        type front(); // 
        type back();
        long long int getSize(); //
        bool empty(); //
};
template <typename type> deque<type>::deque(){
    size = 0;
    firstElement = nullptr;
    lastElement = nullptr;
}
template <typename type> deque<type>::~deque(){
    for (int i = 0; i < size; i++){
        element<type> *cur = firstElement;
        firstElement = (*cur).back;
        delete cur;
    }
}
template <typename type> void deque<type>::pushFront(type x){
    if (size == 0){
        element<type> *cur = new element<type>();
        (*cur).value = x;
        (*cur).front = nullptr;
        (*cur).back = nullptr;
        firstElement = cur;
        lastElement = cur;
        size = size + 1;
    }else{
        element<type> *cur = new element<type>();
        (*cur).value = x;
        (*cur).front = nullptr;
        (*cur).back = firstElement;
        (*firstElement).front = cur;
        firstElement = cur;
        size = size + 1;
    }
}
template <typename type> void deque<type>::pushBack(type x){
    if (size == 0){
        element<type> *cur = new element<type>();
        (*cur).value = x;
        (*cur).front = nullptr;
        (*cur).back = nullptr;
        firstElement = cur;
        lastElement = cur;
        size = size + 1;
    }else{
        element<type> *cur = new element<type>();
        (*cur).value = x;
        (*cur).front = lastElement;
        (*cur).back = nullptr;
        (*lastElement).back = cur;
        lastElement = cur;
        size = size + 1;
    }
}
template <typename type> void deque<type>::popFront(){
    if (size == 1){
        firstElement = nullptr;
        lastElement = nullptr;
        size = size - 1;
    }else{
        element<type> *cur = firstElement;
        firstElement = (*cur).back;
        delete cur;
        size = size - 1;
    }
}
template <typename type> void deque<type>::popBack(){
    if (size == 1){
        firstElement = nullptr;
        lastElement = nullptr;
        size = size - 1;
    }else{
        element<type> *cur = lastElement;
        lastElement = (*cur).front;
        delete cur;
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
