#include "Exchange.h"
using namespace std;

//LEGEND Semaphore
//0 empty not in use
//1 in use by client
//2 in use by server
//3 to read by server
//4 to read by client

int Exchange::semaphore = 0;
string Exchange::message = "0";


Exchange::Exchange()
{
}