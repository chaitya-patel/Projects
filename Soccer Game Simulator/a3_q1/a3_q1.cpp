// a3_q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//*****************************************************************************
// Student Name: Chaitya Patel
//  Student Number:  20886642
//
//  SYDE 121 Assignment: 3
//  Filename: a3_q1
//
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
// Due Date: Sunday, November 1, 2020
//**************************************************************

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

/*Testing and Debugging: In order to test and debug the program I ran the program about 10 times, where none of the cases repeated too heavily but still sometimes
within a simulation, one team just had bad luck, or it kept fouling, but other times it was a fair game.
I also walked through the debugger to make sure the flow was accurate and followed the procedure that I implemented and planned. 
Also, I manually counted the number of events and of each type of event for 5 runs of the code so that I had seen one type of each stat be changed at least once.*/

void soccer_game_simulator();
// PURPOSE: to start the soccer game simulator.
//	INPUTS: none
//	OUTPUTS: none

void event_number();
// PURPOSE: to generate a random number between [1,20], inclusive to represent the number of events that will take place in the game.
//	INPUTS: none
//	OUTPUTS: none

void divide_game(int number_of_events);
// PURPOSE: to divide the game/total events into two parts and store those events into vector arrays and start the game, as well as print out half-time and end of game stats.
//	INPUTS: number_of_events - the random number of events generated in event_number()
//	OUTPUTS: none

void number_per_event(vector<int> half_events, char team_a, char team_b, int& points_a, int& points_b, int& foul_a, int& foul_b, int& shots_on_goal, int& shots_off_goal, int& blocked_shots,
	int& penalty_on_goal, int& penalty_off_goal, int& blocked_penalty_shots, int& free_on_goal, int& free_off_goal, int& blocked_free, int& yellow_card_a, int& red_card_a, int& yellow_card_b, int& red_card_b);
// PURPOSE: to generate a random number between [1,6], inclusive for each event and pass it to check_event_number() to initiate the main game events
//	INPUTS: half_events - vector array of the number of events that occur within the current half of the game, so that they can be iterated through
//			variables representing the game stats like goals, shots and cards to pass into the check_event_number() so that stats can be updated
//	OUTPUTS: none

void check_event_number(int event, char team_a, char team_b, int& points_a, int& points_b, int& foul_a, int& foul_b, int& shots_on_goal, int& shots_off_goal, int& blocked_shots,
	int& penalty_on_goal, int& penalty_off_goal, int& blocked_penalty_shots, int& free_on_goal, int& free_off_goal, int& blocked_free, int& yellow_card_a, int& red_card_a, int& yellow_card_b, int& red_card_b);
// PURPOSE: to initiate a main event, that triggers other sub-events such as goals and foul cards
//	INPUTS: variables representing the game stats like goals, shots and cards so that stats can be updated as the game runs
//	OUTPUTS: none

void decide_goal(char team, int& points, int& shots_on, int& shots_off, int& blocked);
// PURPOSE: to trigger an event during normal game play where a shot was on, off or blocked
//	INPUTS: team (the team that is making the shot), points (the points stats of that team/goal made), shots_on (shots that were made on the goal)
//			shots_off (shots that were made off the goal), blocked (shots made on the goal but were blocked)
//	OUTPUTS: none

void decide_free(char team, int& points, int& shots_on, int& shots_off, int& blocked);
// PURPOSE: a free kick event where a shot was on, off or blocked
//	INPUTS: team (the team that is making the shot), points (the points stats of that team/goal made), shots_on (shots that were made on the goal)
//			shots_off (shots that were made off the goal), blocked (shots made on the goal but were blocked)
//	OUTPUTS: none

void decide_penalty(char team, int& points, int& shots_on, int& shots_off, int& blocked);
// PURPOSE:  a penalty kick event where a shot was on, off or blocked
//	INPUTS: team (the team that is making the shot), points (the points stats of that team/goal made), shots_on (shots that were made on the goal)
//			shots_off (shots that were made off the goal), blocked (shots made on the goal but were blocked)
//	OUTPUTS: none

