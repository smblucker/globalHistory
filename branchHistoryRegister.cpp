#include "branchHistoryRegister.h"

//Sean Blucker

using namespace std;

namespace csci5814
{
    branchHistoryRegister::branchHistoryRegister()
    {
        value = 0;
        size = 3;
    }

    int branchHistoryRegister::getValue()
    {
        return value;
    }

    int branchHistoryRegister::getSize()
    {
        return size;
    }

    void branchHistoryRegister::setValue(int setValue)
    {
        int mask = (1 << getSize()) - 1;
        value = setValue & mask;
    }

    void branchHistoryRegister::incrementValue()
    {
        value += 1;
    }

    void branchHistoryRegister::decrementValue()
    {
        value -= 1;
    }

    void branchHistoryRegister::shiftValueLeft()
    {
        value <<= 1;
    }

    void branchHistoryRegister::shiftValueRight()
    {
        value >>= 1;
    }

    void branchHistoryRegister::updateTaken()
    {
        shiftValueLeft();
        incrementValue();
        int mask = (1 << getSize()) - 1;
        value = value & mask;
    }

    void branchHistoryRegister::updateNotTaken()
    {
        shiftValueRight();
        decrementValue();
        int mask = (1 << getSize()) - 1;
        value = value & mask;
    }
}
