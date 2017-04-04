#include "smithCounter.h"
#include "stats.h"
#include "branchHistoryRegister.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

//Sean Blucker

using namespace std;
using namespace csci5814;

int main()
{

	Stats smith_stats;
	SmithCounter smith_array[128];
	BranchHistoryRegister bhr;

	string branch;
	string pathIdentifier;
	int instruction;
	bool pathPrediction;
	bool takenPath;

	ifstream input("branch_trace.dat");


	while (getline(input,branch,' '))
   {
	   if(input.eof())
	   {
		   break;
	   }

	   getline(input,pathIdentifier,'\n');
	   instruction = atoi(branch.c_str());
	   int index = (((instruction/4) << 3) | (bhr.getValue() & 0x2)) & 0x1F;
	   pathPrediction = smith_array[index].getPrediction();

	   if (pathIdentifier.find('T') != std::string::npos)
	   {
		   takenPath=true;
		   smith_stats.incrementBranchTakenCount();
	   }
	   else if (pathIdentifier.find('N') != std::string::npos)
	   {
		   takenPath=false;
		   smith_stats.incrementBranchNotTakenCount();
	   }

	   if (pathPrediction && takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
		   smith_stats.incrementCorrectlyPredictedTakenBranches();

	   }
	   else if (pathPrediction && !takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
	   }
	   else if (!pathPrediction && !takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
		   smith_stats.incrementCorrectlyPredictedNotTakenBranches();
	   }
	   else if (!pathPrediction && takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
	   }

		smith_stats.incrementBranches();
	}

	input.close();

	cout << "Number of branches: " << smith_stats.getBranches() << endl;
	cout << "Number of branches taken: " << smith_stats.getBranchTakenCount() << endl;
	cout << "Number taken branches correctly predicted: " << smith_stats.getCorrectlyPredictedTakenBranches() << endl;
	cout << "Number of branches not taken: " << smith_stats.getBranchNotTakenCount() << std::endl;
	cout << "Number not taken branches correctly predicted: " << smith_stats.getCorrectlyPredictedNotTakenBranches() << endl;
	cout << "Overall rate of correct predictions: " << smith_stats.getPercent() << "%" << endl;

	return 0;
}
