/**
 * @file main.cpp
 * @author Charles B. Owen
 *
 * Main entry point for program
 */
#include "pch.h"
#include "CanadianExperienceApp.h"
#include <iostream>
#include <cmath>
using namespace std;
wxIMPLEMENT_APP(CanadianExperienceApp);

//int main(){
//    double a = 185;
//    double b = 150;
//    double x1 = 106.41640786499875;
//    double y1 = -34.480939197273116;
//
//    double x2 = 0;
//    double y2 = -120;

//    double x1 = 195;
//    double y1 = -58;
//
//    double x2 = 0;
//    double y2 = -232;
//
//    double a = 185;
//    double b = 150;
//    double c = sqrt(pow((y2-y1), 2) + pow((x2-x1), 2));
//    double delta = atan2(-(y2-y1),x2-x1);
//    double alpha = acos((pow(b, 2)+pow(c, 2)-pow(a, 2))/(2*b*c));
//    double theta = delta-alpha;
//    double x3 = x1+b*cos(-theta);
//    double y3 = y1+b*sin(-theta);
//    double phi = atan2(y3-y2,x3-x2);
//    double PI = M_PI*2;
//
//    double rod_rotation =(((-1.0*theta)/PI)) ;
//    double lever_rotation = phi/PI;
//    double x4 = x2 + (-a*cos(phi));
//    double y4 = y2 + (-a*sin(phi));

//    double x1 = -183;
//    double y1 = -256;
//    double a = 50;
//    double x2 =-175;
//    double alpha = asin((x2-x1)/a);
//    double beta = M_PI/2-alpha;
//    double rod_rotation = beta/(2*M_PI);
//    double c = sqrt(pow((a), 2) - pow((x2-x1), 2))+y1;
//    cout<<"alpha: "<<alpha<<endl
//        <<"beta: "<<beta<<endl
//        <<"rod_rotation: "<<rod_rotation<<endl
//        <<"c: "<<(c)<<endl;

//    Variable	Value	Unit
//    α (alpha)	0.16069065295191060	radians
//    β (beta)	1.4101056738429860

//    cout<<"a: "<<a<<endl
//            <<"b: "<<b<<endl
//            <<"c: "<<c<<endl
//            <<"delta: "<<delta<<endl
//            <<"alpha: "<<alpha<<endl
//            <<"theta: "<<theta<<endl
//            <<"x3: "<<x3<<endl
//            <<"y3: "<<y3<<endl
//            <<"phi: "<<phi<<endl
//            <<"rod_rotation: "<< rod_rotation<<endl
//            <<"lever_rotation: "<< lever_rotation<<endl
//            <<"X4: "<<x4<<endl
//            <<"Y4:"<<y4<<endl;


