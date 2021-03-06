#include <iostream>
#include <csignal>
#include "crawler.hpp"
using namespace std;

Crawler _crawler;

void stop(int signum)
{
  _crawler.Stop();
}

int main()
{
  _crawler.SetOutputFolder("./documents/");
  signal(SIGINT, stop);
   
  cout << "\nTo Stop, press Ctrl-C\nStarting the crawler...\n";
  // Name of the file with the seeds, 80 threads
  _crawler.Start("seeds", 80);
  
  return 0;
}
