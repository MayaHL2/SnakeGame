#ifndef List_hpp
#define List_hpp


class ListNode {
  public:
    int element;
    ListNode* next;
    ListNode* prev;

    ListNode(int element, ListNode* prev, ListNode* next) : element(element)
    {
      this->next = next;
      this->prev = prev;
    };
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
    int& getCurrent();
    int& First() const;
    int& Last() const;
    int getLength();
    void Append(int);
    void DeleteLast();
    void DeleteFirst();
    void DeleteCurrent();
    bool next();
    bool moveToStart();
    bool prev();
    void Delete(int&);
    bool Search(int);
    void Clear();
    void PutFirstToLast();
    void Update(int elem);
    List& operator = (const List&);
};


#endif