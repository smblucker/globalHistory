#ifndef BRANCHHISTORYREGISTER_H
#define	BRANCHHISTORYREGISTER_H

//Sean Blucker

#include <string>

namespace csci5814
{
    class BranchHistoryRegister
    {
    private:
        int value;
        int size;
    public:
        BranchHistoryRegister();
        int getValue();
        int getSize();
        void setValue(int setValue);
        void updateTaken();
        void updateNotTaken();
        void updateBranchHistoryRegister(std::string takenBranch);
        void updateBranchHistoryRegister2(bool takenPath);
    };
}

#endif
