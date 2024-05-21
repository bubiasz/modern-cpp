//
//  test_userliterals.cpp
//  lab11
//
//  Created by Jakub Matysek on 19/05/2024.
//

#include "../userliterals.cpp"
#include <iostream>

/**
    Computes velocity in meters per seconds.
    @param distance  distance in meters
    @param time      time in seconds
    @return velocity in meters per seconds.
*/
double computeVelocity(double distance, double time){
    return distance / time;
}

int main(){
    std::cout << computeVelocity(100_m, 5_s) << std::endl;     //20
    std::cout << computeVelocity(360_km, 2.0_h) << std::endl;  //50
    std::cout << computeVelocity(3.6_km, 0.02_h) << std::endl; //50
    std::cout << computeVelocity(250_cm, 2.5_ms) << std::endl; //1000
    return 0;
}