/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: saurabh mane 
 *
 */

#include <iostream>
#include "customer.h"

using namespace std;

//ostream& operator<< (ostream& os, customerType& c)
//{
//    os << "[#" << c.customerNumber << " ar" << c.arrivalTime << " tr"
//    		<< c.transactionTime << " srv" << c.serviceTime << "]";
//    return os;
//}


ostream& operator<< (ostream& os, customerType& c)
{
    os << "with customerNo: " << c.customerNumber << " with arrival time: " << c.arrivalTime << " Transaction time: "
    		<< c.transactionTime << " and Service Time: " << c.serviceTime  <<" Waiting time for this customer is: "<<c.serviceTime-c.arrivalTime;
      
    return os;
}


istream& operator>> (istream& is, customerType& c)
{
    is >> c.customerNumber >> c.arrivalTime >> c.transactionTime;
    return is;
}



