class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26,0);
        int time = 0;

        for(char ch : tasks){
            frq[ch-'A']++ ;
        }

        priority_queue<int> pq;
        for(int i=0;i<26; i++){
            if(frq[i] > 0){
                pq.push(frq[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<= n+1;i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }

            for(int i: temp){
                if(i >0){
                    pq.push(i);
                }
            }
            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += n+1;
            }
        }
        return time;
    }
};
