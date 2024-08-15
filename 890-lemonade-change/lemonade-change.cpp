class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
   int billsSize=bills.size();
    int i,count[3]={0,0,0};
    for(i=0;i<billsSize;i++){
        if(bills[i]==5)
        count[0]++;
        else if(bills[i]==10){
            if(count[0]!=0){
                count[0]--;
                count[1]++;
            }
            else
            return false;
        }
        else{
            if(count[0]>=1 && count[1]>=1)
            {
                count[0]--;
                count[1]--;
            }
            else if(count[0]>=3){
                count[0]=count[0]-3;
            }
            else
            return false;
        }
    }
    return true;
    }
};