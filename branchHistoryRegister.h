#ifndef BRANCHHISTORYREGISTER_H
#define	BRANCHHISTORYREGISTER_H

//Sean Blucker


namespace csci5814
{
    class branchHistoryRegister
    {
    private:
        int value;
        int size;
    public:
        int getValue();
        int getSize();
        void setValue(int setValue);
        void incrementValue();
        void decrementValue();
        void shiftValueLeft();
        void shiftValueRight();
        void updateTaken();
        void updateNotTaken();
    };
}

#endif