void decide_foul_card(char team, int& yellow_card, int& red_card);
// PURPOSE: to give or not give a yellow or red card that comes with a foul event such as penalty or free kick
//	INPUTS: team (the team that committed the foul), yellow_card, red_card
//	OUTPUTS: none

void point_stats(char team_a, char team_b, int points_a, int point_b);
// PURPOSE: to display the points/score of each team
//	INPUTS: each team and its related points
//	OUTPUTS: none

void shots_stats(int shots_on, int shots_off, int blocked);
// PURPOSE: to display the stats of the types of shots made during normal game play
//	INPUTS: the subevents and their corresponding values that have accumulated
//	OUTPUTS: none

void free_stats(int shots_on, int shots_off, int blocked);
// PURPOSE: to display the stats of the types of shots made during free kick events
//	INPUTS: the subevents and their corresponding values that have accumulated
//	OUTPUTS: none

void penalty_stats(int shots_on, int shots_off, int blocked);
// PURPOSE: to display the stats of the types of shots made during penalty events
//	INPUTS: the subevents and their corresponding values that have accumulated
//	OUTPUTS: none

void foul_stats(char team_a, char team_b, int fouls_a, int fouls_b);
// PURPOSE: to display the stats of the number of fouls each team has committed
//	INPUTS: the team names and their corresponding accumulation of fouls
//	OUTPUTS: none

void card_stats(char team_a, char team_b, int yellow_card_a, int red_card_a, int yellow_card_b, int red_card_b);
// PURPOSE: to display the number of yellow cards and red cards that each team has
//	INPUTS: yellow_card_a and yellow_card_b - number of yellow_cards issued to respective team
//			red_card_a and red_card_b - number of red cards issued to respective team
//	OUTPUTS: none


void soccer_game_simulator() {
	event_number();
}

void event_number() {
	//[SETUP]step0. declare and initialize variables
	int number_of_events; // the random number of main events to occur in the game 
	
	//[PROCESSING]step1. set variables to a random number
	srand((unsigned)time(0));
	number_of_events = rand() % 20 + 1; // setting game events to a number [1,20], inclusive

	//step2. pass events to get game divided into halves
	divide_game(number_of_events);
}

