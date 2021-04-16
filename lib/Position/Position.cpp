#include <Position.h>

  Position :: Position(int newRow, int newColumn) :row(newRow), column(newColumn){};

  Position :: Position(Position & copy)
  {
    row = copy.getRow();
    column = copy.getColumn();
  }

  Position ::~ Position(){};

  int Position ::getRow(){return row;}

  int Position ::getColumn(){return column;}

  void Position::operator = (Position pos){
    row = pos.getRow();
    column = pos.getColumn();
  }
 
  bool Position::operator == (Position pos){
    if(row==pos.getRow() && column==pos.getColumn()){
      return true;
    }
    else return false;
  }

  void Position::operator+=(const Position& pos){
    row +=pos.row;
    column +=pos.column;
  }

  bool Position::inMatrix(const int matrixLength){
    return (row<=matrixLength && row>=1 && column<=matrixLength && column>=1);
  }


  void Position::update(int newRow, int newColumn){
    row = newRow;
    column = newColumn;
  }