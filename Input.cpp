#include "Input.h"

#include "Output.h"

#include <string>
//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW) 
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if(Key == 13 )	// ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

int Input::GetInteger(Output *pO) const 
{

	///TODO: implement the GetInteger function as described in Input.h file 
	//       using function GetString() defined above and function stoi()

	string s = Input::GetSrting(pO);
	return stoi(s);

	



	// Note: stoi(s) converts string s into its equivalent integer (for example, "55" is converted to 55)

	return 0; // this line should be changed with your implementation
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{	
	int x = -1, y = -1;
	GetPointClicked(x, y); 

	//  ============ GUI in the Design mode ============
	if ( UI.InterfaceMode == MODE_DESIGN )	
	{
		// [1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int clickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (clickedItemOrder)
			{
			case ITM_SET_FLAG_CELL: return SET_FLAG_CELL;
			case ITM_ADD_ANTENNA:   return SET_ANTENNA;
			case ITM_ADD_BELT:       return ADD_BELT;
			case ITM_ADD_WATER_PIT:  return ADD_WATER_PIT;
			case ITM_ADD_DANGER_ZONE: return ADD_DANGER_ZONE;
			case ITM_ADD_WORKSHOP:    return ADD_WORKSHOP;
			case ITM_ROTATING_GEAR: return ADD_ROTATING_GEAR;
			case ITM_COPY_GAME_OBJECT: return COPY_GAME_OBJECT;
			case ITM_CUT_GAME_OBJECT:  return CUT_GAME_OBJECT;
			case ITM_PASTE_GAME_OBJECT: return PASTE_GAME_OBJECT;
			case ITM_SAVE_GRID:        return SAVE;
			case ITM_LOAD_GRID:          return LOAD;

			case ITM_EXIT: return EXIT;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY_MODE;			

				///TODO: Add cases for the other items of Design Mode




			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ( (y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;	
		}

		// [3] User clicks on the status bar
		return STATUS;
	}

	// ============ GUI in the Play mode ============
	else	
	{
		///TODO:
		
		int clickeditemorder = x / UI.MenuItemWidth;

		switch (clickeditemorder)
		{

		case ITM_EXECUTE_COMMANDS:  return EXECUTE_COMMANDS;
		case ITM_SELECT_COMMAND:    return SELECT_COMMAND;
		case ITM_REBOOT_AND_REPAIR: return REBOOT_AND_REPAIR;
		case ITM_USE_CONSUMABLE:   return USE_CONSUMABLE;
		case ITM_NEW_GAME:         return NEW_GAME;
		}


		// perform checks similar to Design mode checks above for the Play Mode
		// and return the corresponding ActionType

		return TO_DESIGN_MODE;	// just for now ==> This should be updated




	}	

}

////////////////////////////////////////////////////////////////////////////////////////// 

CellPosition Input::GetCellClicked() const
{
	int x,y;
	pWind->WaitMouseClick(x, y);	// Get the coordinates of the user click

	CellPosition cellPos;

	if ( UI.InterfaceMode == MODE_DESIGN )	
	{
		if ( y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{
			///TODO: SetHCell and SetVCell of the object cellPost appropriately
			//       using the coordinates x, y and the appropriate variables of the UI_Info Object (UI)
			
			

		}
	}

	return cellPos;
}

//////////////////////////////////////////////////////////////////////////////////////////

int Input::GetSelectedCommandIndex() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	if ((y >= UI.height - UI.StatusBarHeight - UI.CommandsBarHeight - UI.AvailableCommandsYOffset) && (y < UI.height - UI.StatusBarHeight))
	{
		if (x < UI.AvailableCommandsXOffset || x > UI.AvailableCommandsXOffset + (UI.CommandItemWidth / 2) * MaxAvailableCommands)
			return -1;

		return (x - UI.AvailableCommandsXOffset) / (UI.CommandItemWidth / 2);;
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////////////////// 