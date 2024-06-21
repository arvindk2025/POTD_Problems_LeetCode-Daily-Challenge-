class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxUnsat=0,currUnsat=0;
        for(int i=0; i<minutes; i++){
            if(grumpy[i]==1){
               currUnsat+=customers[i]*grumpy[i];
            }
        }

        int i=0, j=minutes;

        maxUnsat=currUnsat;
        while(j<n){
            currUnsat+=customers[j]*grumpy[j];
            currUnsat-=customers[i]*grumpy[i];
            
            maxUnsat = max(maxUnsat, currUnsat);
            i++;j++;
        }

        int totalSat = maxUnsat;
        for(int i=0; i<n; i++){
            if(grumpy[i]==0){
                totalSat+=customers[i];
            }
        }

        return totalSat;
    }
};
