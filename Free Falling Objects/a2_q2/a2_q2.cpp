// a2_q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//*****************************************************************************
// Student Name: Chaitya Patel
//  Student Number:  20886642
//
//  SYDE 121 Assignment: 2
//  Filename: a2_q2
//
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
// Due Date: Sunday, October 11, 2020
//**************************************************************
// distance = 0.5gt^2 where g is the gravitational constant and t is the time in seconds of the ball in the air. g = 9.80665m/s^2
// step1. Output the distance the ball has fallen in each 1-second interval for the first 30 seconds AND the total distance travelled at the end of each interval
// note. precision is to 3 decimal points (used fixed and precision)
// ASSUME: drone is flying at 15,000 meters
// step2. calculate how long it will it take for the ball to reach the ground
// step3. as the ball is reaching the ground, increase the resolution to 0.1s (i.e decrease the time interval length to 0.1s when close to the ground)

/* - The first 3 intervals and their values were tested by manually calculating the outputs for the time, distance per interval and total distance
	- The values for smaller intervals were also manually calculated
	- the first part of the program will only run for a 30 sec interval and the second part of program will only show to a precision of 0.001
	because I chose to implement that further than 0.01s
	- the range of values valid will be the range of a double since that is the data type used throughout the program
	- TIME FOR THE BALL TO REACH THE GROUND: between 55.309 and 55.310s as per "table" when I uncomment the outputs for the second part.
	- OUTPUT for PART 2: 55.310s */

#include <iostream>
#include <math.h>	// include to enable use of power function
using namespace std;

void p1time_tracking();
// PURPOSE: compute the distance travelled by a free falling object within the first 30s of a fall and keep track of the incrementing interval

void p1distance_per_interval(double time);
// PURPOSE: to track the distance that a object has fallen during a given time interval
//		INPUTS: time - the time for which the distance per interval is being calculated
//		OUTPUTS: distance - the distance that the ball has fallen during this interval

void p1total_distance(double& current_interval);
// PURPOSE: to compute the total distance that an object has fallen thus far (up till that interval of time)
//		INPUTS: current_interval - the distance the object has fallen during the interval at hand
//		OUTPUTS: total_distance - the total distance that the object has fallen thus far

void time_to_ground();
// PURPOSE: to compute the time that it will take for the ball to reach the ground from the drone by interval until the ground is reached

void time_tracking(double& ball_travelled, int close_to_ground, int drone_height, int more_closer);
// PURPOSE: to track the time intervals that the ball has fallen and 
//			the resolution of that interval time that should be passed to calculate distance per interval
//      INPUTS: ball_travelled - the distance that the ball has fallen
//				close_to_ground - the value where there is an interval resolution change due to the ball being close to the ground
//				drone_height - the height of the drone where the ball is dropped from 
//				more_closer - the value where there is another interval resolution change due to the ball being even more closer to the ground
//      OUTPUTS: time - the total time that has passed where the distance per interval and total distance was calculated

void distance_per_interval(double time, double& ball_travelled);
// PURPOSE: to calculate the distance that the ball has fallen within the specified time interval
//      INPUTS: time - the total time that has passed up to this interval
//				ball_travelled - the total distance that the ball has travelled so far
//      OUTPUTS: distance - the distance travelled within that specific interval

void total_distance(double& current_interval, double& ball_travelled);
// PURPOSE: to calculate the total distance that the ball has fallen thus far
//      INPUTS: current_interval - the distance travelled by the ball in the interval at hand
//				ball_travelled - the total distance that has been travelled up until the previous interval
//      OUTPUTS: ball_travlled - the updated total distance that the ball has travelled thus far


void p1time_tracking() {
	
	cout << "THE DISTANCE FALLEN OVER A 30-SEC DURATION:" << endl;
	
	// [PROCESSING] step1. increment the time by a 1s for which the distance has to be calculated
	for (double time = 0; time <= 30; ++time) {
		
		// [OUTPUT] prepare the output format
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);
		
		// output the time passed
		cout << "Time (in sec): " << time;
		p1distance_per_interval(time); // FUNCTION: to track the distance that a object has fallen during a given time interval
	}
	cout << endl;
}

void p1distance_per_interval(double time) {
	// [SETUP] declare and initialize constant
	const double GRAVITY = 9.80665; // the gravity constant in the metric system of units (m/s^2)

	// [PROCESSING] step1. calculate the distance travelled during this interval
	double distance = 0.5 * GRAVITY * pow(time, 2); // mathematical formula to calculate distance travelled based on the time passed

	// [OUTPUT] prepare the output format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	// output the time passed
	cout << " Distance during interval (in m): " << distance;
	p1total_distance(distance); // FUNCTION: to compute the total distance that an object has fallen thus far (up till that interval of time)
}

