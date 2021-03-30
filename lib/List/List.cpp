#include <List.h>


 List::List() {
    length = 0;
    head = nullptr;
    tail = nullptr;
    curr = nullptr;
}

 
 List::List(const  List & list) {
    length = 0;
    head = nullptr;
    tail = nullptr;
    curr = nullptr;

     ListNode * temp = list.head;

    while(temp != nullptr)
    {
        Append(temp->element);
        temp = temp->next;
    }
}

 
 List &  List::operator=(const  List & list)
{
    Clear();

     ListNode * temp = list.head;

    while(temp != nullptr)
    {
        Append(temp->element);
        temp = temp->next;
    }

    return *this;
}

 
 List::~ List() {
    Clear();
}

 
Position&  List::getCurrent()
{
  return curr->element;
}

 
Position&  List::First() const
{
  return head->element;
}

 
Position&  List::Last() const
{
  return tail->element;
}

 
int  List::getLength()
{
  return length;
}

 
void  List::Append( Position element)
{
     ListNode * node = new  ListNode(element, tail, nullptr);

    if(length == 0)
        curr = tail = head = node;
    else {
        tail->next = node;
        tail = node;
    }

    length++;

}

 
void  List::DeleteLast()
{
    if(length == 0)
      return;
    curr = tail;
    DeleteCurrent();
}

 
void  List::DeleteFirst()
{
    if(length == 0)
      return;
    curr = head;
    DeleteCurrent();
}

 
bool  List::next()
{
    if(length == 0)
        return false;

    if(curr->next == nullptr)
        return false;

    curr = curr->next;
    return true;
}

 
bool  List::moveToStart()
{
    curr = head;
    return length != 0;
}

 
bool  List::prev()
{
    if(length == 0)
        return false;

    if(curr->prev != nullptr)
        return false;

    curr = curr->prev;
    return true;
}

 
void  List::Delete(Position & elem)
{
    if(Search(elem))
        DeleteCurrent();
}

 
void  List::DeleteCurrent()
{
    if(length == 0)
        return;
    length--;
     ListNode * temp = curr;

    if(temp->prev != nullptr)
        temp->prev->next = temp->next;
    if(temp->next != nullptr)
        temp->next->prev = temp->prev;

    if(length == 0)
        head = curr = tail = nullptr;
    else if(curr == head)
        curr = head = head->next; 
    else if(curr == tail)
        curr = tail = tail->prev;
    else
        curr = curr->prev;

     delete temp;
}

 
bool  List::Search(Position elem)
{
    if(length == 0)
        return false;
    if(moveToStart())
        do {
            if(curr->element == elem)
                return true;
        } while (next());
    return false;
}

 
void  List::PutFirstToLast()
{
  if(length < 2)
    return;
   ListNode* temp = head->next;
  head->next->prev = nullptr;
  head->next = nullptr;
  head->prev = tail;
  tail->next = head;
  tail = head;
  head = temp;
}

 
void  List::Update(Position elem)
{
    if(Search(elem))
        curr->element = elem;
}

 
void  List::Clear()
{
    if(length == 0)
        return;
    ListNode * temp = head;

    while(temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    head = curr = tail = nullptr;

    length = 0;

}
