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
  if(empty()){
    //Creates a new array for the new val
    head_ = tail_ = new Item;
    //Adds it to the center of the array 
    tail_->first = 0;
    //updates the last indicator to +1 of first
    tail_->last = 1;
    //Adds value to the newly created array
    tail_->val[tail_->first] = val;
  }else if(tail_->last == 10){  //If the current array is full
    //Creates a new array to store the new value
    Item* new_array = new Item;
    //Initalizes the new list.
    new_array->prev = tail_;
    //Links new array to list.
    tail_->next = new_array;
    //Updates the tail of the linked list.
    tail_=new_array;
    //Adds new val into linked list (into new array)
    tail_->val[tail_->first]=val;
    //Updates 'last' index
    (tail_->last)++;
  }else{ //Current array is not empty and has sufficent space
    //Adds the value to the array 
    tail_->val[tail_->last] = val;
    //Updates the last index indicator 
    (tail_->last)++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if(empty()){
    //Creates a new array for the new val
    head_ = tail_ = new Item;
    //Adds it to the center of the array 
    head_->first = 0;
    //updates the last indicator to +1 of first
    head_->last = 1;
    //Adds value to the newly created array
    head_->val[head_->first] = val;
    //Updates size of the array. 
  }else if(head_->first == 0){  //If the current array is full
    //Creates a new array to store the new value
    Item* new_array = new Item;
    //Initalizes the new list.
    new_array->next = head_;
    //Links new array to list.
    head_->prev = new_array;
    //Updates the tail of the linked list.
    head_=new_array;
    //Adds new val into linked list (into new array)
    head_->val[9]=val;
    //Updates the index indicators for the given array 
    head_->last = 10;
    head_->first = 9;
  }else{ //Current array is not empty and has sufficent space
    //Adds the new value to the front.
    head_->val[(head_->first)-1] = val;
    //Decreases the index of the first value in array.
    (head_->first)--;
  }
  size_++;
}

void ULListStr::pop_back(){
  if(empty()){
    //No data to erase (Terminate)
    return;
  }else{
    //Just ignores the last number in the array (essentially erasing it)
    (tail_->last)--;
    if(tail_->first == tail_->last){ //Checks for empty Item
      if(tail_ == head_){ //If there is only one Item in the linked list.
        //Delete the Item and are left with an empty link list.
        delete tail_;
        tail_ = head_ = NULL;
      }else{
        //Saves new tail.
        Item* new_tail = tail_->prev;
        //Disconnects the Item from the Link List
        new_tail->next = NULL;
        //Delets the empty Item.
        delete tail_;
        //Updates the new tail
        tail_ = new_tail;
      }
    }
  }
  size_--;
}

void ULListStr::pop_front(){
  if(empty()){
    //Nothing to erase Terminate process.
    return;
  }else{
    //Moves Item's 'first' index up one to essentiall erase first val.
    (head_->first)++;
    if(head_->first == head_->last){ //Checks if the Item is empty
      if(head_ == tail_){ //if only one item in linked list
        //delete only Item and left with empty linked list
        delete head_;
        head_=tail_=NULL;
      }else{
        //Saves new head.
        Item* new_head = head_->next;
        //Updates its previous to avoid seg fault
        new_head->prev = NULL;
        //Deletes the empty head Item
        delete head_;
        head_ = new_head;
        
      }
    }
  }
  size_--;
}

std::string const& ULListStr::back()const{
  if(empty()){
    return NULL;
  }else{
    return (tail_->val[(tail_->last)-1]);
  }
}

std::string const& ULListStr::front()const{
  if(empty()){
    return NULL;
  }else{
    return (head_->val[head_->first]);
  }
}

std::string* ULListStr::getValAtLoc(size_t loc)const{
  //Pointer to the first val and last value in the list 
  if(loc > size_){
    return NULL;
  }

  Item* curr_Item = tail_;
  int items_Away = size_-loc;

  if(head_ == tail_){
    return &(curr_Item->val[curr_Item->first+loc]);
  }else{
    while(items_Away != 0){
      int places = (curr_Item->last-curr_Item->first);
      if(items_Away-places > 0){
        items_Away -= places;
        curr_Item = curr_Item->prev;
      }else{
        return &(curr_Item->val[(curr_Item->last)-items_Away]);
      }
    }
  }
  return NULL;

}











/***************GIVEN FUNCTIONS***************/
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
