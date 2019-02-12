#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;

int i=0, j=0, check=0, spaces, iterations;

main ()
{
    cout << "How many iterations would you like to run the simulation for?" << endl;
    cin >> iterations;
    
    cout << "How many spaces would you like the hoppers to try to fill?" << endl;
    cin >> spaces;
    
    int *hopper = new (nothrow) int[spaces];
    
    if (hopper!=NULL)
    {
        srand(time(NULL));
        for(i=0; i<spaces; i++){
            hopper[i]=0;
        }
        while (j<iterations)    //specifying how many iterations we want to run the simulation for
        {
            for(i=0; i<spaces; i++){
                cout.width(3) ;
                cout << hopper[i] ;                 //printing the hoppers
            }
            hopper[spaces]=1;   // don't know why but if this isn't here after an iteration the final hopper can go from 1 to 0 at least once.
            for (i=0; i<spaces; i++)
            {
                hopper[0]=1;    //first space for the hoppers is always occupied.
                if (hopper[i]==1 && hopper[i+1]==0){ //if there is a hopper in a space and the next space is empty
                    if(rand()%1000 > 500){
                            hopper[i]=0;            //and the pseudo-random number is greater than 500
                            hopper[i+1]=1;          //the hopper will move forward by one space
                            i++;                    //we i++ to prevent a hopper making more than 1 move per iteration.
                        }
                        else{
                            hopper[i]=1;            //if the random number is less than 500 nothing happens. The hopper stays where it is.
                            }
                }
            }
            for(i=0; i<spaces; i++){
                if (hopper[i]==1){
                    check = check+1;          //count how many spaces are filled
                }
            }
            Sleep(250);
            system("CLS");          //clear screen
            cout << endl;
            j++ ;               // add iteration count
            if (check == spaces){break;}
            else{check=0;}             // if all spaces are full program loop ends
        }
        for(i=0; i<spaces; i++){
                cout.width(3) ;
                cout << hopper[i] ;                 //printing the hoppers
        }
        if(check==spaces){
        cout<< endl << "The simulation finished running and it took " << j << " iterations to fill all spaces.";
        }
        else{cout << endl << "The program timed out. " << j <<" iterations were run and the hoppers did not fill all available spaces.";}
    }else{cout << "Not enough memory to run simulation with that many spaces";}
    delete hopper;
    hopper = NULL;
}
