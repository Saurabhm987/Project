/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#include "customer.h"
#include "server.h"
using namespace std;

int main() {
    int sim_Time;
    int customer_Count=0;
    int server_Count=0;
    int current_wait_time=0;
    int max_wait_time=0;
        cout<<"Enter simulation time: " ;
	cin>>sim_Time;
	//int simulationTime = 100;
        int numberOfServers;
        float avg_wait_time=0;
        cout<<"Enter number of servers: " ;
	cin>>numberOfServers;
        
        //int numberOfServers=3;

	// create and initialize servers
	vector <serverType> servers;
	serverType s;
	s.busy=false;
	for (int i=0; i< numberOfServers; i++) servers.push_back(s);

	// create customer Queue
	queue<customerType> customerQueue;
	// read customer arrival patterns into customer Q : assuming it is sorted by arrival time
	{
		customerType cust;
		ifstream	fin;
		fin.open("C:\\Users\\manes\\Desktop\\simulation.txt");
		while (!fin.eof()){
			fin >> cust;
			customerQueue.push(cust);
		}
		fin.close();
	}

	// start the simulation loop
	for (int clock = 1; clock <= sim_Time; clock++)
	{
		// update all servers
		for (int i=0; i<numberOfServers; i++) {
			if (servers[i].busy) {
				servers[i].transactionTime -- ;
				if (servers[i].transactionTime <=0) {
					servers[i].busy=false;	// done with current customer
                                        
					cout << "At clock " << clock << " server"
                                                " " << i <<" finish " << servers[i].currentCustomer.customerNumber<< endl;
				}
			}

			// assign waiting customer (if any) to idle server
			if (servers[i].busy == false) {
                               
				if (customerQueue.empty()) continue;	// nobody in customerQ
                                // servers[i].ServeridleTime++;
				if (customerQueue.front().arrivalTime > clock) continue; // front customer has not arrived yet
                                
				// assign first ready customer to the server
				customerType readyC = customerQueue.front();
				customerQueue.pop();
                                customer_Count++;
				readyC.serviceTime = clock;  // record starting service time
				servers[i].busy = true;
                                server_Count=i+1;  //to count number of servers used in simulation
				servers[i].currentCustomer = readyC;
				servers[i].transactionTime = readyC.transactionTime;
                                 servers[i].working_Time += readyC.transactionTime;
                                avg_wait_time+=(servers[i].currentCustomer.serviceTime)-(servers[i].currentCustomer.arrivalTime);
				cout << "At clock " << clock << " server " << i <<" start " << servers[i].currentCustomer << endl;
                                
                                current_wait_time=(servers[i].currentCustomer.serviceTime)-(servers[i].currentCustomer.arrivalTime);
                                
                                if(max_wait_time<current_wait_time){
                                    max_wait_time=current_wait_time;
                                }
                               
			}
		}
	}
        cout<<"Simulation Result:  "<<endl;
        cout<<"Number of Customer being served:  "<<customer_Count<<endl;
        cout<<"Maximum wait time from all customer: "<<max_wait_time<<endl;
        cout<<"Average wait time of all customer: "<<(avg_wait_time)/customer_Count<<endl;
        cout<<"Number of servers used during simulation= "<<server_Count<<endl;
        for(int i=0;i<server_Count;i++){
        cout<<"server "<<i<<" is working for "<<servers[i].working_Time<<" unit "<<endl;
        cout<<"server "<<i<<" Efficiency= "<<(servers[i].working_Time/sim_Time)*100<<"%"<<endl;
        }    
        cout<<"############# Simulation End ##############"<<endl;
              
	cout << endl;
}





