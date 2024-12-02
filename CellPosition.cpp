#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v<UI.ToolBarHeight && v>UI.CommandsBarHeight)
	{
		vCell = v;
		return true;
	}
	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if (h)
	{
		hCell = h;
	}
	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if (vCell != -1 && hCell != -1)
		return true;

	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file

	int CellNum;



	if (cellPosition.VCell() == 0)
	{

		CellNum = 40 + (cellPosition.HCell() + 5);
	}
	else if (cellPosition.VCell() == 1)
	{
		CellNum = 30 + (cellPosition.HCell() + 4);
	}

	else if (cellPosition.VCell() == 2)
	{
		CellNum = 20 + (cellPosition.HCell() + 3);
	}

	else if (cellPosition.VCell() == 3)
	{
		CellNum = 10 + (cellPosition.HCell() + 2);
	}
	else
	{
		CellNum = cellPosition.HCell() + 1;
	}

	return CellNum;

	 // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	if (cellNum >= 45)
	{
		position.SetVCell(0);
		for (int i = 0; i < 11; i++)
		{
			if (i == (cellNum - 45))
			{
				position.SetHCell(i);
			}
		}
	}
	else if (cellNum < 45 && cellNum >= 34)

	{
		position.SetVCell(1);

		for (int i = 0; i < 11; i++)
		{
			if (i == (cellNum - 34))
				position.SetHCell(i);
		}

	}
	else if (cellNum < 34 && cellNum >= 23)
	{
		position.SetVCell(2);

		for (int i = 0; i < 11; i++)
		{
			if (i = (cellNum - 23))

				position.SetHCell(i);
		}
	}
	else if (cellNum < 23 && cellNum >= 12)
	{
		position.SetVCell(3);
		for (int i = 0; i < 11; i++)
		{
			if (i == (cellNum - 12))
			{
				position.SetHCell(i);
			}
		}

	}
	else
	{
		position.SetVCell(4);
		for (int i = 0; i < 11; i++)
		{
			if (i == cellNum - 1)
			{
				position.SetHCell(i);
			}
		}
	}
	/// TODO: Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	
	/// TODO: Implement this function as described in the .h file


	

	// Note: this function updates the data members (vCell and hCell) of the calling object

}