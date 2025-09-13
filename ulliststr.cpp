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
  //create new node
  head_ = new Item();
  head_->val[0] = val;
  head_->first = 0;
  head_->last = 1;
  tail_ = head_;
} else {
  int temp = tail_->last;

  //if there is room add to tail node
  if(temp < ARRSIZE){
  std::string toInsert = val;
  tail_->val[temp] = toInsert;
  tail_->last = tail_->last + 1;

  
  //or create a new tail node
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
// std::cout << "push back: " << val << std::endl;
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

void ULListStr::pop_back() 
{
  if (head_ == nullptr){
    return;
  }

  tail_->last = tail_->last - 1;
  --size_;

  if(tail_->first >= tail_->last){
    Item* tmp = tail_;
    Item* newTail = tail_->prev;
    tail_ = newTail;

    if(newTail != nullptr){
      newTail->next = nullptr;
    } else{
      head_ = nullptr;
    }
    delete tmp;
  }
    }

void ULListStr::pop_front() {
    if(head_ == nullptr){
      //nothing to pop
      return;
    }

if(head_->first < head_->last){
  head_->first = head_->first + 1;
  size_ = size_ - 1;
}


    //removes head ptr?
    if(head_->first >= head_->last) {
        Item* oldHead = head_;
        Item* nextNode = head_->next;
        head_ = nextNode;
        
        if(head_ != nullptr) {
            head_->prev = nullptr;
        } else {
            tail_ = nullptr;
        }
        //double check head reset correctly
        delete oldHead;
    }
}

std::string const & ULListStr::back() const {
    if(head_ == nullptr && tail_ == nullptr){
      throw std::out_of_range("empty list");
    }

    int lastItemIdx = tail_->last;
    int backPos = lastItemIdx - 1;

    return tail_->val[backPos];
}

std::string const & ULListStr::front() const {
    if(head_ == nullptr){
      throw std::out_of_range("empty list");
    }

    int firstIdx = head_->first;

    return head_->val[firstIdx];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
    if(loc >= size_){
      return nullptr;
    } 

    Item* cur = head_;
    size_t idx = loc;

    bool found = false;
    std::string* result = nullptr;

    //go thru each item node
    while(cur != nullptr && !found)
    {
      size_t numElements = cur->last - cur->first;

      if(idx < numElements){
        size_t pos = cur->first + idx;
        result = &cur->val[pos];
        found = true;
      }
      else{
        idx = idx - numElements;
        cur = cur->next;
      
    }
    //maybe throw if not found
}
return result;
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
