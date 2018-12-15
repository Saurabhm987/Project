/* 
 * File:   server.h
 * Author: saurabh mane
 *
 * Created on December 13, 2018, 2:45 PM
 */

#ifndef SERVER_H_
#define SERVER_H_
#include "customer.h"

class serverType
{
public:
    bool busy;	// default is false
    int ServeridleTime;
    float working_Time=0;
    int transactionTime; 	// if busy, how much more time to become free
    customerType currentCustomer;	// if busy, who is the customer
};


#endif /* SERVER_H_ */
