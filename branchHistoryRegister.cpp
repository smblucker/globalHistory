#include "branchHistoryRegister.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

//Sean Blucker

using namespace std;

namespace csci5814
{
    BranchHistoryRegister::BranchHistoryRegister()
    {
        value = 0;
        size = 3;
    }

    int BranchHistoryRegister::getValue()
    {
        return value;
    }

    int BranchHistoryRegister::getSize()
    {
        return size;
    }

    void BranchHistoryRegister::setValue(int setValue)
    {
        int mask = (1 << getSize()) - 1;
        value = setValue & mask;
    }

    void BranchHistoryRegister::updateTaken()
    {
        value <<= 1;
        value += 1;
        int mask = (1 << getSize()) - 1;
        value = value & mask;
    }

    void BranchHistoryRegister::updateNotTaken()
    {
        value <<= 0;
        value -= 1;
        int mask = (1 << getSize()) - 1;
        value = value & mask;
    }
}