void divide_game(int number_of_events) {
	//[SETUP]step 0. declare and initialize variables
	int events_half_1 = 0;
	char team_a = 'A';
	char team_b = 'B';
	int points_a = 0, points_b = 0;
	int foul_a = 0, foul_b = 0;
	int shots_on_goal = 0, shots_off_goal = 0, blocked_shots = 0;
	int penalty_on_goal = 0, penalty_off_goal = 0, blocked_penalty_shots = 0;
	int free_on_goal = 0, free_off_goal = 0, blocked_free = 0;
	int yellow_card_a = 0, red_card_a = 0, yellow_card_b = 0, red_card_b = 0;

	//[PROCESSING]step1. divide events in half and in case total is odd, split up so one half has an extra event
	if ((number_of_events % 2) == 0) {
		events_half_1 = number_of_events / 2;
	}
	else {
		events_half_1 = number_of_events / 2 + 1;
	}

	//step2. create a vector array out of events for this half
	vector<int> first_half_events; // create vector instance
	for (int event = 1; event <= events_half_1; event++) { 
		first_half_events.push_back(event); // insert event number at the end
	}
	//step3. pass variables to initiate the actual game simulation
	cout << "AND THE GAME BEGINS!" << endl << endl;
	number_per_event(first_half_events, team_a, team_b, points_a, points_b, foul_a, foul_b, shots_on_goal, shots_off_goal, blocked_shots,
		penalty_on_goal, penalty_off_goal, blocked_penalty_shots, free_on_goal, free_off_goal, blocked_free, yellow_card_a, red_card_a, yellow_card_b, red_card_b);
	cout << "AND THE FIRST HALF HAS ENDED..." << endl;

	//[OUTPUT]step4. output half-time game stats through different functions for that collection of stats
	cout << endl << "HALF-TIME STATS:" << endl;
	point_stats(team_a, team_b, points_a, points_b);
	shots_stats(shots_on_goal, shots_off_goal, blocked_shots);
	free_stats(free_on_goal, free_off_goal, blocked_free);
	penalty_stats(penalty_on_goal, penalty_off_goal, blocked_penalty_shots);
	foul_stats(team_a, team_b, foul_a, foul_b);
	card_stats(team_a, team_b, yellow_card_a, red_card_a, yellow_card_b, red_card_b);
	cout << endl;

	//[PROCESSING] step5. repeat creation of array for second half of game
	vector<int> second_half_events; // create vector instance
	for (int event = 1; event <= number_of_events / 2; ++event) {
		second_half_events.push_back(event); // insert at the end
	}

	//step6. pass variables to initiate the game simulation for second half of game
	cout << "THE SECOND HALF HAS STARTED..." << endl << endl;
	number_per_event(second_half_events, team_a, team_b, points_a, points_b, foul_a, foul_b, shots_on_goal, shots_off_goal, blocked_shots,
		penalty_on_goal, penalty_off_goal, blocked_penalty_shots, free_on_goal, free_off_goal, blocked_free, yellow_card_a, red_card_a, yellow_card_b, red_card_b);
	cout << endl << "THE GAME HAS ENDED! GREAT GAME!" << endl;

	//[OUTPUT]step7. output final game stats through different functions for that collection of stats
	cout << endl << "FINAL STATS:" << endl;
	point_stats(team_a, team_b, points_a, points_b);
	shots_stats(shots_on_goal, shots_off_goal, blocked_shots);
	free_stats(free_on_goal, free_off_goal, blocked_free);
	penalty_stats(penalty_on_goal, penalty_off_goal, blocked_penalty_shots);
	foul_stats(team_a, team_b, foul_a, foul_b);
	card_stats(team_a, team_b, yellow_card_a, red_card_a, yellow_card_b, red_card_b);
	cout << endl;
}

void number_per_event(vector<int> half_events, char team_a, char team_b, int& points_a, int& points_b, int& foul_a, int& foul_b, int& shots_on_goal, int& shots_off_goal, int& blocked_shots,
	int& penalty_on_goal, int& penalty_off_goal, int& blocked_penalty_shots, int& free_on_goal, int& free_off_goal, int& blocked_free, int& yellow_card_a, int& red_card_a, int& yellow_card_b, int& red_card_b) {
	//[SETUP]step0. declare and initialize variable
	int event; // event number for the current event in the current half

	//[PROCESSING]step1. iterate through each main event to create another event for each
	for (vector<int>::iterator events = half_events.begin(); events != half_events.end(); ++events) {
		event = rand() % 6 + 1; // assign random number from [1,6], inclusive

		//step2. initiate events for current main event from half-time vector 
		check_event_number(event, team_a, team_b, points_a, points_b, foul_a, foul_b, shots_on_goal, shots_off_goal, blocked_shots,
			penalty_on_goal, penalty_off_goal, blocked_penalty_shots, free_on_goal, free_off_goal, blocked_free, yellow_card_a, red_card_a, yellow_card_b, red_card_b);
	}
}

