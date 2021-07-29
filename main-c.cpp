#include <iostream>
#include <string>
#include "func.h"

using namespace std;

int main()
{
    CORRIDOR corridor;
    // get number of players from the user
    int number_of_players;
    cout << "Enter number of players : " << endl;
    cin >> number_of_players;
    cout << endl;

    // set the board
    if (number_of_players == 2)
    {
        corridor.board[0]   = "  a  ";
        corridor.board[10]  = "  B  ";
    }
    else if (number_of_players == 3)
    {
        corridor.board[0]   = "  A  ";
        corridor.board[10]  = "  B  ";
        corridor.board[120] = "  C  ";
    }
    else if (number_of_players == 4)
    {
        corridor.board[0]   = "  A  ";
        corridor.board[10]  = "  B  ";
        corridor.board[120] = "  C  ";
        corridor.board[110] = "  D  ";
    }

    // print the board
    corridor.print_board();

    // this loop continues till the game ends.
    while (corridor.board[60] == "     ")
    {
        // ask if a user wants to put walls or move
        cout << "press (W) to put walls or (M) to move on." << endl;
        char choice;
        cin >> choice;
        // if a player wants to move:
        if(choice == 'M')
	    {
            // get start and destionation position from the user
            int start,destination;
            cin >> start >> destination;
            // check if the destination is valid or not
            if(corridor.valid_place(start,destination))
            {
                cout<<endl;
                // swapping
                string tmp=corridor.board[start];
                corridor.board[start]=corridor.board[destination];
                corridor.board[destination]=tmp;
                system("cls");
                corridor.print_board();

            } // end if
            else
            {
                cout<<"invalid move !!"<<endl;
            }
    	} // end if

        // if a player wants to put walls:
        if (choice == 'W')
        {
            int fist_wall, second_wall;
            cin >> fist_wall >> second_wall;
            // check if the blockes are empty to block 
            if (corridor.valid_wall(fist_wall, second_wall))
            {
                corridor.board[fist_wall] = corridor.board[second_wall] = "~~~~~";
                system("cls");
                corridor.print_board();
            } // end if
            else
            {
                cout << "invalid place to put walls !!" << endl;
            }
        } // end if
    } // end loop
    
    // the winner
    if (corridor.board[60] != "     ")
    {
        cout << corridor.board[60].substr(2, 1) << " won the game!" << endl;
    }
} // end main