#ifndef List_hpp
#define List_hpp

#include <Position.h>

class ListNode { 
  private:
    Position element;
    ListNode* next;
    ListNode* prev;
  public:
    ListNode(Position element, ListNode* prev, ListNode* next) : element(element)
    {
      this->next = next;
      this->prev = prev;
    };
  friend class List; 

};

class List  {
  private:
    int length;
    ListNode* head;
    ListNode* tail;
    ListNode* curr;
  public:
    List();
    List(const List&);
    ~List();
    Position& getCurrent();
    Position& First() const;
    Position& Last() const;
    int getLength();
    void Append(Position);
    void DeleteLast();
    void DeleteFirst();
    void DeleteCurrent();
    bool next();
    bool moveToStart();
    bool prev();
    void Delete(Position&);
    bool Search(Position);
    bool SearchColumn(int column);
    List SearchSameColumn(int column);
    void Clear();
    void PutFirstToLast();
    void Update(Position elem);
    List& operator = (const List&);
    void operator += (Position);
    void move(Position, int maxPosition);
};

// S'assurer que les positions sont toutes différentes les unes des autres 

#endif