void check_event_number(int event, char team_a, char team_b, int& points_a, int& points_b, int& foul_a, int& foul_b, int& shots_on_goal, int& shots_off_goal, int& blocked_shots,
	int& penalty_on_goal, int& penalty_off_goal, int& blocked_penalty_shots, int& free_on_goal, int& free_off_goal, int& blocked_free, int& yellow_card_a, int& red_card_a, int& yellow_card_b, int& red_card_b) {

	//[PROCESSING] based on the event number chosen for the current main event, go to that case and play out the scenario
	switch (event) {
	case 1 :
		cout << "Team A has shot at target." << endl;
		decide_goal(team_a, points_a, shots_on_goal, shots_off_goal, blocked_shots);
		cout << endl;
		break;
	case 2:
		cout << "Team B has shot at target." << endl;
		decide_goal(team_b, points_b, shots_on_goal, shots_off_goal, blocked_shots);
		cout << endl;
		break;
	case 3:
		cout << "Team B has committed a foul and Team A was awarded a free kick." << endl;
		foul_b += 1;
		decide_free(team_a, points_a, free_on_goal, free_off_goal, blocked_free);
		decide_foul_card(team_b, yellow_card_b, red_card_b);
		cout << endl;
		break;
	case 4:
		cout << "Team A has committed a foul and Team B was awarded a free kick." << endl;
		foul_a += 1;
		decide_free(team_b, points_b, free_on_goal, free_off_goal, blocked_free);
		decide_foul_card(team_a, yellow_card_a, red_card_a);
		cout << endl;
		break;
	case 5:
		cout << "Team B has committed a foul close to the goal and Team A was awarded a penalty kick." << endl;
		foul_b += 1;
		decide_penalty(team_a, points_a, penalty_on_goal, penalty_off_goal, blocked_penalty_shots);
		decide_foul_card(team_b, yellow_card_b, red_card_b);
		cout << endl;
		break;
	case 6:
		cout << "Team A has committed a foul close to the goal and Team B was awarded a penalty kick." << endl;
		foul_a += 1;
		decide_penalty(team_b, points_b, penalty_on_goal, penalty_off_goal, blocked_penalty_shots);
		decide_foul_card(team_a, yellow_card_a, red_card_a);
		cout << endl;
		break;
	}

}

void decide_goal(char team, int& points, int& shots_on, int& shots_off, int& blocked) {
	//[SETUP]step0. declare and initialize variable
	int goal_event = rand() % 4; // set event to a random subevent between [0,3], inclusive

	//[PROCESSING]step1. based on the subevent number chosen for the current event, go to that case and play out the scenario
	switch (goal_event) {
	case 0 :
		shots_on += 1;
		points += 1;
		cout << "Team " << team << " scored a goal! " << endl;
		break;
	case 1 :
		shots_on += 1;
		blocked += 1;
		cout << "Team " << team << " made a shot on the goal, but was saved by the defense. :( " << endl;
		break;
	case 2 :
		shots_off += 1;
		cout << "Team " << team << " took a shot but it was made off goal. :( " << endl;
		break;
	case 3 :
		blocked += 1;
		cout << "Team " << team << " took a shot but it was blocked by a player other than the defense. :(" << endl;
		break;
	}
}

void decide_free(char team, int& points, int& shots_on, int& shots_off, int& blocked) {
	//[SETUP]step0. declare and initialize variable
	int free_event = rand() % 4; // set event to a random subevent between [0,3], inclusive

	//[PROCESSING]step1. based on the subevent number chosen for the current event, go to that case and play out the scenario
	switch (free_event) {
	case 0:
		shots_on += 1;
		points += 1;
		cout << "Team " << team << " scored a goal! " << endl;
		break;
	case 1:
		shots_on += 1;
		blocked += 1;
		cout << "Team " << team << " made a shot on the goal, but was saved by the defense. :( " << endl;
		break;
	case 2:
		shots_off += 1;
		cout << "Team " << team << " took a shot but it was made off goal. :( " << endl;
		break;
	case 3:
		blocked += 1;
		cout << "Team " << team << " took a shot but it was blocked by a player other than the defense. :(" << endl;
		break;
	}
}

