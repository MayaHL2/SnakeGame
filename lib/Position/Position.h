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
  void operator = (Position);
  bool operator == (Position);
  void operator +=(const Position& );
  int getRow();
  int getColumn();
  bool inMatrix(const int matrixLength);
  void update(int, int);
friend class List; 
};

// faire en sorte que les positins ne dépasse pas la longueur de la matrice LED
// Afficher la position sous forme de (row,column)


#endif