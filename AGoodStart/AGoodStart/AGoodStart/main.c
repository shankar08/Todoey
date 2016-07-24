//
//  main.c
//  AGoodStart
//
//  Created by Shankar Prajapati on 8/4/14.
//  Copyright (c) 2014 Shankar Prajapati. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void cartesianToPolar(float x, float y , double * rPtr, double *thetaPtr){
    //store the radius in the supplied address
    *rPtr = sqrt(x * x + y * y);
    
    //calculate theta
    float theta;
    if(x ==0.0){
        if (y ==0.0) {
            theta = 0.0; //technically considered undefined
        } else if (y > 0){
            theta = M_PI_2;
        }else {
            theta = - M_PI_2;
        }
    }else {
        theta = atan(y/x);
    }
    //store theta in the supplied address
    *thetaPtr = theta;
}
int main(int argc, const char * argv[])
{
    double pi = 3.14;
    double integerPart;
    double fractionPart;
    
    //Pass the addres of integerPart as an argument
    fractionPart = modf(pi, &integerPart);
    
    //Find the value stored in integerPart
    printf("intgerPart = %.0f, fractionPart = %.2f\n", integerPart,fractionPart);
    
    double x = 3.0;
    double y = 4.0;
    double radius;
    double angle;
    
    cartesianToPolar(x, y, &radius, &angle);
    
    printf("(%.2f, %.2f) becomes (%.2f radians, %.2f degree)\n", x, y, radius, angle);
    
    return 0;
}