void decide_penalty(char team, int& points, int& shots_on, int& shots_off, int& blocked) {
	//[SETUP]step0. declare and initialize variable
	int penalty_event = rand() % 3; // set event to a random subevent between [0,2], inclusive

	//[PROCESSING]step1. based on the subevent number chosen for the current event, go to that case and play out the scenario
	switch (penalty_event) {
	case 0:
		shots_on += 1;
		points += 1;
		cout << "Team " << team << " scored a goal! " << endl;
		break;
	case 1:
		shots_on += 1;
		blocked += 1;
		cout << "Team " << team << " made a shot on the goal, but was saved by the defense. :( " << endl;
		break;
	case 2:
		shots_off += 1;
		cout << "Team " << team << " took a shot but it was made off goal. :( " << endl;
		break;
	}
}

void decide_foul_card(char team, int& yellow_card, int& red_card) {
	//[SETUP]step0. declare and initialize variable
	int foul_card_event = rand() % 3;  // set event to a random subevent between [0,2], inclusive

	//[PROCESSING]step1. based on the subevent number chosen for the current event, go to that case and play out the scenario
	switch (foul_card_event) {
	case 0:
		cout << "Team " << team << " did not recieve a foul card. " << endl;
		break;
	case 1:
		yellow_card += 1;
		cout << "Team " << team << " was given a yellow card. :( " << endl;
		break;
	case 2:
		red_card += 1;
		cout << "Team " << team << " was given a red card. :( " << endl;
		break;
	}
}

void point_stats(char team_a, char team_b, int points_a, int points_b) {
	//[OUTPUT] print the score stats to the console for each team
	cout << "SCORE:" << endl;
	cout << "Team " << team_a << ": " << points_a << endl;
	cout << "Team " << team_b << ": " << points_b << endl;
}

void shots_stats(int shots_on, int shots_off, int blocked) {
	//[OUTPUT] print the shots stats to the console for each type of shot during normal play
	cout << "SHOTS DURING PLAY:" << endl;
	cout << "Total Shots on Goal: " << shots_on << endl;
	cout << "Total Shots off Goal: " << shots_off << endl;
	cout << "Total Shots Blocked: " << blocked << endl;
}

void free_stats(int shots_on, int shots_off, int blocked) {
	//[OUTPUT] print the free kick stats to the console for each subevent for free kick events
	cout << "FREE KICK STATS:" << endl;
	cout << "Total Free Kicks on Goal: " << shots_on << endl;
	cout << "Total Free Kicks off Goal: " << shots_off << endl;
	cout << "Total Free Kicks Blocked: " << blocked << endl;
}

void penalty_stats(int shots_on, int shots_off, int blocked) {
	//[OUTPUT] print the penalty stats to the console for each subevent for penalty events
	cout << "PENALTY STATS:" << endl;
	cout << "Total Penalty Shots on Goal: " << shots_on << endl;
	cout << "Total Penalty Shots off Goal: " << shots_off << endl;
	cout << "Total Penalty Shots Blocked: " << blocked << endl;
}

void foul_stats(char team_a, char team_b, int fouls_a, int fouls_b) {
	//[OUTPUT] print the foul stats to the console for each team
	cout << "FOUL STATS:" << endl;
	cout << "Team " << team_a << ": " << fouls_a << endl;
	cout << "Team " << team_b << ": " << fouls_b << endl;
}

void card_stats(char team_a, char team_b, int yellow_card_a, int red_card_a, int yellow_card_b, int red_card_b) {
	//[OUTPUT] print the card stats to the console for each team and each card
	cout << "CARD STATS:" << endl;
	cout << "Team " << team_a << ":" << endl;
	cout << "Yellow Cards Given: " << yellow_card_a << endl;
	cout << "Red Cards Given: " << red_card_a << endl;
	cout << "Team " << team_b << ":" << endl;
	cout << "Yellow Cards Given: " << yellow_card_b << endl;
	cout << "Red Cards Given: " << red_card_b << endl;
}

int main()
{
	soccer_game_simulator();
}

