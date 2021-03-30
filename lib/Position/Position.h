#ifndef Position_hpp
#define Position_hpp

class Position
{
private:
  int row; 
  int column;
public:
  Position(int newRow, int newColumn);
  Position(Position & copy);
  ~Position();
  Position operator = ( Position);
  bool operator == (Position);
  int getRow();
  int getColumn();
};



#endif