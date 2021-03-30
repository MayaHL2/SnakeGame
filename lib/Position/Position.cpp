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

  Position Position::operator = (Position pos){
    return pos;
  }

  bool Position::operator == (Position pos){
    if(row==pos.getRow() && column==pos.getColumn()){
      return true;
    }
    else return false;
  }