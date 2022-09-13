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

void ULListStr::push_back(const std::string& val)
{
  if(tail_ == NULL)
  {
    tail_ = new Item(); 
    tail_->first = 0;
    tail_->last = 0;
    tail_->val[tail_->first] = val; 
    tail_->last++; 
    ++size_; 
    head_ = tail_; 
  }
  else if (tail_->last < 9)
  {
    tail_->val[tail_->last] = val; 
    tail_->last++; 
    ++size_; 
  }
  else
  {
    Item* boof = new Item(); 
    boof->val[boof->last] = val; 
    boof->last++; 
    ++size_; 
    boof->prev = tail_;
    tail_->next = boof;  
    tail_ = boof;
    boof->next = NULL; 
  }
}


void ULListStr::push_front(const std::string& val)
{
  if (head_ == NULL) 
  {
    head_ = new Item();
    head_->first = 9; 
    head_->last = 10; 
    head_->val[head_->first] = val; 
    ++size_;
    tail_ = head_;   
  }
  else if (head_->first > 0)
  {
    head_->val[head_->first - 1] = val; 
    head_->first--; 
    ++size_;  
  }
  else
  {
    Item* boof = new Item(); 
    boof->first = 9; 
    boof->last = 10; 
    boof->val[boof->first] = val; 
    ++size_; 
    boof->next = head_;
    head_->prev = boof;
    head_ = boof;
    boof->prev = NULL; 
  }
}

void ULListStr::pop_back() 
{
  if (tail_ == NULL)
  {
    throw std::invalid_argument("Tried to pop back on an empty list!"); 
  }
  else if (tail_)
  {
    tail_->last--; 
    size_--; 
  }
  if (tail_->first == tail_->last) 
  {
    if (head_ == tail_)
    {
      tail_ = NULL; 
      delete head_; 
      head_ = NULL; 
    }
    else
    {
      Item* temp = tail_; 
      tail_ = tail_->prev; 
      delete temp;
      tail_->next = NULL; 
    } 
  }
}

void ULListStr::pop_front()  
{
  if (head_ == NULL)
  {
    throw std::invalid_argument("Tried to pop front on an empty list!"); 
  }
  else if(head_)
  {
    head_->first++; 
    size_--; 
  }
  if (head_->first == head_->last)
  {
    if (head_ == tail_)
    {
      tail_ = NULL; 
      delete head_;
      head_ = NULL;
    }
    else 
    {
      Item* temp = head_; 
      head_ = head_->next; 
      delete temp; 
      head_->prev = NULL; 
    }
  }
}

std::string const & ULListStr::back() const 
{
  if (tail_ == NULL)
  {
    throw std::invalid_argument("Tried to return back on an empty list!"); 
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const   
{
  if (head_ == NULL)
  {
    throw std::invalid_argument("Tried to return front on an empty list!"); 
  }
  return head_->val[head_->first]; 
}

std::string* ULListStr::getValAtLoc(size_t loc) const  
{
  if (loc > size_) return NULL; 
  Item* tracker = head_;
  while ((tracker->last - tracker->first) <= loc)
  {
    loc -= (tracker->last - tracker->first); 
    tracker = tracker->next; 
  }
  return &tracker->val[tracker->first+loc]; 
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