void p1total_distance(double& current_interval) {
	// [SETUP] declare and initialize variable
	double total_distance = 0; // total distance that the object has fallen

	// [PROCESSING] step1. add the distance travelled in the interval to the total distance travelled up to the previous interval
	total_distance += current_interval;
	
	// [OUTPUT] prepare the output format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	
	// output the time passed
	cout << " Total Distance (in m): " << total_distance << endl;
}

void time_to_ground() {
	// [SETUP] declare and initialize variables
	double ball_travelled = 0; // distance the ball has travelled
	int close_to_ground = 14500; // when the ball is considered too close to the ground for a certain interval resolution
	int more_closer = 14950; // when the ball is considered too close to the ground for a certain interval resolution
	int drone_height = 15000; // the height the ball is dropped from (the height of the drone)

	cout << "IF A BALL IS RELEASED FROM A DRONE AT 15,000m: " << endl;

	// [PROCESSING] step1. check if the ball has completed the trip to the ground and compute the distance over time until it has
	while (ball_travelled < drone_height) {
		time_tracking(ball_travelled, close_to_ground, drone_height, more_closer); // FUNCTION: to track the time intervals that the ball has fallen
	}

	cout << endl;
}

void time_tracking(double& ball_travelled, int close_to_ground, int drone_height, int more_closer) {
	// [SETUP] declare and initialize variables
	double resolution = 0.1; // time interval resolution
	double smaller_resolution = 0.001; // smaller time interval resolution
	double time = -1; // count of time passed (set to -1 since incrementation will cause the calculations from 0)

	// [PROCESSING] step1. compute distance while the distance can be accumulated using largest interval resolution and keep track of time passed
	while (ball_travelled < close_to_ground) {
		time++; // increment the time by 1s interval

		// [OUTPUT] prepare the output format
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);

		// output the time passed up to this interval
		cout << "Time (in sec): " << time;
		distance_per_interval(time, ball_travelled);
	}
	// step2. compute distance when the distance needs to be accumulated using a smaller interval resolution and continue keeping track of time
	while (close_to_ground <= ball_travelled && ball_travelled <= more_closer) {
		time += resolution; // increment the time by a smaller interval resolution

		// [OUTPUT] prepare the output format
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);

		// output the time passed up to this interval
		cout << "Time (in sec): " << time;
		distance_per_interval(time, ball_travelled); // FUNCTION: to calculate the distance that the ball has fallen within the specified time interval
	}
	// step3. compute distance when the distance needs to be accumulated using a smaller interval resolution and continue keeping track of time
	while (more_closer <= ball_travelled && ball_travelled <= drone_height) {
		time += smaller_resolution; // increment the time by an even smaller interval resolution

		// [OUTPUT] prepare the output format
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);

		// output the time passed up to this interval
		cout << "Time (in sec): " << time;
		distance_per_interval(time, ball_travelled);
	}
	// [OUTPUT] prepare the output format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	
	// output the total time it will take for the ball to reach the ground
	cout << "The ball will have reached the ground at approximately " << time << " seconds.";
}

void distance_per_interval(double time, double& ball_travelled) {
	// [SETUP] declare and initialize constant
	const double GRAVITY = 9.80665; // the gravity constant in the metric system of units (m/s^2)

	// [PROCESSING] step1. calculate the distance travelled during this interval
	double distance = 0.5 * GRAVITY * pow(time, 2); // mathematical formula to calculate distance travelled based on the time passed
	distance -= ball_travelled; // find the difference between the total up to the last interval and this interval

	// [OUTPUT] prepare the output format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	// output the distance travelled during this interval
	cout << " Distance during interval (in m): " << distance;
	total_distance(distance, ball_travelled); // FUNCTION: to calculate the total distance that the ball has fallen thus far
}

void total_distance(double& current_interval, double& ball_travelled) {
	// [PROCESSING]	step1. add the ditance travelled in this interval back to the distance travelled up to the previous interval
	ball_travelled += current_interval;

	// [OUTPUT] prepare the output format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	// output the total distance travelled thus far
	cout << " Total Distance (in m): " << ball_travelled << endl;
}

int main() {
	p1time_tracking(); // FUNCTION: compute the distance travelled by a free falling object within the first 30s of a fall and keep track of the incrementing interval
	time_to_ground(); // FUNCTION: to compute the time that it will take for the ball to reach the ground from the drone by interval until the ground is reached
}


