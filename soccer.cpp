//Soccer Game Simulator
//Last_Edited_Date:11/3/2022

#include <iostream>
//Declaring functions
int random1();
int random2();
int random3();
void event(int);
void penaltyNumber(int, int&, int&, int);
void winner(int, int);

int main(){
    using namespace std;

    //using seed function with current time
    srand(time(NULL));
    //random numbers for the number of events
    int rounds = random1();

    cout << "There would be " << rounds << " events for this game." << endl;
    cout << endl;
    event(rounds);
    return 0;
}
/**
 * @brief Return random numbers for the number of events
 * 
 * @return int 
 */
int random1(){
    int random1 = (rand() % 14) + 1;
    return random1;
}
/**
 * @brief Return random number for what happen in each event
 * 
 * @return int 
 */
int random2(){
    int random2 = (rand() % 6) + 1;
    return random2;
}
/**
 * @brief Return random numbers for penalties
 * 
 * @return int 
 */
int random3(){
    int random3 = (rand() % 4) + 1;
    return random3;
}
/**
 * @brief Calculate the total number of team 1 and team 2 goals 
 * 
 * @param r - random number for the number of events
 */
void event(int r){
    using namespace std;

    int goalsOfTeam1 = 0; 
    int goalsOfTeam2 = 0;
    //using loop for each event
    for(int i = 1; i <= r; i++){
        //function call for the random number that gives what happen in each event
        int decision = random2();
        //function call for the random number for penalty choices
        int penalty = random3();
        cout << "In Event " << i << endl;
        switch(decision){
            case 1:
                cout << "Team 1 has scored a goal! " << endl;
                goalsOfTeam1 += 1;
                break;
            case 2:
                cout << "Team 2 has scored a goal! " << endl;
                goalsOfTeam2 += 1;
                break;
            case 3:
                cout << "Team 1 has committed an offside." << endl;
                break;
            case 4:
                cout << "Team 2 has committed an offside." << endl;
                break;
            case 5:
                cout << "Team 1 gets a penalty." << endl;
                penaltyNumber(decision, goalsOfTeam1, goalsOfTeam2, penalty);
                break;
            case 6:
                cout << "Team 2 gets a penalty. " << endl;
                penaltyNumber(decision, goalsOfTeam1, goalsOfTeam2, penalty);
                break;
        }
        cout << endl;
    }
    cout << "Total Goals of Team 1: " << goalsOfTeam1 << endl;
    cout << "Total Goals of Team 2: " << goalsOfTeam2 << endl;
    winner(goalsOfTeam1, goalsOfTeam2);
}
/**
 * @brief Penalty choices and calculate the total goals from penalties
 * 
 * @param option - random number for what happen in each event
 * @param goals1 - total number of goals for Team 1
 * @param goals2 - total number of goals for Team 2
 * @param penaltyNum - random number for penalty choices
 */
void penaltyNumber(int option, int& goals1, int& goals2, int penaltyNum){
    using namespace std;

    switch(option){
        case 5:
                if(penaltyNum == 1){
                    cout << "Team 1 scores from the penalty." << endl;
                    goals1 += 1;
                }
                else if(penaltyNum == 2){
                    cout << "Team 1 misses from the penalty." << endl;
                }
                else if(penaltyNum == 3){
                    cout << "Team 1 gets a yellow card." << endl;
                }
                else{
                    cout << "Team 1 gets a red card." << endl;
                }
            break;
        case 6:
            if(penaltyNum == 1){
                cout << "Team 2 scores from the penalty." << endl;
                goals2 += 1;
            }
            else if(penaltyNum == 2){
                cout << "Team 2 misses from the penalty." << endl;
            }
            else if(penaltyNum == 3){
                cout << "Team 2 gets a yellow card." << endl;
            }
            else{
                cout << "Team 2 gets a red card." << endl;
            }
            break;
        
    }
}
/**
 * @brief Determine which team is a winner
 * 
 * @param goals1 - Total number of Team 1 goals
 * @param goals2 - Total number of Team 2 goals
 */
void winner(int goals1, int goals2){
    using namespace std;
    if(goals1 > goals2){
        cout << "Team 1 is a winner! " << endl;
    }
    else if(goals1 < goals2){
        cout << "Team 2 is a winner! " << endl;
    }
    else{
        cout << "A tie! " << endl;
    }
}
