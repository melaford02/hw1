#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}






// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if(head_ == nullptr){
    head_ = new Item();
    head_->val[0] = val;
    head_->first = 0;
    head_->last = 1;
    tail_ = head_;
} else {
  int temp = tail_->last;
  if(temp < ARRSIZE){
    tail_->val[temp] = val;
    int newLast = temp + 1;
    tail_->last = newLast;
  
} else {
  Item* node = new Item();
  node->val[0] = val;
  node->first = 0;
  node->last = 1;
  Item* currentTail = tail_;
  node->prev = currentTail;
  currentTail->next = node;
  tail_ = node;
}
}
size_++;
}

void ULListStr::push_front(const std::string& val) {
    if(head_ == nullptr) {
  
        Item* node = new Item();
        node->first = ARRSIZE - 1;
        node->last = ARRSIZE;
        node->val[ARRSIZE - 1] = val;
        head_ = node;
        tail_ = node;
    }
    else if(head_->first > 0) {
       int newFirst = head_->first - 1;
        head_->first = newFirst;
        head_->val[newFirst] = val;
    }
    else {
        
        Item* node = new Item();
        node->first = ARRSIZE - 1;
        node->last = ARRSIZE;
        node->val[node->first] = val;
        node->next = head_;
        head_->prev = node;
        head_ = node;
    }
    size_++;
}

void ULListStr::pop_back() {
  if (head_ == nullptr){
    return;
  }

  tail_->last = tail_->last - 1;
  size_ = size_ - 1;

  if(tail_->first >= tail_->last){
    Item* delete_later = tail_;
    Item* newTail = tail_->prev;
    tail_ = newTail;

    if(newTail != nullptr){
      newTail->next = nullptr;
    } else{
      head_ = nullptr;
    }
    delete delete_later;
  }
    }

void ULListStr::pop_front() {
    if(head_ == nullptr){
      return;
    }

    if (head_->first < head_->last){
      head_->first++;
    }

    if(size_ > 0){
      size_--;
    }

    
    if(head_->first >= head_->last) {
        Item* oldHead = head_;
        Item* nextNode = head_->next;
        head_ = nextNode;
        
        if(head_ != nullptr) {
            head_->prev = nullptr;
        } else {
            tail_ = nullptr;
        }
        delete oldHead;
    }
}

std::string const & ULListStr::back() const {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
    if(loc >= size_) return nullptr;

    Item* cur = head_;
    size_t idx = loc;

    while(cur != nullptr) {
        size_t count = cur->last - cur->first;
        if(idx < count) {
            return &cur->val[cur->first + idx];
        }
        idx -= count;
        cur = cur->next;
    }
    return nullptr;
}






void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
